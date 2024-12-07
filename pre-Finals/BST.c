//BST 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef struct {
	int prio;
	char letter;
}BinVal;

typedef struct node{
	BinVal bit;
	struct node* LC;
	struct node* RC;
}*BST, NodeType, *BSTPTR;

typedef struct qNode {
    BSTPTR elem;
    struct qNode *link;
} *qNodePtr;

typedef struct {
    qNodePtr head;
    qNodePtr tail;
}Queue;

void initBST(BST* B);
bool insertBST(BST* B, int prio, char let);
void deleteBST(BST* B, int prio);
void preOrder(BST B);
void postOrder(BST B);
void inOrder(BST B);
void BFS(BST B);
int main() {
	BST tree;
	initBST(&tree);
	BinVal insert[] = {{4,'D'},{1,'A'}, {2,'B'}, {3,'C'}, {5,'E'},{6,'F'}};
	int x;
	for(x = 0; x < 6; x++) {
		insertBST(&tree, insert[x].prio, insert[x].letter);
	}
	postOrder(tree);
	printf("\n");
	preOrder(tree);
	return 0;
}
void initBST(BST* B) {
	*B = NULL;
	printf("INITIALIZED\n");
}
bool insertBST(BST* B, int prio, char let) {
	BST *hop; bool ret = false;
	hop = B;
	while(*hop != NULL) {
		hop = ((*B)->bit.prio < prio) ? &(*hop)->RC : &(*hop)->LC; 
	}
	
	if(*hop == NULL) {
		*hop = (BST)calloc(1,sizeof(NodeType));
		if(*hop != NULL) {
			(*hop)->bit.letter = let;
			(*hop)->bit.prio = prio;
			ret = true;
		}else {
			ret = false;
		}
	}
	return ret;
}
void deleteBST(BST* B, int prio) {
	BST *trav, temp, *t2;
	trav = B;
	while(*trav != NULL) {
		trav = ((*trav)->bit.prio < prio) ? &(*trav)->RC : &(*trav)->LC; 
	}
	
	if(*trav != NULL) {
		temp = *trav;
		*trav = ((*trav)->LC == NULL) ? temp->LC : temp->RC;
	}
	
	
	for(t2 = &(*trav)->RC;(*t2)->LC != NULL; t2 = &(*t2)->LC) {
		temp = *t2;
		*t2 = temp->LC;
		(*trav)->bit.letter = temp->bit.letter;
		(*trav)->bit.prio = temp->bit.prio;
	}
	free(temp);
}
void preOrder(BST B) {
	if(B != NULL) {
		printf("%c ", B->bit.letter);
		preOrder(B->LC);
		preOrder(B->RC);
	}
}
void postOrder(BST B) {
	if(B != NULL) {
		preOrder(B->LC);
		preOrder(B->RC);
		printf("%c", B->bit.letter);
	}
}
void inOrder(BST B) {
	if(B != NULL) {
		preOrder(B->LC);
		preOrder(B->RC);
		printf("%c", B->bit.letter);
	}
}
void BFS(BST B) {
	Queue q;
	qNodePtr temp = malloc(sizeof(struct qNode));
	
	q.head = temp;
	q.tail = temp;
	
	while(q.head != NULL) {
		printf("%c",q.head->elem->bit.letter);
		if(q.head->elem->LC != NULL) {
			temp = (qNodePtr)malloc(sizeof(struct qNode));
			temp->elem = q.head->elem->LC;
			if(q.head != NULL) {
				q.tail->link = temp;
			}else {
				q.head = NULL;
			}
			q.tail = temp;
		}
		
		if(q.head->elem->RC != NULL) {
			temp = (qNodePtr)malloc(sizeof(struct qNode));
				temp->elem = q.head->elem->RC;	
				if(q.head != NULL) {
					q.tail->link = temp;
				}else {
					q.head = temp;
				}
			q.tail = temp;
		}
		qNodePtr toDel = q.head;
        q.head = q.head->link; 
        free(toDel);
	}
}
