#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "myStack.h"
#include "myHeader.h"

void main(){
    Stack plate;
  
	Student studs[] = {{{"Balake","XXXX","XXXXX"}, "BSCOMP", 2},{{"Bumblebe","XXXX","XXXX"},"BSROB",1},
	{{"Dee-nice","XXXX","XXXX"}, "BSCOMP",3},{{"Steve","Stan", "Rogers"}, "BSROB",1}}
    init(&plate);
	int x;
	for(x = 0; x < 5;x++) {
		visualize(plate);
		push(&plate, studs[x]);
	}
    
    Name *itStack = getStudentInProgram(plate, "BSCOMP");
    displayNames(itStack);
}
