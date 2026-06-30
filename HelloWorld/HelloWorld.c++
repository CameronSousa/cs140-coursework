#include <iostream>
#include <math.h>
using namespace std;
int main() {

	//prints "Hello World!"
	cout << "Hello world!" << endl;
	
	//prints class and Name
	cout << "CS140 Cameron Sousa" << endl;
	
	//Bonus calculation of the volume of a sphere
	//Radius of sphere
	double radius = 2.23;
	//Declaring volume
	double volume = 0;
	//Calculation of volume
	//4/3 * PI * r^3
	volume = (4.0/3.0)* M_PI * pow(radius,3.0);
	//Print volume
	cout << "A sphere with radius of " << radius << " has a volume of " << volume << endl;	
	
	return 0;
}
