#include <vector>
#include <fstream>
#include <string>

#include "..\include\particle.h"

using namespace PPE;
using namespace std;

const double pi = 3.14159265358979323846;



void makeOrthonormalBasis(Vector3D* a, Vector3D* b, Vector3D* c);

//function that saves the particles' position and velocity during motion in csv files
int saveInExcel(vector<Vector3D> vecList, vector<Vector3D> vecList_v, string name);



int main() {
	// testing
	// ...

	//simple projectile motion
	// ...

	//drag force motion
	// ...

	//EM field motion
	// ...
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
		file << vecList[i].getX() << "," << vecList[i].getY() << "," << vecList[i].getZ() << ", ," << vecList_v[i].getX() << "," << vecList_v[i].getY() << "," << vecList_v[i].getZ() << endl;
	}

	// Close the CSV file
	file.close();

	return 0;
}