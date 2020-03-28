/**************************************************/
/* array1.c - See array1.h for copyright and info */
/**************************************************/
#include <stdio.h>
#include "array1.h"

/* Make a struct function that have as members: accounts, pages, and year */
struct date{
    int accounts;
    int pages;
    int years;
};

/*************************************************************************/
/* FUNCTION NAME: read_first_year                                        */
/* DESCRIPTION: read the first year from the time interval               */
/* ARGUMENT LIST:                                                        */
/* Argument         Type    IO      Description                          */
/* ---------------  ------ -------  -------------------------------------*/
/*      int           i      I        index that shows the first year    */
/*************************************************************************/
int read_first_year(int i)
{
    do
    {
        printf(" Enter the first year: ");
        scanf(" %d", &i);

        if (i <= 2004)
           {
            printf("\nOops! We haven't got data stored earlier than 2004! Try again!");
            printf("\nBe careful...the year should be greater than 2004!\n");
           }

    }while(i <= 2004);

    return(i);
}

/*************************************************************************/
/* FUNCTION NAME: read_last_year                                         */
/* DESCRIPTION: read the last year from the time interval                */
/* ARGUMENT LIST:                                                        */
/* Argument         Type    IO      Description                          */
/* ---------------  ------ -------  -------------------------------------*/
/*      int           s      I        index that shows the last year     */
/*************************************************************************/
int read_last_year(int s)
{
    printf("\nThe final year must be strictly greater than the initial one!\n");
    do
    {
        printf(" Enter the final year: ");
        scanf(" %d", &s);

        if (s >= 2030)
            {
             printf("\nOops! We haven't reached such a far away year! Try again!");
             printf("\nBe careful...the year should be less than 2030!\n");
            }

    }while(s >= 2030);

    return(s);
}

/*************************************************************************/
/* FUNCTION NAME: read_accounts                                          */
/* DESCRIPTION: read the number of accounts that are on the network      */
/* ARGUMENT LIST:                                                        */
/* Argument         Type    IO      Description                          */
/* ---------------  ------ -------  -------------------------------------*/
/*      int           i      I        index that shows the first year    */
/*      int           s      I        index that shows the last year     */
/*      int         length   I        calculates the time interval       */
/* struct date  array[MAX]   I        stores the values of the years, 	 */
/*				      accounts and pages     	         */
/*************************************************************************/
void read_accounts(struct date array[MAX], int i, int s)
{
    int j = 0, length = 0;;

    length = s - i + 1;

    for (j = 0; j < length; j++)
    {
        printf("\nIntroduce the %d number of accounts: ", j+1);
        scanf("%d", &array[j].accounts);
    }
}

/*************************************************************************/
/* FUNCTION NAME: read_pages                                             */
/* DESCRIPTION: read the number of pages that are on the network         */
/* ARGUMENT LIST:                                                        */
/* Argument         Type    IO      Description                          */
/* ---------------  ------ -------  -------------------------------------*/
/*      int           i      I        index that shows the first year    */
/*      int           s      I        index that shows the last year     */
/*      int         length   I        calculates the time interval       */
/* struct date  array[MAX]   I        stores the values of the years, 	 */
/*				      accounts and pages     	         */
/*************************************************************************/
void read_pages(struct date array[MAX], int i, int s)
{
    int j = 0;
    int length = 0;

    length = s - i + 1;

    for (j = 0; j < length; j++)
    {
        printf("\nIntroduce the %d number of pages: ", j+1);
        scanf("%d", &array[j].pages);
    }
}

/*************************************************************************/
/* FUNCTION NAME: read_year                                              */
/* DESCRIPTION: read the number of years in the interval                 */
/* ARGUMENT LIST:                                                        */
/* Argument         Type    IO      Description                          */
/* ---------------  ------ -------  -------------------------------------*/
/*      int           i      I        index that shows the first year    */
/*      int           s      I        index that shows the last year     */
/*      int         length   I        calculates the time interval       */
/* struct date  array[MAX]   I        stores the values of the years, 	 */
/*				      accounts and pages     	         */
/*************************************************************************/
void read_year(struct date array[MAX], int i, int s)
{
    int j = 0;
    int length = 0;

    length = s - i + 1;

    for (j = 0; j < length; j++)
    {
        (*(array + j)).years = i;
        i++;
    }
}


