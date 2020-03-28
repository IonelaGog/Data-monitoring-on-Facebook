/**************************************************/
/* array4.c - See array4.h for copyright and info */
/**************************************************/
#include <stdio.h>
#include "array4.h"

struct date{
    int accounts;
    int pages;
    int years;
};

/*************************************************************************/
/* FUNCTION NAME: write_over_limit                                       */
/* DESCRIPTION: writes the years that have no. of pages and accounts over*/
/*                                    a limit                            */
/* ARGUMENT LIST:                                                        */
/* Argument         Type    IO      Description                          */
/* ---------------  ------ -------  -------------------------------------*/
/*      int     limit_pages  I        the limit of the pages		     */
/*      int  limit_accounts  I        the limit of the accounts		     */
/*      int         length   I        calculates the time interval       */
/* struct date  array[MAX]   I        stores the values of the years, 	 */
/*				                     accounts and pages     	         */
/*************************************************************************/
void write_over_limit(struct date array[MAX], int length)
{
    int i = 0;
    int limit_pages = 0, limit_accounts = 0, nr = 0;

    printf("\nEnter the value of the lower limit for accounts: ");
    scanf("%d", &limit_accounts);

    printf("\nEnter the value of the lower limit for pages: ");
    scanf("%d", &limit_pages);

    for (i = 0; i < length; i++)
    {
        if (((*(array + i)).accounts > limit_accounts) && ((*(array + i)).pages > limit_pages))
        {
            nr = nr + 1;
            if (nr == 1)
            {
              printf("\nThe years in which the number of accounts and pages were over the marks are:\n ");
              printf("|Year\n");
            }
            printf("%d. %d\n", i+1, (*(array + i)).years);
        }
    }

    if (nr == 0)
        printf("\nThere are no years with this property.");
}

/*************************************************************************/
/* FUNCTION NAME: write_below_limit                                      */
/* DESCRIPTION: writes the years that have no. of pages and accounts under*/
/*                                    a limit                            */
/* ARGUMENT LIST:                                                        */
/* Argument         Type    IO      Description                          */
/* ---------------  ------ -------  -------------------------------------*/
/*      int     limit_pages  I        the limit of the pages		     */
/*      int  limit_accounts  I        the limit of the accounts		     */
/*      int         length   I        calculates the time interval       */
/* struct date  date[MAX]    I        stores the values of the years, 	 */
/*				      accounts and pages     	                         */
/*************************************************************************/
void write_below_limit(struct date array[MAX], int length)
{
    int i = 0;
    int limit_pages = 0, limit_accounts = 0, nr = 0;

    printf("\nEnter the value of the upper limit for accounts: ");
    scanf("%d", &limit_accounts);

    printf("\nEnter the value of the upper limit for pages: ");
    scanf("%d", &limit_pages);

    for (i = 0; i < length; i++)
    {
        if (((*(array + i)).accounts < limit_accounts) && ((*(array + i)).pages < limit_pages))
        {
            nr = nr + 1;
            if (nr == 1)
            {
              printf("\nThe years in which the number of accounts and pages were below the marks are:\n");
              printf("|Year\n");
            }
            printf("%d. %d\n", i+1, (*(array + i)).years);
        }
    }

    if (nr == 0)
        printf("\nThere are no years with this property.");
}

/*************************************************************************/
/* FUNCTION NAME: write_all_even                                         */
/* DESCRIPTION: writes all even years                                    */
/* ARGUMENT LIST:                                                        */
/* Argument         Type    IO      Description                          */
/* ---------------  ------ -------  -------------------------------------*/
/*      int         length   I        calculates the time interval       */
/* struct date  array[MAX]   I        stores the values of the years, 	 */
/*				      accounts and pages     	                         */
/*************************************************************************/
void write_all_even(struct date array[MAX], int length)
{
    int i = 0;

    printf("\nAll the even years with their accounts and pages are:\n ");
    printf("|Year\t\t|Account\t\t|Page\n");

    for (i = 0; i < length; i++)
    {
        if (((*(array + i)).years % 2) == 0)
        {
            printf("%d. %d\t\t%d\t\t\t%d\n", i+1, (*(array + i)).years, (*(array + i)).accounts, (*(array + i)).pages);
        }
    }
}

/*************************************************************************/
/* FUNCTION NAME: write_all_odd                                          */
/* DESCRIPTION:  writes all odd years                                    */
/* ARGUMENT LIST:                                                        */
/* Argument         Type    IO      Description                          */
/* ---------------  ------ -------  -------------------------------------*/
/*      int         length   I        calculates the time interval       */
/* struct date  array[MAX]   I        stores the values of the years, 	 */
/*				      accounts and pages     	                         */
/*************************************************************************/
void write_all_odd(struct date array[MAX], int length)
{
    int i = 0;

    printf("\nAll the odd years with their accounts and pages are:\n ");
    printf("|Year\t\t|Account\t\t|Page\n");

    for (i = 0; i < length; i++)
    {
        if (((*(array + i)).years % 2 )!= 0)
        {
            printf("%d. %d\t\t%d\t\t\t%d\n", i+1, (*(array + i)).years, (*(array + i)).accounts, (*(array + i)).pages);
        }
    }
}

/*************************************************************************/
/* FUNCTION NAME: write_array                                            */
/* DESCRIPTION: writes the years with accounts and pages                 */
/* ARGUMENT LIST:                                                        */
/* Argument         Type    IO      Description                          */
/* ---------------  ------ -------  -------------------------------------*/
/*      int         length   I        calculates the time interval       */
/* struct date  array[MAX]   I        stores the values of the years, 	 */
/*				      accounts and pages     	                         */
/*************************************************************************/
void write_array(struct date array[MAX], int length)
{
    int j = 0;

    printf("|Year\t\t\ |Accounts\t\t |Pages\n");
    for (j = 0; j < length; j++)
    {
        printf("%d\t\t", (*(array + j)).years);
        printf("%d\t\t\t", (*(array + j)).accounts);
        printf("%d\n", (*(array + j)).pages);
    }
}




