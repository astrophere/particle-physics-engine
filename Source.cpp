#include "C:\Users\melan\source\repos\beepbopengine\core.h"
#include "C:\Users\melan\source\repos\beepbopengine\particle.h"
#include <vector>

using namespace beepbop;
using namespace std;



void makeOrthonormalBasis(Vector3D* a, Vector3D* b, Vector3D* c);



int main() {
	typedef float real;

	Vector3D steve(1, 2, -3);

	steve.print();

	Vector3D pawelekUwU(4, -5, 0);

	pawelekUwU.print();

	real artur = steve*pawelekUwU;

	cout << artur << "\n";

	Vector3D Martin = pawelekUwU % steve;

	Martin.print();

	makeOrthonormalBasis(&steve, &pawelekUwU, &Martin);

	cout << "steve: ";
	steve.print();
	cout << "pawelekUwU: ";
	pawelekUwU.print();
	cout << "Martin: ";
	Martin.print();

	cout << steve * Martin << " " << steve * pawelekUwU << " " << pawelekUwU * Martin << "\n";

	Particle Tommy(1, 1, -1);
	Tommy.printPosition();
	Tommy.printVelocity();
	Tommy.printAcceleration();
	Tommy.setInverseMass(3);
	cout << "Tommy mass: ";
	Tommy.printMass();

	Particle Carl;
	cout << "Carl: ";
	Carl.printPosition();
	Carl.setInverseMass(0.5);
	Carl.printMass();

	Carl.setAcceleration(0, 9.81, 0);

	std:vector<Vector3D> mylist;

	for (int i = 0; i < 100; i++)
	{
		Carl.integrate(0.1);
		mylist.push_back(Carl.getPosition());
		mylist[i].print();
	}
}



void makeOrthonormalBasis(Vector3D *a, Vector3D *b, Vector3D *c)
{
	a->normalise();
	(*c) = (*a) % (*b);
	if (c->squareMagnitude() == 0.0) return;
	c->normalise();
	(*b) = (*c) % (*a);
}