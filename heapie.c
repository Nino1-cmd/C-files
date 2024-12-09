//meanheap
#include<stdio.h>

#define MAX 10
void heapify(int list[],int start, int size);
void heapify2(int list[], int start, int size);
void buildMin(int list[], int size);
void heapsort(int list[], int size);
void display(int list[], int s);
int main() {
	int unsortL[] = {20,8,30,5,40,1};
	heapsort(unsortL, sizeof(unsortL)/sizeof(unsortL[0]));
	display(unsortL, 6);
	return 0;
}

void heapify(int list[],int start, int size) {
	int LC, RC;
	int small = start;

		LC = (2 * start) + 1;
		RC = (2 * start) + 2;
		
		if(LC < size && list[LC] < list[small]) {
			small = LC;
		}
		
		if(RC < size &&list[RC] < list[small] ) {
			small = RC;
		}
		
		if(small != start) {
			int temp = list[start];
			list[start] = list[small];
			list[small] = temp;
			
			heapify(list, small, size);
		}
}

void heapify2(int list[], int start, int size) {
    int smallest = start;

    int continueHeapify = 1; // Flag to continue or stop the loop
    while ((2 * smallest) + 1 < size && continueHeapify) {
        int LC = (2 * smallest) + 1;   // Left child
        int RC = (2 * smallest) + 2;   // Right child
        int tempSmallest = smallest;  // Assume current node is the smallest

        // Check left child
        if (LC < size && list[LC] < list[tempSmallest]) {
            tempSmallest = LC;
        }

        // Check right child
        if (RC < size && list[RC] < list[tempSmallest]) {
            tempSmallest = RC;
        }

        // Swap if necessary and update the smallest
        if (tempSmallest != smallest) {
            int temp = list[smallest];
            list[smallest] = list[tempSmallest];
            list[tempSmallest] = temp;
            smallest = tempSmallest; // Move to the swapped child
        } else {
            // Stop heapifying if no swaps are needed
            continueHeapify = 0; // Set flag to stop
        }
    }
}


void buildMin(int list[], int size) {
	int x;
	for(x = (size / 2) - 1; x >=0; x--) {
		heapify(list, x, size);
	}
}

void heapsort(int list[], int size) {
	buildMin(list, size);
	int x;
	for(x = size-1; x > 0; x--) {
		int t = list[0];
		list[0] = list[x];
		list[x] = t;
		heapify(list,0,size);
	}
}
void display(int list[], int s) {
	int x;
	for(x = 0; x < s; x++) {
		printf("%-5d", list[x]);
	}
}
