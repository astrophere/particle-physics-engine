#include "core.h"
#include "particle.h"
#include <vector>
#include <fstream>
#include <string>

using namespace beepbop;
using namespace std;

const double pi = 3.14159265358979323846;



void makeOrthonormalBasis(Vector3D* a, Vector3D* b, Vector3D* c);

//function that saves the particles' position and velocity during motion in csv files
int saveInExcel(vector<Vector3D> vecList, vector<Vector3D> vecList_v, string name);



int main() {
	typedef float real;


	//simple projectile motion
	real timeStep = 0.0083;

	//creating a particle, adding mass
	Particle Carl;
	Carl.setInverseMass(0.5);

	//defining acceleration and initial position (0) and velocity
	Carl.setAcceleration(0, -9.81, 0);
	Carl.setInitialVelocity(10, 10, 0);

	//initiating lists with positions and velocitis, to be exported later
	vector<Vector3D> mylist_position1;
	vector<Vector3D> mylist_velocity1;

	real height = Carl.getPosition().y; //height for finishing condition

	mylist_position1.push_back(Carl.getPosition());
	mylist_velocity1.push_back(Carl.getVelocity());


	for (int i = 0; height >= 0; i++) //loop that runs the projectile
	{
		Carl.integrate(timeStep);

		mylist_position1.push_back(Carl.getPosition());
		mylist_velocity1.push_back(Carl.getVelocity());

		height = Carl.getPosition().y;
	}

	saveInExcel(mylist_position1, mylist_velocity1, "simple_projectile");



	//drag force motion
	/*
	Particle Carl;
	Carl.setInverseMass(0.5); */

	Carl.setAcceleration(0, -9.81, 0);
	Carl.setInitialVelocity(10, 10, 0);

	vector<Vector3D> mylist_position2;
	vector<Vector3D> mylist_velocity2;

	height = Carl.getPosition().y;

	mylist_position2.push_back(Carl.getPosition());
	mylist_velocity2.push_back(Carl.getVelocity());

	Vector3D drag; //defining drag
	Vector3D Carl_vel_norm_inv = Carl.getVelocity();

	float constant = 0.5 * 1 * 0.47 * pi * 1 * 1; //air resistance constant

	for (int i = 0; height >= 0; i++)
	{
		Carl_vel_norm_inv = Carl.getVelocity(); //calculating the direction of drag force
		Carl_vel_norm_inv.normalise();
		Carl_vel_norm_inv.invert();

		drag = Vector3D();
		drag.addScaledVector(Carl_vel_norm_inv, constant * Carl.getVelocity().squareMagnitude()); //defining drag force
		Carl.addForce(drag); //adding drag to the integrator

		Carl.integrate(0.017);

		mylist_position2.push_back(Carl.getPosition());
		mylist_velocity2.push_back(Carl.getVelocity());

		height = Carl.getPosition().y;
	}

	saveInExcel(mylist_position2, mylist_velocity2, "drag");



	//EM field motion
	
	Particle Sarah(0, 0, 0);
	Sarah.setMass(1);
	Sarah.setInitialVelocity(0.1, 0.1, 0);

	//define the electric field vector in x direction
	Vector3D E(0, 0, 0); //0 for no electric field
	
	//define magnetic field in y direction
	Vector3D B(0, 1, 0);

	//define an electromagnetic force
	Vector3D EMforce;

	//define a time step
	real dt = 0.017;

	//define a charge
	real q = 1;//1.6 * pow(10,-19);

	//list for storing values
	vector<Vector3D> mylist_position3;
	vector<Vector3D> mylist_velocity3;
	mylist_position3.push_back(Sarah.getPosition());
	mylist_velocity3.push_back(Sarah.getVelocity());

	//make a loop
	for (double t = 0; t <= 15; t = t + dt)
	{
		//define a force acting on the particle
		Vector3D SarahV = Sarah.getVelocity();
		Vector3D VcrossB = SarahV % B;
		EMforce.addScaledVector(E,q);
		EMforce.addScaledVector(VcrossB,q);

		//add EM force to Sarah
		Sarah.addForce(EMforce);

		//call the integrator
		Sarah.integrate(dt);

		//save values etc
		mylist_position3.push_back(Sarah.getPosition());
		mylist_velocity3.push_back(Sarah.getVelocity());

		//clear the EM force
		EMforce = Vector3D();
	}

	saveInExcel(mylist_position3, mylist_velocity3, "magnetic");
}



void makeOrthonormalBasis(Vector3D* a, Vector3D* b, Vector3D* c)
{
	a->normalise();
	(*c) = (*a) % (*b);
	if (c->squareMagnitude() == 0.0) return;
	c->normalise();
	(*b) = (*c) % (*a);
}


int saveInExcel(vector<Vector3D> vecList, vector<Vector3D> vecList_v, string name)
{
	// Open the CSV file for writing
	ofstream file(name + ".csv");
	if (!file.is_open()) {
		cout << "Failed to open the file" << endl;
		return 1;
	}

	// Write the header to the CSV file
	file << "x,y,z" << ", ," << "vx,vy,vz" << endl;

	// Write the 3D vector's coordinates to the CSV file
	for (int i = 0; i < vecList.size()-1; i++)
	{
		file << vecList[i].x << "," << vecList[i].y << "," << vecList[i].z << ", ," << vecList_v[i].x << "," << vecList_v[i].y << "," << vecList_v[i].z << endl;
	}

	// Close the CSV file
	file.close();

	return 0;
}