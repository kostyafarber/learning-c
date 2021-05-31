#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int main(){
    
    
    int randomNumber;
    int guessCount = 5;
    int userGuess;
    time_t t;

    // initialise random number between 0-20
    srand((unsigned) time(&t));
    randomNumber = rand() % 21;

    // introduction to game
    printf("This is a guessing game.\n");
    printf("I have chosen a number between 0 and 20 which you must guess.\n");
    printf("You only have five shots. So choose wisely.\n");
    

    while (userGuess != randomNumber)
    {
        // initial messages when guessing.
        printf("You have %i tries left\n", guessCount);
        printf("Please enter a number: ");
        scanf("%i", &userGuess);

        // stop program if user doesn't guess in 5 tries.
        if (guessCount <= 1)
        {
            printf("Sorry you have ran out of guesses.\n");
            break;

        }
        else if (userGuess > randomNumber)
        {
            printf("Sorry %i is wrong. My number is less than that.\n", userGuess);
        }
        else if (userGuess < randomNumber)
        {
            printf("Sorry %i is wrong. My number is more than that.\n", userGuess);
        }
        
        else
            printf("Congratulations you guessed right!\n");

        // keep incrementing guessed down on every run
        guessCount--;
    }

    return 0;
}

