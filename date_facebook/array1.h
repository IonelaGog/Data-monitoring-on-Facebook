/***************************************************/
/* array1.h - Header file for array1 module        */
/* Copyright:  2017                                */
/* License:    Technical University of Cluj Napoca */
/* Authors:    Ionela - Maria Gog, Alex Ciobotaru  */
/* Version 12-18-2017                              */
/***************************************************/
#ifndef ARRAY1_H_INCLUDED
#define ARRAY1_H_INCLUDED

/* Headers required by the following definitions/declarations */
#include <stdlib.h>

/* Constants definition */
#define MAX 26

/*Types definitions: */
typedef struct date date;

/*Function prototypes: */
extern int read_first_year(int i);
extern int read_last_year(int s);
extern void read_accounts(struct date*, int, int);
extern void read_pages(struct date*, int, int);
extern void read_year(struct date*, int, int);

#endif // ARRAY1_H_INCLUDED
