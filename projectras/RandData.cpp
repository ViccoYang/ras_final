
#include"RandData.h"
#include"BigData.h"

void prime_random(struct slink *p,struct slink *q,int plength,int qlength)
{
	int i,k;
	time_t t; 
	p->bignum[0]=1;
	q->bignum[0]=3;
	
	 p->length=plength;
	 q->length=qlength;

 
	do
	{
		t=time(NULL);
		srand((unsigned long)t);
		for(i=1;i<p->length-1;i++)
		{
		k=rand()%10;
		p->bignum[i]=k;
		}
		k=rand()%10;
		while (k==0)
		{
			k=rand()%10;
		}
		p->bignum[p->length-1]=k;

	}while((is_prime_san(*p))!=1);
	printf("素数 p 为  : ");
	for(i=0;i<p->length;i++)
	{
		printf("%d",p->bignum[p->length-i-1]);
	}
    printf("\n\n");
	do
	{
		t=time(NULL);
		srand((unsigned long)t);
		for(i=1;i<q->length;i++)
		{
		k=rand()%10;
		q->bignum[i]=k;
		}

	}while((is_prime_san(*q))!=1);
	printf("素数 q 为 : ");
	for(i=0;i<q->length;i++)
	{
		printf("%d",q->bignum[q->length-i-1]);
	}
    printf("\n\n");
	return;
}
	
void  erand(struct slink &e,struct slink m)
{
	int i,k;
	time_t t;
	e.length=3;
	printf("随机产生一个与(p-1)*(q-1)互素的 e :");
	do
	{
		t=time(NULL);
		srand((unsigned long)t);
		for(i=0;i<e.length-1;i++)
		{
		k=rand()%10;
		e.bignum[i]=k;
	}while((k=rand()%10)==0)
		k=rand()%10;
	e.bignum[e.length-1]=k;
	}while(coprime( e, m)!=1);
	for(i=0;i<e.length;i++)
	{
		printf("%d",e.bignum[e.length-i-1]);
	}
    printf("\n\n");
	return ;
}

void rsad(struct slink e,struct slink g,struct slink *d)
{
	struct slink   r,n1,n2,k,w,t,b1,b2,temp;
	int     i;
	mov(g,&n1);
	mov(e,&n2);
	for(i=0;i<MAX;i++)
		k.bignum[i]=w.bignum[i]=r.bignum[i]=temp.bignum[i]=b1.bignum[i]=b2.bignum[i]=t.bignum[i]=0;
	k.length=w.length=r.length=temp.length=b1.length=b2.length=t.length=0;
	b1.length=0;b1.bignum[0]=0;/*/b1=0;*/
	b2.length=1;b2.bignum[0]=1;/*/b2=1;*/
	while (1)
	{
		for (i = 0; i < MAX; i++)
			k.bignum[i] = w.bignum[i] = 0;
		k.length = w.length = 0;
		divt(n1, n2, &k, &w);/*/k=n1/n2;*/
		for (i = 0; i < MAX; i++)
			temp.bignum[i] = 0;

		mul(k, n2, &temp);/*/temp=k*n2;*/
		for (i = 0; i < MAX; i++)
			r.bignum[i] = 0;
		r.length = 0;

		sub(n1, temp, &r);

		if ((r.length == 1) && (r.bignum[0] == 0))/*/r=0*/
		{
			break;
		}
		else
		{
			mov(n2, &n1);/*/n1=n2;*/
			mov(r, &n2);/*/n2=r;*/
			mov(b2, &t);/*/t=b2;*/
			for (i = 0; i < MAX; i++)
				temp.bignum[i] = 0;

			mul(k, b2, &temp);/*/b2=b1-k*b2;*/
			for (i = 0; i < MAX; i++)
				b2.bignum[i] = 0;

			sub(b1, temp, &b2);
			mov(t, &b1);
		}
	}

	for (i = 0; i < MAX; i++)
		t.bignum[i] = 0;
	t.length = 0;
	add(b2, g, &t);
	for (i = 0; i < MAX; i++)
		temp.bignum[i] = d->bignum[i] = 0;
	temp.length = d->length = 0;
	divt(t, g, &temp, d);
	printf("由以上的(p-1)*(q-1)和 e 计算得出的 d : ");
	for (i = 0; i < d->length; i++)
		printf("%d", d->bignum[d->length - i - 1]);
	printf("\n\n");
}

