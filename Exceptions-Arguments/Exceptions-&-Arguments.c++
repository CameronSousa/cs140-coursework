#include <iostream>
#include <math.h>
using namespace std;
int main(int argc, char *argv[]) {
	//initialize and declare varables
	double r = 0;
	double l = 0;
	//loop to get possible numbers
	try{
		double n = stoi(argv[1]);
		if(n <= 0) throw 1;
		//find reciprocal(n)
		r = 1.0/n;
		//find log_2(n)
		l = log2(n);
		//print results
		cout << "Number: n = " << n << endl;
		cout << "Reciprocal: 1/n = " << r << endl;
		cout << "Log_2: log2(n) = " << l << endl;	
	}
	catch (int) {
		cout << "Your number must be greater than 0" <<endl;
	}
	catch (...) {
		cout << "Input was not an INT" << endl;
	}
	return 0;
}
