#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

// PROGRAM ROCK PAPER SCISSORS
char choice;
int player;
int round = 0;
char results [100][10];

void pick();
void win();
void lose();
void tie();
int retry();
int end();
void header();

int main(){
    char *hands[] = {"Rock", "Paper", "Scissors"};

    srand(time(0)); 
    int opponent = rand() % 3;

    if(round == 0){
        header();
    }

    pick();

    printf("\nYou SHOOT: %s\n", hands[player-1]);
    printf("Your opponent SHOOT: %s\n", hands[opponent]);

    if(player-1 == opponent){
        tie();
    }
    else if((player-1 == 0 && opponent == 2) ||
            (player-1 == 1 && opponent == 0) ||
            (player-1 == 2 && opponent == 1)){
                win();
           } 
    else{
        lose();
    }
}

void header(){
    printf("=== Welcome to Rock, Paper, Scissors! ===\n");
}

void pick(){
    printf("\n1. Rock\n");
    printf("2. Paper\n");
    printf("3. Scissors\n");
    printf("SHOOT your choice: ");
    scanf("%d", &player);
    round++; 
}

void win(){
    printf("\nYou win!\n");
    strcpy(results[round-1], "Win"); 
    retry();
}
void lose(){
    printf("\nYou lose!\n");
    strcpy(results[round-1], "Lose");
    retry();
}

void tie(){
    printf("\nTie!\n");
    strcpy(results[round-1], "Tie");
    retry();
}

int retry(){
    printf("\nTry again? (y/n): ");
    scanf(" %c", &choice);
    if(choice == 'y' || choice == 'Y'){
        main();
    }
    else{
        end();
    }
}

int end(){
    printf("\nYour Results: \n");
    for(int i = 0; i < round; i++){
        printf("Round %d: %s\n", i+1, results[i]);
    }
    printf("\nThanks for playing!\n");

    return 0;
}
