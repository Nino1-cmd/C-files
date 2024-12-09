#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "queue.h"

void main(){
    NQueue names;
    initNQueue(&names);
    Name list[] = {{"Optimus", "Prime"}, {"Meowmed", "Ali"},{"AAron","Prime"},{"Dwyane", "Wade"};
    int x;
    for(x = 0; x < 4; x++) {
        enqueue(&names, list[x]);
    }

    
    displayQueue1(names);
    
    printf("\n-----FILTER NAMES FUNCTION\n");
    Name *nameList = filterNames(list, "Prime");
    displayQueue1(names);
    displayNames(nameList);

}
