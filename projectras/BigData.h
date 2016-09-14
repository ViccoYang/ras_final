#ifndef BIGDATA_H
#include<stdio.h>
#include<string.h>
#include <stdlib.h>   
#include <time.h>  
#include <math.h>
#include <malloc.h>
#define MAX 1000
struct slink
{ 
	__int8  bignum[MAX];	/*bignum[99]用来标记正负号，1正，0负*/
	int length;
    struct slink *next;
};

void  print(  slink * a );
int  cmp(struct slink a1,struct slink a2);
void mov(struct slink a,struct slink *b);
void mul(struct slink a1,struct slink a2,struct slink *c);
void add(struct slink a1,struct slink a2,struct slink *c);

void sub(struct slink a1,struct slink a2,struct slink *c);
void  divt(struct slink t,struct slink b,struct slink  *c ,struct slink *w);
void expmod(struct slink a ,struct slink p ,struct slink n,struct slink *m);
int   is_prime_san(struct slink p );
int coprime(struct slink e,struct slink s);//求两个大素数是否互质
void prime_random(struct slink *p,struct slink *q);
#endif