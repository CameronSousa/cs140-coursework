#include <iostream>
#include <math.h>
using namespace std;
int main() {

	//initialize and declare n (Number) r (reciprocal) l (log_2)
	double n = 0;
	double r = 0;
	double l = 0;
	//loop to get possible numbers
	while(1){
	
		//request a user number
		cout << "Enter a number:";
		//assign user number to n
		cin >> n;
		//check that number is possible
		if(n>0){
			//find reciprocal(n)
			r = 1.0/n;
			//find log_2(n)
			l = log2(n);
			//print results
			cout << "Number: n = " << n << endl;
			cout << "Reciprocal: 1/n = " << r << endl;
			cout << "Log_2: log2(n) = " << l << endl;
			break;	
		}
		//ask for a possible number
		else cout << "Your number must be greater than 0" <<endl;
	}
	return 0;
}
