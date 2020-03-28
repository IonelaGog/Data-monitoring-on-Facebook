/***************************************************/
/* array2.h - Header file for array2 module        */
/* Copyright:  2017                                */
/* License:    Technical University of Cluj Napoca */
/* Authors:    Ionela - Maria Gog, Alex Ciobotaru  */
/* Version 12-18-2017                              */
/***************************************************/
#ifndef ARRAY2_H_INCLUDED
#define ARRAY2_H_INCLUDED

/* Headers required by the following deffinition and declarations */
#include <stdlib.h>

/* Constants deffinitions */
#define MAX 26

/*Types definitions: */
typedef struct date date;

/*Function prototypes: */
extern void ordonare_cresc_cont(struct date*, int, struct date*);
extern void ordonare_descr_cont(struct date*, int, struct date*);
extern int cont_max(struct date*, int);
extern int cont_min(struct date*, int);
extern int lost_accounts(struct date*, int);
extern int lost_pages(struct date*, int);

#endif // ARRAY2_H_INCLUDED
