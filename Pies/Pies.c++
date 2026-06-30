#include <iostream>
#include<iomanip>
#include <math.h>
using namespace std;
//global structure for pies
struct pie{
	string name;
	double price;
	int value;
};
int main() {
	// user input
	string input;
	//name from input
	string nameIn;
	//num from input
	string numIn;
	//space location
	int space = 0;
	//num
	int inNum = 0;
	//total sales
	int sales =0;
	//total money
	double money = 0.0;
	//best pie 
	int bp = 0;
	//list array
	pie pieList[8];
	//list of names
	const string names[8] = {"lemon","pumpkin","strawberry","apple","raspberry","blueberry","pecan","rhubarb"};
	//list of prices
	const double prices[8] = {5.50,4.75,6.75,5.25,7.25,6.85,6.35,5.35};
	//function 
	void addPie(string,int,pie[]);
	//initialize array values to names values and 0
	for(int i = 0; i < 8; i ++)
	{
		pieList[i].name = names[i];
		pieList[i].price = prices[i];
		pieList[i].value = 0;
	}
	//Run till empty input
	while(1){
		
		//input
		cout << "Enter pie and number: \n";
		getline(cin,input);
		//check if length is 0
		if(input.length() > 0){
			//find the space
			space = input.find(" ");
			nameIn = input.substr(0,space);
			numIn = input.substr(space+1, input.length() - nameIn.length() - 1);
			inNum = stoi(numIn);
			//input pie and value using function
			addPie(nameIn,inNum,pieList);
		}
		else break;
	}
	//output
	for(int j = 0; j < 8; j++)
	{
		cout << "Orders for " << pieList[j].name << ":\t" ;
		cout << setw(4) << pieList[j].value << " value is $" << setw(3) << fixed<< setprecision(2) << (pieList[j].price)*(pieList[j].value) << endl;
		sales += pieList[j].value;
		money += (pieList[j].price)*(pieList[j].value);
		if(pieList[j].value > pieList[bp].value){
			bp = j;
		}
			
		
	}
	cout << "\nGrand total : " << sales << " pies for $" << fixed<< setprecision(2) << money << endl;
	cout << "Most Popular Pie: " << pieList[bp].name << endl;
	return 0;
}
void addPie(string name, int num, pie pieList[]){
	for(int i = 0; i < 8; i++){
		if(name == pieList[i].name){
			pieList[i].value += num;
			return;
		}

	}
	return;
}


