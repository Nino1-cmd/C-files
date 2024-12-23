#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "queue.h"

#define MAX 8


void initNQueue(NQueue *nq){
    nq->head = 1;
    nq->tail = 0;
}

bool isEmpty(NQueue nq){
    return (nq.head == (nq.tail + 1) % MAX) ? true : false; 
}

bool isFull(NQueue nq){
    return (nq.head == (nq.tail + 2) % MAX) ? true : false; 
}

void displayQueue1(NQueue nq){
    printf("DATA: {\n");
    while(!isEmpty(nq)){
        Name n = front(nq);
        printf("%s, %s\n", n.lName, n.fName);
        dequeue(&nq);
    }
    printf("}\n");
}

void displayQueue2(NQueue nq){
    printf("DATA: {\n");
    
    NQueue temp;
    initNQueue(&temp);
    
    int x = nq.head;
    int tempTail = temp.head;
    
    for(; x != (nq.tail + 1) % MAX; x = (x + 1) % MAX){
        printf("%s, %s\n", nq.elems[x].lName, nq.elems[x].fName);
        temp.elems[tempTail] = nq.elems[i];
        tempTail = (tempTail + 1) % MAX;
    }

    temp.tail = (tempTail - 1 + MAX) % MAX;

    x = temp.head;
    tempTail = nq.head;
    for(; x != (temp.tail + 1) % MAX; x = (x + 1) % MAX){
        nq.elems[tempTail] = temp.elems[i];
        tempTail = (tempTail + 1) % MAX;
    }
    
    printf("}\n");
}

bool enqueue(NQueue *nq, Name n){
    if(!isFull(*nq)){
        nq->tail = (nq->tail + 1) % MAX;
        nq->elems[nq->tail] = n;
        return true;
    }
    return false;
}

bool dequeue(NQueue *nq){
    if(!isEmpty(*nq)){
        nq->head = (nq->head + 1) % MAX;
        return true;
    }
    return false; 
}

Name front(NQueue nq){
    return nq.elems[nq.head]; 
}

int countElem(NQueue nq){
    int count = 0;
    while(!isEmpty(nq)){
      count++;
      dequeue(&nq);
    }
    return count;
}

/*Removes the names that matches the filterString to the lastname. 
  Returns the removed names. Use the concept of adding a sentinel
  at the end indicating the last item in list as empty strings for
  fname and lname. If there are no names that will match then the
  function should return the sentinel.*/
Name *filterNames(NQueue *nq, char *filterString){
    int x, count = 0;
    int size = countElem(*nq);
    NQueue temp;
    initNQueue(temp); 
    Name *nameList = (Name*)malloc(sizeof(Name)*size+1);
    

    for(x = nq.head; x == (nq.tail+1)% MAX;) {
            Name val = front(*nq);
            if(val.lName, fillterString) == 0){
                nameList[count++] = val; //collect the value
                 dequeue(nq);
            }else {
                enqueue(&temp, val);
                dequeue(nq);
            }
    }
    
    strcpy(nameList[count].fName,""); //adds a sentinel value
    strcpy(nameList[count++].lName,""); //adds a sentinel value
    
    nameList = (Name*)realloc(nameList,count*sizeof(Name));//updates size for sentinel values
    
    while(nq.head == (nq.tail + 1) % MAX) {
        Name p = front(temp);
        enqueue(nq, p);
        dequeue(&temp);
    }
    return nameList;
}

void displayNames(Name nameArray[]){
    printf("NAME DATA: {\n");
    for(int i = 0; strcmp(nameArray[i].fName, "") != 0; ++i){
        printf("%s, %s\n", nameArray[i].lName, nameArray[i].fName);
    }
    printf("}\n");
}

/*Insert sorted base on lastname. Remember to use the property 
  of the queue but without using the functions (enqueue, dequeue, front)*/
bool insertSorted(NQueue *nq, Name n){

if(isFull(*nq)){
    return false;
}
    NQueue temp;
    initNQueue(&temp);
    
    int x = nq->head;
    int tempTail = temp.head;
    
    for(; x != (nq->tail + 1) % MAX && strcmp(nq->elems[x].lName, n.lName) < 0; x = (x + 1) % MAX){
        temp.elems[tempTail] = nq->elems[x];
        tempTail = (tempTail + 1) % MAX;
    }
    
    temp.elems[tempTail] = n;
    tempTail = (tempTail + 1) % MAX;
    
    while (x != (nq->tail + 1) % MAX) {
        temp.elems[tempTail] = nq->elems[x];
        tempTail = (tempTail + 1) % MAX;
        x = (x + 1) % MAX;
    }

    temp.tail = (tempTail - 1 + MAX) % MAX;

    nq->head = temp.head;
    nq->tail = temp.tail;
    int y;
    for (y = temp.head; y != (temp.tail + 1) % MAX; y = (y + 1) % MAX) {
        nq->elems[y] = temp.elems[y];
    }
    return true;
}
