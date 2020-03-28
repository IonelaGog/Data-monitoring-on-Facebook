/**************************************************/
/* array3.c - See array3.h for copyright and info */
/**************************************************/
#include "array3.h"
#include <stdio.h>

/* Make a struct function that have as members: accounts, pages, and year */
struct date{
    int accounts;
    int pages;
    int years;
};

/*************************************************************************/
/* FUNCTION NAME: compute_rate                                           */
/* DESCRIPTION: computes the growing rates                               */
/* ARGUMENT LIST:                                                        */
/* Argument         Type    IO      Description                          */
/* ---------------  ------ -------  -------------------------------------*/
/*      int           i      I        index that shows the first year    */
/*      int           s      I        index that shows the last year     */
/*      int       rate[MAX]      I    stores the rates		         */
/*      int         length   I        calculates the time interval       */
/* struct date  array[MAX]   I        stores the values of the years, 	 */
/*				      accounts and pages     	         */
/*************************************************************************/
void compute_rate(struct date array[MAX], int length, float rate[MAX])
{
    int i = 0;

    for (i = 0; i < length - 1; i++)
    {
        rate[i] = (array[i+1].accounts - array[i].accounts)* 100.0 / array[i].accounts;
    }

    printf("%d", array[0].years);

    for (i = 1; i < length; i++)
        printf("%10d", array[i].years);

    printf("\n%14.2f%c", rate[0], '%');

    for (i = 1; i < length - 1;i++)
        printf("%10.2f%c ", rate[i], '%');

      printf("\n");
}

/*************************************************************************/
/* FUNCTION NAME: all_time_intervals_rates                               */
/* DESCRIPTION: stores the begining of the rates                         */
/* ARGUMENT LIST:                                                        */
/* Argument         Type    IO      Description                          */
/* ---------------  ------ -------  -------------------------------------*/
/*      int           i      I        index that shows the first year    */
/*      int           s      I        index that shows the last year     */
/*      int       rate[MAX]      I    stores the rates		         */
/*      int         length   I        calculates the time interval       */
/* struct date  array[MAX]   I        stores the values of the years, 	 */
/*				      accounts and pages     	         */
/*      int           diff1   I        computes the diference            */
/*      int           diff2   I        computes the diference            */
/*************************************************************************/
int all_time_intervals_rates(int length, float rate[MAX], int contor[MAX])
{
    int i = 0, nr = 0, poz = -1;
    int max = 0, max1 = 0;
    float diff1 = 0.0f, diff2 = 0.0f;

    for (i = 0; i < length; i++)
        contor[i] = 0;

    for (i = 0; i < length-1; i++)
    {
        diff1 = rate[i] - rate[i + 1];
        diff2 = rate[i + 1] - rate[i + 2];

        if (((diff1 < 0) && (diff2 > 0)) || ((diff1 > 0) && (diff2 < 0)))
        {
            if (nr != 0)
            {
                max = max + 1;
                nr = 1;
                contor[poz] = max;
            }

            if (nr == 0)
            {
                max = 3;
                nr = 1;
                poz = i;
                contor[poz] = max;
            }

            diff1 = 0.0;
            diff2 = 0.0;
        }
        else
            {
                nr = 0;
                diff1 = 0.0; diff2 = 0.0;

                if (max > max1)
                     max1 = max;

                max = 0;
            }
         if ((i == length-2) && (nr == 1))
         {
                max1 = max;
                contor[poz] = max;
         }
    }

      return(max1);
}

/*************************************************************************/
/* FUNCTION NAME: det_longest_time_interval_rate                         */
/* DESCRIPTION: det the longest rate interval                            */
/* ARGUMENT LIST:                                                        */
/* Argument         Type    IO      Description                          */
/* ---------------  ------ -------  -------------------------------------*/
/*      int           i      I        index that shows the first year    */
/*      int           s      I        index that shows the last year     */
/*      int       rate[MAX]      I    stores the rates		         */
/*      int         length   I        calculates the time interval       */
/* struct date  array[MAX]   I        stores the values of the years, 	 */
/*				      accounts and pages     	         */
/*      int           max1   I        stores the max value               */
/*      int    contor[MAX]   I        stores the max values              */
/*************************************************************************/
int det_longest_time_interval_rate(int max1, int length, int contor[MAX])
{
    int i = 0, poz = 0;

    for (i = 0; i < length; i++)
    {
        if (contor[i] == max1)
            poz = i;
    }
   return(poz);
}

/*************************************************************************/
/* FUNCTION NAME: write_longest_time                                     */
/* DESCRIPTION: writes the longest time interval                         */
/* ARGUMENT LIST:                                                        */
/* Argument         Type    IO      Description                          */
/* ---------------  ------ -------  -------------------------------------*/
/*      int           i      I        index that shows the first year    */
/*      int           s      I        index that shows the last year     */
/*      int         length   I        calculates the time interval       */
/* struct date  array[MAX]   I        stores the values of the years, 	 */
/*				      accounts and pages     	         */
/*      int           max1   I        stores the max value               */
/*************************************************************************/
void write_longest_time(struct date array[MAX], int max1, int poz, float rate[MAX])
{
    int i = 0;

    if (rate[poz + max1]>rate[poz+max1-1])
        max1=max1-1;

    if (max1 >= 3)
    {
       printf("\n%cThe longest time interval consists of %d elements", '*', max1);
       printf("\nThe interval is: \n");

    for (i = (poz + 1); i < (poz + max1 + 1); i++)
        printf("%d  ", array[i].years);
     printf("\n");
    }
    else
        printf("\n%cThere is no time interval bigger than 2 years.\n", '*');
}

/*************************************************************************/
/* FUNCTION NAME:  write_corresp_rates                                   */
/* DESCRIPTION: writes the longest rate interval                         */
/* ARGUMENT LIST:                                                        */
/* Argument         Type    IO      Description                          */
/* ---------------  ------ -------  -------------------------------------*/
/*      int           i      I        index that shows the first year    */
/*      int           s      I        index that shows the last year     */
/*      int       rate[MAX]      I    stores the rates		         */
/*      int         length   I        calculates the time interval       */
/* struct date  array[MAX]   I        stores the values of the years, 	 */
/*				      accounts and pages     	         */
/*      int           max1   I        stores the max value               */
/*************************************************************************/
void write_corresp_rates(float rate[MAX], int max1, int poz)
{
    int i = 0;

    if (rate[poz + max1]>rate[poz+max1-1])
        max1=max1-1;
    if (max1 >= 3)
    {
       printf("\n%cThe longest 'saw' rate sequence consists of %d elements ", '*', max1);
       printf("\nThe sequence is: ");

    for (i = poz; i < (poz + max1); i++)
        printf("%.2f%c  ", rate[i], '%');
       printf("\n");
    }
    else
        printf("\n%cThere is no sequence longer than 2 rates.\n", '*');
}
