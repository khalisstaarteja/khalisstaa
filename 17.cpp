#include <stdio.h>
#include <string.h>

// PALINDROME
// EXAMPLE = LEVEL -> LEVEL (PALINDROME), BOOK -> KOOB (NOT PALINDROME)

void REVERSE(char *str, int n, char *revStr);
void PALINDROME(char *str, char *revStr);


int main(){
    char str[100];
    char revStr[100];

    printf("Input string (all lowercase / uppercase) = ");
    scanf("%s", str);

    int n = strlen(str);

    REVERSE(str, n, revStr);

    printf("Swap = %s\n", revStr);

    PALINDROME(str, revStr);

    return 0;
}

void REVERSE(char *str, int n, char *revStr){
    int x = n - 1;
    for(int i = x; i >= 0; i--){
        *(revStr + (n - i - 1)) = *(str + i);
    }
    *(revStr + n) = '\0';
}

void PALINDROME(char *str, char *revStr){
   if(strcmp(str, revStr) == 0) printf("%s is palindrome.\n", str);
   else printf("%s is not palindrome.\n", str);
}
