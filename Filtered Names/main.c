#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "queue.h"

void main(){
    NQueue names;
    initNQueue(&names);
    Name list[] = {{"stuv", "wxyz"}, {"stuv", "abcd"},{"ijkl","mnop"}};
    int x;
    for(x = 0; x < 3; x++) {
        enqueue(&names, list[x]);
    }

    
    displayQueue1(names);
    
    printf("\n-----FILTER NAMES FUNCTION\n");
    Name *nameList = filterNames(&n1, "stuv");
    displayQueue1(names);
    displayNames(nameList);

}
