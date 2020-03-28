/**************************************************/
/* array2.c - See array2.h for copyright and info */
/**************************************************/
#include "array2.h"
#include <stdio.h>


/* Make a struct function that have as members: accounts, pages, and year */
struct date{
    int accounts;
    int pages;
    int years;
};

/*************************************************************************/
/* FUNCTION NAME: ordonare_cresc_cont                                    */
/* DESCRIPTION: order the number of accounts ascending                   */
/* ARGUMENT LIST:                                                        */
/* Argument         Type    IO      Description                          */
/* ---------------  ------ -------  -------------------------------------*/
/*      int           i      I        index that shows the first year    */
/*      int           s      I        index that shows the last year     */
/*      int           j      I        index		  	         */
/*      int      length      I        the length of the time interval    */
/* struct date      aux      I        stores the interval		 */
/*************************************************************************/
void ordonare_cresc_cont(struct date array[MAX], int length, struct date vector[MAX])
{
    int i = 0, j = 0;
    struct date aux;

    for (i = 0; i < length; i++)
        vector[i] = array[i];

    for (i = 0; i < length-1; i++)
        for (j = i+1; j < length; j++)
    {
        if (vector[i].accounts > vector[j].accounts)
        {
            aux = vector[i];
            vector[i] = vector[j];
            vector[j] = aux;
        }

    }
}

/*************************************************************************/
/* FUNCTION NAME: ordonare_descr_cont                                    */
/* DESCRIPTION: order the number of accounts downward                    */
/* ARGUMENT LIST:                                                        */
/* Argument         Type    IO      Description                          */
/* ---------------  ------ -------  -------------------------------------*/
/*      int           i      I        index that shows the first year    */
/*      int           s      I        index that shows the last year     */
/*      int           j      I        index		  	         */
/*      int      length      I        the length of the time interval    */
/* struct date      aux      I        stores the interval		 */
/*************************************************************************/
void ordonare_descr_cont(struct date array[MAX], int length, struct date vector1[MAX])
{
    int i = 0, j = 0;
    struct date aux;

    for (i = 0; i < length; i++)
        vector1[i] = array[i];

    for (i = 0; i < length-1; i++)
        for (j = i+1; j < length; j++)
    {
        if (vector1[i].accounts < vector1[j].accounts)
        {
            aux = vector1[i];
            vector1[i] = vector1[j];
            vector1[j] = aux;
        }

    }
}

/*************************************************************************/
/* FUNCTION NAME: cont_max                                               */
/* DESCRIPTION: search for the greatest account                          */
/* ARGUMENT LIST:                                                        */
/* Argument         Type    IO      Description                          */
/* ---------------  ------ -------  -------------------------------------*/
/*      int           i      I        index that shows the first year    */
/*      int           s      I        index that shows the last year     */
/*      int           max    I        finds the maximum value		 */
/*************************************************************************/
int cont_max(struct date array[MAX], int length)
{
    int max = 0, i = 0;

    max = (*(array + i)).accounts;

    for (i = 1; i < length; i++)
    {
       if ((*(array + i)).accounts > max)
            max = (*(array + i)).accounts;
    }
    return(max);
}

/*************************************************************************/
/* FUNCTION NAME: cont_min                                               */
/* DESCRIPTION: search for the smallest account                          */
/* ARGUMENT LIST:                                                        */
/* Argument         Type    IO      Description                          */
/* ---------------  ------ -------  -------------------------------------*/
/*      int           i      I        index that shows the first year    */
/*      int           s      I        index that shows the last year     */
/*      int           min    I        finds the minimum value		 */
/*************************************************************************/
int cont_min(struct date array[MAX], int length)
{
    int min = 0, i = 0;

    min = (*(array + i)).accounts;

    for (i = 1; i < length; i++)
    {
       if ((*(array + i)).accounts < min)
            min = (*(array + i)).accounts;
    }
    return(min);
}

/*************************************************************************/
/* FUNCTION NAME: lost_accounts                                          */
/* DESCRIPTION: search for those accounts that are lost                  */
/* ARGUMENT LIST:                                                        */
/* Argument         Type    IO      Description                          */
/* ---------------  ------ -------  -------------------------------------*/
/*      int           i      I        index that shows the first year    */
/*      int           s      I        index that shows the last year     */
/*      int           diff   I        computes the diference             */
/*      int           lost   I        computes the accounts              */
/*************************************************************************/
 int lost_accounts(struct date array[MAX], int length)
{
    int i = 0, j = 0;
    int lost = 0, diff = 0;

    for (i = 0; i < length-1; i++)
        for (j = i+1; j < length; j++)
    {
        if ((*(array + j)).accounts < (*(array + i)).accounts)
        {
            diff = (*(array + i)).accounts - (*(array + j)).accounts;
            lost = lost + diff;
        }
    }
    return(lost);
}

/*************************************************************************/
/* FUNCTION NAME: lost_pages                                             */
/* DESCRIPTION: search for those pages that are lost                     */
/* ARGUMENT LIST:                                                        */
/* Argument         Type    IO      Description                          */
/* ---------------  ------ -------  -------------------------------------*/
/*      int           i      I        index that shows the first year    */
/*      int           s      I        index that shows the last year     */
/*      int           diff   I        computes the difference             */
/*      int           lost   I        computes the pages                 */
/*************************************************************************/
int lost_pages(struct date array[MAX], int length)
{
    int i = 0, j = 0;
    long int lost = 0, diff = 0;


    for (i = 0; i < length-1; i++)
        for (j = i+1; j < length; j++)
    {
        if ((*(array + j)).pages < (*(array + i)).pages)
        {
            diff  = (*(array + i)).pages - (*(array + j)).pages;
            lost = lost + diff;
        }
    }
    return(lost);
}
