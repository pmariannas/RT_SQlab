#include <stdio.h>

struct person {
	char*	 name;
	int	 age;
};

typedef int (*familyDuty)(char*) ;

struct familyTree {
   	 int nMembers;
   	 struct person p[2];

   	 struct familyTree* 	next;
   	 familyDuty		func;
};

typedef struct person Person_t;
typedef struct familyTree FamilyTree_t;

int Refua(char* name)   { printf("I'm a doctor\n");		return 0; }
int Handasa(char* name) { printf("I'm an engineer\n");  return 0; }
FamilyTree_t Halakhmi = { 2, "Ilan", 28, "Gilad", 26, 0, Handasa};
FamilyTree_t Buchler  = { 2, "Rita", 38, "Brian", 30, 0, Refua };

void DoIt(FamilyTree_t* ftPtr, char* name) {
	ftPtr->func(name);
}

int main() {
	DoIt(&Halakhmi , "Ilan");
	DoIt(&Buchler  , "Rita");
	return 1;
}
