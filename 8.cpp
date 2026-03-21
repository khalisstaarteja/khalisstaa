#include <stdio.h>

// PROGRAM MAX VALUE BUT ONLY REPLACING THE VALUE INSIDE THE FILE IF MAX VALUE IS HIGHER THAN THE NUMBER INSIDE THE FILE
int num[5];
FILE *file;
int file_max;
int array_max;

void header();
void updateMax();
void readMax();

int main(){
    header();
    
    printf("Num (1): ");
    scanf("%d", &num[0]);

    array_max = num[0];

    for(int i = 1; i < 5; i++){
        printf("Num (%d): ", i + 1);
        scanf("%d", &num[i]);

        if(num[i] > array_max) array_max = num[i];
    }

    printf("\nNum: ");
    for(int i = 0; i < 5; i++){
        printf("%d ", num[i]);

        if(i == 4){
            printf("\nMax: %d\n", array_max);
            readMax();

            if(array_max > file_max){
                updateMax();
                printf("\nMaxValue.txt berhasil diupdate! (Max: %d)\n\n", array_max);
            }
        }
    } 
}

void header(){
    printf("\n--- Max Program ---\n");
}

void updateMax(){
    file = fopen("MaxValue.txt", "w");
    fprintf(file, "%d", array_max);
    fclose(file);
}

void readMax(){
    file = fopen("MaxValue.txt", "r");
    fscanf(file, "%d", &file_max);
    fclose(file);
}