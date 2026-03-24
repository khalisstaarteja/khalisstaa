#include <stdio.h>
#include <string.h>

// REVERSE STRING

void REVERSE(char *str, int n, char *revStr);

int main(){
    char str[100];
    char revStr[100];

    printf("Input string (all lowercase / uppercase) = ");
    scanf("%s", str);

    int n = strlen(str);

    REVERSE(str, n, revStr);

    printf("Reverse = %s\n", revStr);

    return 0;
}

void REVERSE(char *str, int n, char *revStr){
    int x = n - 1;
    for(int i = x; i >= 0; i--){
        *(revStr + (n - i - 1)) = *(str + i);
    }
    *(revStr + n) = '\0';
}

