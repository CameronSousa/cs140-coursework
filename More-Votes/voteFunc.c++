#include <iostream>
#include <iomanip>
#include <math.h>
#include "voting.h"
using namespace std;
vote* sortList(vote* head){
	bool swapped;
	do{
		swapped = false;
		vote* current = head;
		vote* prev = NULL;
		while(current != NULL && current->next != NULL){
			if(current->votes < current->next->votes){
				vote* temp = current->next;
				current->next = temp->next;
				temp->next = current;
				if(prev == NULL){
					head = temp;
				}
				else{
					prev->next = temp;
				}
				swapped = true;
				prev = temp;
			}
			else{
				prev = current;
				current = current->next;
			}
		}
	} while(swapped);
	
	return head;
}
//function to create votes and initialize their values
void createVote(const string& candidateName, vote** head){
	vote* current = *head;
	vote* prev = NULL;
	vote* newVote = new vote;
	newVote->name = candidateName;
	newVote->votes = 1;
	if(current == NULL){
		newVote->next = NULL;
		*head = newVote;
		return;
	}
	if(current->name > candidateName){
		newVote->next = *head;
		*head = newVote;
		return;
	}
	while(current){
		if(current->name > candidateName)
		{
			prev->next = newVote;
			newVote->next = current;
			return;
		}	
		prev = current;
		current = current->next;
	}
	prev->next = newVote;
	newVote->next = current;
	return;
	
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

