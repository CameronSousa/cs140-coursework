#include <iostream>
#include<iomanip>
#include <math.h>
using namespace std;
//Structure for votes
struct vote{
	string name;
	int votes;
	vote* next;
};
//function to create votes and initialize their values
vote* createVote(const string& candidateName){
	vote* newVote = new vote;
	newVote->name = candidateName;
	newVote->votes = 1;
	newVote->next = NULL;
	return newVote;
}
//function to find the address in memory of votes that match the input name
vote* findCandidate(vote* head, const string& name){
	vote* current = head;
	//while there are more votes in the list
	while(current != NULL){
		if(current->name == name){
			return current;
		}
		current = current->next;
	}
	return NULL;
}
//function to print the linked list and other values
void printList(vote* head, int totalVotes){
	vote* current = head;
	int count = 0;
	//find the ammount total amounts of Names voted for
	while(current != NULL){
		count++;
		current = current->next;
	}
	cout << "List of candidates has " << count << " names" << endl;
	//print each name and how many votes they got and what percentage of the total it was
	current = head;
	while(current != NULL){
		int percentage = (int)(((double)(current->votes)/totalVotes) * 100 + 0.5);
		cout << setw(20) << current->name << "\t"  << setw(3) << current->votes << setw(4) << " " << percentage << "%" << endl;
		current = current->next;
	}
	cout<< "Total votes cast: " << totalVotes << endl;
	current = head;
	return;
}
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
				vote* newVote = createVote(input);
				newVote->next = head;
				head = newVote;
			}
		}		
	}
	//print the candidates
	printList(head, totalVotes);
	return 0;
}
