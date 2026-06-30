#include <iostream>
#include <math.h>
using namespace std;
int main() {
	//Variables
	//is the long even
	bool isEven(long);
	//is the long a power of 2
	bool isPow2(long);
	//is the long prime
	bool isPrime(long);
	//string input
	string in = ""; 
	//string output
	string out = "";
	//long user
	long L = 0;
	//long random
	long R = 0;
	
	//while loop until user inputs blank string
	while(1){	
		cout << "Enter a Number: ";
		getline(cin,in);
		//break if string length is 0
		if(in.length() == 0)break;
		L = stol(in);
		//Build and print the output
		out = in + " is ";
		out += isEven(L) ? "even, ":"odd, ";
		out += isPow2(L) ? "a power of 2, ":"not a power of 2, ";
		out += isPrime(L) ? "and is prime.":"and is not prime.\n";
		cout << out << endl;
	}
	//seed random
	srandom(time(0));
	//for 10 random values run checks
	for(int i = 0; i < 10;i++){
		in = "";
		//set random value
		R = random();
		//Build and print output
		out = to_string(R) + " is ";
		out += isEven(R) ? "even, ":"odd, ";
		out += isPow2(R) ? "a power of 2, ":"not a power of 2, ";
		out += isPrime(R) ? "and is prime.":"and is not prime.\n";
		cout << out << endl;
	}
	
	return 0;
}
// check if long is even by modulo 2
bool isEven(long L1){
	return (L1 %2 == 0);
}
//check if long is a power of 2 using bitwise and
bool isPow2(long n){
	if(n<=0){
	return false;
	}
	return (n & (n - 1)) == 0;
}
//check if long is prime by moding until square root of number	
bool isPrime(long L2){
	double x = ceil(sqrt(L2));
	for (int i = 2; i < x; i++) if (L2 % i == 0) return 0;
    	return 1;
}


	
