#include <iostream>
using namespace std;
struct vote{
	string name;
	int votes;
	vote* next;
	
};
void printList(vote*,int);
vote* findCandidate(vote*, const string&);
void createVote(const string&, vote**);
vote* sortList(vote*);
