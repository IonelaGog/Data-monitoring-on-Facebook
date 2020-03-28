/***************************************************/
/* array3.h - Header file for array3 module        */
/* Copyright:  2017                                */
/* License:    Technical University of Cluj Napoca */
/* Authors:    Ionela - Maria Gog, Alex Ciobotaru  */
/* Version 12-18-2017                              */
/***************************************************/
#ifndef ARRAY3_H_INCLUDED
#define ARRAY3_H_INCLUDED

/* Headers required by the following deffinition and declarations */
#include <stdlib.h>

/* Constants deffinitions */
#define MAX 26

/*Types definitions: */
typedef struct date date;

/*Function prototypes: */
extern void compute_rate(struct date*, int, float*);
extern int all_time_intervals_rates(int, float*, int*);
extern int det_longest_time_interval_rate(int, int, int*);
extern void write_longest_time(struct date*, int, int, float*);
extern void write_corresp_rates(float*, int, int);

#endif // ARRAY3_H_INCLUDED
