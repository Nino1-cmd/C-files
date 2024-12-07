#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[16];
    int age;
} Person;

void getFile(Person P);
void printFile();

int main() {
    Person list[] = {
        {"Nino", 25}, {"James", 30}, {"Daryll", 19}, {"Anton", 45}, {"Cyborg", 20}};
    int x;

    for (x = 0; x < sizeof(list) / sizeof(list[0]); x++) {
        getFile(list[x]);
    }

    printf("\nData writing completed.\n\n");
    printFile();

    return 0;
}

void getFile(Person P) {
    FILE *fp;

    fp = fopen("ValuedNames.dat", "ab");
    if (fp == NULL) {
        printf("Failed to open the file.\n");
    } else {
        fwrite(&P, sizeof(Person), 1, fp);
        printf("Successfully wrote: Name = %s, Age = %d\n", P.name, P.age);
        fclose(fp);
    }
}

void printFile() {
    FILE *fp;
    Person P;

    fp = fopen("ValuedNames.dat", "rb");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    printf("Contents of the file:\n");
    while (fread(&P, sizeof(Person), 1, fp)) {
        if (P.age > 0 && P.age < 150) {  // Validate age range
            printf("Name: %s, Age: %d\n", P.name, P.age);
        } else {
            printf("Invalid data encountered.\n");
        }
    }

    fclose(fp);
}
