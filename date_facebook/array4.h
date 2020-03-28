/***************************************************/
/* array4.h - Header file for array4 module        */
/* Copyright:  2017                                */
/* License:    Technical University of Cluj Napoca */
/* Authors:    Ionela - Maria Gog, Alex Ciobotaru  */
/* Version 12-18-2017                              */
/***************************************************/
#ifndef ARRAY4_H_INCLUDED
#define ARRAY4_H_INCLUDED

/* Headers required by the following deffinition and declarations */
#include <stdlib.h>

/* Constants deffinitions */
#define MAX 26

/*Types definitions: */
typedef struct date date;

/*Function prototypes: */
extern void write_over_limit(struct date*, int);
extern void write_below_limit(struct date*, int);
extern void write_all_odd(struct date*, int);
extern void write_all_even(struct date*, int);
extern void write_array(struct date*, int);

#endif // ARRAY4_H_INCLUDED
