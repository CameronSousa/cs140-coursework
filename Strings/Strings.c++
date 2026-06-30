#include <iostream>
#include <math.h>
using namespace std;
int main() {
	//Initializing and declaring variables
	//input
	string in = "";
	//list of vars
	string var = "aeiou";
	//length
	int len = 0;
	//upper case
	int upr = 0;
	//lower case
	int low = 0;
	//numbers
	int num = 0;
	//vowels
	int vow = 0;
	//punctuation
	int pun = 0;
	//temp char to compare
	char c = ' ';
	
	//get user String
	cout << "Enter String:" << endl;
	getline(cin,in);
	//reassign string length
	len = in.length();
	//for each character in String in
	for(int i = 0; i < len;i++){
		//asign temp character
		c = in.at(i);
		//check for alphabetic
		if(isalpha(c)){
			//check for upper and lower case
			if(isupper(c)) upr++;
			else low++;
			//check for all vowels
			for(int j = 0; j < var.length();j++) vow += (var.at(j) == tolower(c));
		}
		//check for digit
		else if(isdigit(c)) num++;
		//check for puntuation
		else if(ispunct(c)) pun++;
	}
	
	//print out all output variables
	cout << "String length: " << len << endl;
	cout << "Alphabetics: " << upr + low << "(" << upr << "  upper case, " << low << " lower case)" << endl;
	cout << "Numerics: " << num << endl;
	cout << "Vowels: " << vow << endl;
	cout << "Punctuation: " << pun << endl;
				
	return 0;
}
