#include "diceclass.h"

diceroll::diceroll() 
{
	//seeding random using time
	srand(time(0));
}
//function to return one dice roll
int diceroll::onedice() 
{
	return (rand() % 6) + 1;
}
//function to print out two roll values and return their total
int diceroll::twodice() 
{
	//first roll
	int roll1 = onedice();
	//second roll
	int roll2 = onedice();
	cout << "Rolled: " << roll1 << " and " << roll2 << endl;
	return roll1 + roll2;
}

