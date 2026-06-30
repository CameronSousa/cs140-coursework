#include "diceclass.h"
//function to return total wins as a percentage
double sumOfWins(int arr[])
{
	//game sum
	int gSum = 0;
	//itterate through each array position
	for (int i = 1; i <= 21; i++)
	{
		gSum += arr[i];
	}
	return (double)gSum/10.0;
}
//funcccction to print each value of the array and its position
void printArray(int arr[])
{
	//sum of wins or losses
	int sumWL = 0;
	//itterate through each position of an array
	for (int i = 1; i <=21; i++)
	{
		sumWL += arr[i];
		cout << "wins at: " << i << " " << arr[i] << endl;
	}
	cout << "Total: " << sumWL << endl;
	return;
} 
int main()
{
//Cameron Sousa
//Craps
	//create diceroll instance
	diceroll dice;
	//win array
	int win[21] = {0};
	//lose array
	int lose[21] = {0};
	//total games played
	int numGames = 1000;	
	//sum of dice rolls
	int sum = 0;
	//play 1000 games
	for (int i = 1; i <= numGames; i++)
	{
		//number of rolls int current game
		int roll = 1;
		//win/lose condition
		int gameOver = 0;
		//desired value after first roll to win
		int points = 0;
		sum = dice.twodice();
		//for 7 and 11 win, 2 3 and 12 lose , all else cont. to more rolls
		switch(sum)
		{
			case 7:
				win[roll]++;
				gameOver = 1;
				break;
			case 11:
				win[roll]++;
				gameOver = 1;
				break;
			case 2:
				lose[roll]++;
				gameOver = 1;
				break;
			case 3:
				lose[roll]++;
				gameOver = 1;
				break;
			case 12:
				lose[roll]++;
				gameOver = 1;
				break;
			default:
				points = sum;
				break;
		}
		//while game is not over
		while(!gameOver)
		{
			// if total rolls is below 21 
			if (roll < 21)
			{
				++roll;
				sum = dice.twodice();
				//if the sum of dice is equal to the desired points player wins
				if (sum == points)
				{
					win[roll]++;
					gameOver = 1;
				}
				//if the sum of dice is equal to the 7 player lose
				if (sum == 7)
				{
					lose[roll]++;
					gameOver = 1;
				}
			}
			//if rolls is above 21
			else
			{
				sum = dice.twodice();
				//if the sum of dice is equal to the desired points player wins
				if (sum == points)
				{
					win[roll]++;
					gameOver = 1;
				}
				//if the sum of dice is equal to the 7 player lose
				if (sum == 7)
				{
					lose[roll]++;
					gameOver = 1;
				}
			}
			
		}
	}
	cout << "Win Percentage: " << sumOfWins(win) << "%" << endl;
	cout << "Win Values: " << endl;
	printArray(win);
	cout << "Lose Values: " << endl;
	printArray(lose);
	return 0;
}
