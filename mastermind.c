/*************************************************************
* Project:   The Mastermind Game                             *
* Name:      Sabrina Aravena                                 *
**************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main() {
  char colors[6] = "roygbp";
  char choice[5]; /* user input */
  char guess[6];  /* user guess */
  char solution[4];  /* solution */
  char no = 'n';
  char yes = 'y';
  int turns = 1;
  int pegs = 4;

  /* Introduction */
  printf("Welcome to Mastermind!\n\n");
  /* loops until user decides to not play again */
  while(1) {
    printf("Would you like to play? ");
    fgets(choice, sizeof(choice), stdin); /* take in user input */

    /* Determines if player wants to play game */
    if (choice[0] == yes) {
      int idx;

      /* Initializes random number generator */
      srand((unsigned int)time(NULL));
      /* Populates the answer array with random numbers between 0 and 5 */
      for (idx = 0; idx < pegs; idx++) {
        solution[idx] = colors[rand() % 6];
        printf("%c", solution[idx]);   //TEST TEST TEST TEST
      } /* end for */

      /* Game Play */
      while(turns <= 10) {
        int check[4] = {0, 0, 0, 0};
        int i;
        int j;
        int k;
        int count_place = 0;
        int count_color = 0;
        /* takes in user guess */
        printf("\n\n\nEnter guess number %d: ", turns);
        fgets(guess, sizeof(guess), stdin);

        /* Compares user guess to solution */
        for (i = 0; i < pegs; i++) {
          /* Determines the number of colors in correct place */
          if (guess[i] == solution[i] && check[i] == 0) {
            check[i] = 1;
            count_place++;
          }
        } /* end for */
        /* Determines the correct colors in the wrong place */
        for (j = 0; j < pegs; j++) {
          for (k = 0; k < pegs; k++) {
            if (guess[j] == solution[k] && check[k] == 0) {
              check[k] = 1;
              count_color++;
            }
          } /* end for */
        } /* end for */

        /* Displays the score for the user */
        printf("\nColors in the correct place: %d\n", count_place);
        printf("\nColors correct but in wrong position: %d\n", count_color);

        /* Determines if user won */
        if (count_place == 4) {
          printf("\nYou win! Congratulations!!\n");
          printf("---------------------------------------------\n\n\n");
          break; /* end game */
        }

        turns++; /* new turn */
      } /* end while */

    } else {
      /* ends game */
      printf("Thanks for playing!");
      break;
    }
  } /* end while */
  printf("\n\n\n");
  return 0;
} /* end main */
