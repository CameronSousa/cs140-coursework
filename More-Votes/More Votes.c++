#include <iostream>
#include <iomanip>
#include <math.h>
#include "voting.h"
using namespace std;

int main() {
	//start of the linked list
	vote* head = NULL;
	// user input
	string input;
	//total votes 
	int totalVotes = 0;
	//Run till empty input
	while(1){
		//input
		cout << "Enter Name: \n";
		getline(cin,input);
		//check if length is 0
		if(input.length()  == 0) break;
		//add the input vote to one of the candidates in the linked list or create a new candidate
		else{
			totalVotes++;
			vote* candidate = findCandidate(head, input);
			if(candidate){
				candidate->votes++;
			}
			else{
				createVote(input,&head);
			}
		}		
	}
	//print the candidates
	printList(head, totalVotes);
	vote* newHead = sortList(head);
	printList(newHead, totalVotes);
	return 0;
}
