/***************************************************/
/* Monitoring data on Facebook                   */
/* Copyright:  2017                                */
/* License:    Technical University of Cluj Napoca */
/* Authors:    Ionela - Maria Gog, Alex Ciobotaru  */
/* Version 12-18-2017                              */
/***************************************************/

/* Include standard libraries */
#include <stdio.h>
#include <stdlib.h>

/* Include modules header that are directly invoked */
#include "array1.h"
#include "array2.h"
#include "array3.h"
#include "array4.h"

int main()
{
/* Declare the variables that are used in the program */
    struct date *array[MAX], *vector[MAX], *vector1[MAX];;
    float *rate[MAX];
    int *contor[MAX];
    char letter = '\0';
    int index = 0;
    int i = 0, s = 0, length = 0, max1 = 0, poz = 0;

    i = read_first_year(i);
    s = read_last_year(s);
    length = s - i + 1;

    if (i < s)
    {
/* Calls the functions that reads the number of accounts, pages and years from the network */
    read_accounts(array, i, s);
    read_pages(array, i, s);
    read_year(array, i, s);

    printf("\nWe'd like to show you something:\n");

    printf("The growing rates are computed with respect to the previous year. So, you'll see one less rate than the number of years.\n");
    printf("These are the growing rates of the years you chose:\n");
    compute_rate(array, length, rate);

/* Computes all the time intervals */
    max1 = all_time_intervals_rates(length - 1, rate, contor);

/* Determines the maximum of the interval */
    poz = det_longest_time_interval_rate(max1, length, contor);

/* Writes the longest time interval */
    write_longest_time(array, max1, poz, rate);

/* Writes the coresponding rates */
    write_corresp_rates(rate, max1, poz);

/* Make two lists from which the user can choose his/her option */
    printf("\nThis is a list at your disposal that you can choose from:\n");
    printf("%d.Press %c to order the data increasingly depending on the accounts and see the informations.\n", 1, 'A');
    printf("%d.Press %c to order the data decreasingly depending on the accounts and see the informations.\n", 2, 'B');
    printf("%d.Press %c to see the total number of accounts that have been lost over the years.\n", 3, 'C');
    printf("%d.Press %c to see the total number of pages that have been lost over the years.\n", 4, 'D');
    printf("%d.Press %c to see the maximum number of accounts that has been achieved in all the years.\n", 5, 'E');
    printf("%d.Press %c to see the minimum number of accounts that has been achieved in all the years.\n", 6, 'F');
    printf("%d.Press %c to quit the operation.\n", 7, 'G');

    do
    {
        printf("\nEnter the character you want: ");
        scanf(" %c", &letter);

    switch(letter)
    {
    case 'A':
        {printf("\nYou have chosen to order the data increasingly depending on the accounts: \n");

        ordonare_cresc_cont(array, length, vector);
        write_array(vector, length);

        break;
        }

    case 'B':
        {printf("\nYou have chosen to order the data decreasingly depending on the accounts: \n");

         ordonare_descr_cont(array, length, vector1);
         write_array(vector1, length);

        break;
        }

    case 'C':
        printf("\nThe total number of lost accounts is: %d\n", lost_accounts(array, length));
        break;

    case 'D':
        printf("\nThe total number of lost pages is: %d\n", lost_pages(array, length));
        break;

    case 'E':
        printf("\nThe maximum value of an account is: %d\n", cont_max(array, length));
        break;

    case 'F':
        printf("\nThe minimum value of an account is: %d\n", cont_min(array, length));
        break;

    case 'G':
        printf("Quit the operation.");
        break;

    }

    if ((letter < 'A') || (letter > 'F'))
        printf("It must be from A to F! Don't give up!\n");

    }while(letter != 'G');

      printf("\nNow, let us give you a range to choose from. Your options are: \n");
      printf("%d.Press %d to see the years that have the accounts and pages under a limit you type in.\n", 1, 1);
      printf("%d.Press %d to see the years that have the accounts and pages over a limit you type in.\n", 2, 2);
      printf("%d.Press %d to see all the odd years along with the number of accounts and pages.\n", 3, 3);
      printf("%d.Press %d to see all the even years along with the number of accounts and pages.\n", 4, 4);
      printf("%d.Press %d to quit the operation.\n", 5, 5);

    do
    {
        printf("\nEnter the index you'd like to choose: ");
        scanf(" %d", &index);

    switch(index)
    {
    case 1:{
        printf("\nYou have chosen to see all the years in which the accounts and pages were under the limits: \n");
        write_below_limit(array, length);

        break;
    }

    case 2:
        {
        printf("\nYou have chosen to see all the years in which the accounts and pages were over the limits: \n");
        write_over_limit(array, length);

        break;
        }

    case 3:
        {
        printf("\nYou have chosen to see the odd years alongside their accounts and pages: \n");
        write_all_odd(array, length);

        break;
        }

    case 4:{
        printf("You have chosen to see the even years alongside their accounts and pages: \n");
        write_all_even(array, length);

        break;
    }

    case 5:
        printf("Quit the operation.\n");
        break;

    }

    if ((index < 1) || (index > 5))
        printf("It must be between 1 and 4! Try again!\n");

    }while(index != 5);


    printf("\nFacebook wishes you a nice day! ");

    }
    else printf("We can't follow the instructions. Please try again later.");

    return 0;
}
