#ifndef RandData_H
#include <stdlib.h>   
#include <time.h>  
#include <math.h>
#include <malloc.h>

void prime_random(struct slink *p,struct slink *q,int qlength,int plength);
void  erand(struct slink &e,struct slink m);
void rsad(struct slink e,struct slink g,struct slink *d);
#endif