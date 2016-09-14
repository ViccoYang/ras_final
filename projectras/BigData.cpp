
#include"BigData.h"
/*/--------------------------------------自己建立的大数运算库-------------------------------------*/

void  print(  slink * a )
   {
	   int i;
	   for(i=0;i<a->length;i++)
		   printf("%d",a->bignum[a->length-i-1]);
	   printf("\n\n");
	   return;
   }


int  cmp(struct slink a1,struct slink a2)
{   int l1, l2;
	int i;
	l1=a1.length;
	l2=a2.length;
	if (l1>l2)
		return 1;
    if (l1<l2)
		return -1;
    for(i=(l1-1);i>=0;i--)
	{
		if (a1.bignum[i]>a2.bignum[i])
		   return 1 ;

		if (a1.bignum[i]<a2.bignum[i])
		   return -1;
	}
    return 0;
}

void mov(struct slink a,struct slink *b)
{
	int j;
	b->length=a.length;
	for(j=0;j<MAX;j++)
		b->bignum[j]=a.bignum[j];
		
	return ;
}


void mul(struct slink a1,struct slink a2,struct slink *c)
{
	int i,j,w;
	__int8 x,y,z;
	int l1, l2;
	l1=a1.length;
	l2=a2.length;
	if (a1.bignum[MAX-1]=='-'&& a2.bignum[MAX-1]=='-')
		c->bignum[MAX-1]=0;
	else if (a1.bignum[MAX-1]=='-')
			c->bignum[MAX-1]='-';
	else if (a2.bignum[MAX-1]=='-')
			c->bignum[MAX-1]='-';
	for(i=0;i<l1;i++)
	{
	  for(j=0;j<l2;j++)
	  {
		 x=a1.bignum[i]*a2.bignum[j];
		 y=x/10;
		 z=x%10;
		 w=i+j;
		 c->bignum[w]=c->bignum[w]+z;
		 c->bignum[w+1]=c->bignum[w+1]+y+c->bignum[w]/10;
		 c->bignum[w]=c->bignum[w]%10;
	  }
	}
	w=l1+l2;
	if(c->bignum[w-1]==0)	w=w-1;
	c->length=w;
	return;
} 

void add(struct slink a1,struct slink a2,struct slink *c)
{

	int i,l1,l2,len;
	struct slink temp;
	int k=0;
	l1=a1.length;
	l2=a2.length;
	if((a1.bignum[MAX-1]=='-')&&(a2.bignum[MAX-1]=='-'))
	{
		c->bignum[MAX-1]='-';
	}
	else if (a1.bignum[MAX-1]=='-')
	{
		mov(a1,&temp);
		//temp.length=0;
		temp.bignum[MAX - 1] = 0;
		sub(a2,temp,c);
		int test=0;
		test++;
		return;
	}
	else if (a2.bignum[MAX-1]=='-')
	{
		mov(a2,&temp);
		//temp.length=0;
		temp.bignum[MAX - 1] = 0;
		sub(a1,temp,c);
		return;
	}

	if(l1<l2)
		len=l1;
	else 
		len=l2;
	for(i=0;i<len;i++)
	{
		c->bignum[i]=(a1.bignum[i]+a2.bignum[i]+k)%10;
		k=(a1.bignum[i]+a2.bignum[i]+k)/10;
	}
	if(l1>len)
	{
		 for(i=len;i<l1;i++)
		 {
			 c->bignum[i]=(a1.bignum[i]+k)%10;
			 k=(a1.bignum[i]+k)/10;   
		 }
		 if(k!=0)
		 {
			 c->bignum[l1]=k;
			len=l1+1;
		 }
		 else len=l1;
	}
	else
	{
		 for(i=len;i<l2;i++)
		 {
			 c->bignum[i]=(a2.bignum[i]+k)%10;
			 k=(a2.bignum[i]+k)/10;   
		 }
		 if(k!=0)
		 {
			 c->bignum[l2]=k;
			 len=l2+1;
		 }
		 else len=l2;
	 }
	c->length=len;
	 return;
} 


void sub(struct slink a1,struct slink a2,struct slink *c)
{
	int i,l1,l2,len;
	struct slink t1,t2;
	int k=0;
	l1=a1.length;
	l2=a2.length;
	if ((a1.bignum[MAX-1]=='-') && (a2.bignum[MAX-1]=='-'))
	{
		mov(a1,&t1);
			mov(a2,&t2);
		t1.bignum[MAX-1]=0;
		t2.bignum[MAX-1]=0;
		sub(t2,t1,c);
		return;
	}
	else if( a2.bignum[MAX-1]=='-')
	{
		mov(a2,&t2);
		t2.bignum[MAX-1]=0;
		add(a1,t2,c);
		return;
	}
	else if (a1.bignum[MAX-1]=='-')
	{
		mov(a2,&t2);
		t2.bignum[MAX-1]='-';
		add(a1,t2,c);
		return;
	}

	if(cmp(a1,a2)==1)
	{	 
		len=l2;
		for(i=0;i<len;i++)
		{
			if ((a1.bignum[i]-k-a2.bignum[i])<0)
			{
				c->bignum[i]=(a1.bignum[i]-a2.bignum[i]-k+10)%10;
				 k=1;
			}
			else 
			{
				c->bignum[i]=(a1.bignum[i]-a2.bignum[i]-k)%10;
				 k=0;
			}
		}

		for(i=len;i<l1;i++)
		{
			if ((a1.bignum[i]-k)<0)
			{
				c->bignum[i]=(a1.bignum[i]-k+10)%10;
				 k=1;
			}
			else 
			{
				c->bignum[i]=(a1.bignum[i]-k)%10;
				 k=0;
			} 
		}
		if(c->bignum[l1-1]==0)/*使得数组C中的前面所以0字符不显示了，如1000-20=0980--->显示为980了*/
		{
			len=l1-1;
			i=2;
			while (c->bignum[l1-i]==0)/*111456-111450=00006，消除0后变成了6；*/
			{
				 len=l1-i;
				 i++;
			 }
		}
		else 
		{
			  len=l1;
		}
	}
	else if(cmp(a1,a2)==(-1))
	{
		c->bignum[MAX-1]='-';
		len=l1;
		for(i=0;i<len;i++)
		{
			if ((a2.bignum[i]-k-a1.bignum[i])<0)
			{
				c->bignum[i]=(a2.bignum[i]-a1.bignum[i]-k+10)%10;
				k=1;
			}
			else 
			{
				c->bignum[i]=(a2.bignum[i]-a1.bignum[i]-k)%10;
				k=0;
			}
		}
		for(i=len;i<l2;i++)
		{
			if ((a2.bignum[i]-k)<0){
				c->bignum[i]=(a2.bignum[i]-k+10)%10;
				 k=1;
			}
			else{
				c->bignum[i]=(a2.bignum[i]-k)%10;
				 k=0;
			}   
		 }
		if(c->bignum[l2-1]==0)
		 {  
			   len=l2-1;
			   i=2;
			   while (c->bignum[l1-i]==0){
					len=l1-i;
					i++;
			   }

		 }
		 else len=l2; 
	}
	else if(cmp(a1,a2)==0)
	   {
		   len=1;
		   c->bignum[len-1]=0;
	   }
	c->length=len;
	return;
}

void  divt(struct slink t,struct slink b,struct slink  *c ,struct slink *w)/*//试商法//调用以后w为a mod b, C为a  div b;*/
{

	int a1,b1,i,j,m;/*w用于暂时保存数据*/
	struct slink d,e,f,g,a;
	
	mov(t,&a);
		for(i=0;i<MAX;i++)
			e.bignum[i]=0;
	for(i=0;i<MAX;i++)
		d.bignum[i]=0;
	for(i=0;i<MAX;i++) 
		g.bignum[i]=0;
	a1=a.length;
	b1=b.length;
	if (cmp(a,b)==(-1))
	{
		c->bignum[0]=0;
		c->length=1;
		mov(t,w);
		return;
	}
	else if (cmp(a,b)==0)
	{
		c->bignum[0]=1;
		c->length=1;
		w->bignum[0]=0;
		w->length=1;
		return;
	}
		m=a1-b1;
    for(i=m;i>=0;i--)/*341245/3=341245-300000*1--->41245-30000*1--->11245-3000*3--->2245-300*7--->145-30*4=25--->25-3*8=1*/
	{
        for(j=0;j<MAX;j++)
		    d.bignum[j]=0;
	    d.bignum[i]=1;
	    d.length=i+1;
	    mov(b,&g);
        mul(g,d,&e);

	
		while (cmp(a,e)!=(-1))
		{
			c->bignum[i]++;
			sub(a,e,&f);
		    mov(f,&a);/*f复制给g*/
		}

     for(j=i;j<MAX;j++)/*高位清零*/
		 e.bignum[j]=0;
	
	}
	mov(a,w);
	if (c->bignum[m]==0) c->length=m;
	else c->length=m+1;

	return;
}

void expmod(struct slink a ,struct slink p ,struct slink n,struct slink *m)
{
	struct slink t,l,temp,w,s,c,b;/*/t放入2，l放入1；*/
	int i;
	for(i=0;i<MAX;i++)
		b.bignum[i]=l.bignum[i]=t.bignum[i]=w.bignum[i]=0;
	t.bignum[0]=2;t.length=1;
	l.bignum[0]=1;l.length=1;
    mov(l,&temp);
	mov(a,m);
    mov(p,&b);

	while(cmp(b,l)!=0)
	{
		for(i=0;i<MAX;i++)
			w.bignum[i]=c.bignum[i]=0;

		divt(b,t,&w,&c);/*// c=p mod 2  w= p /2*/
		
		mov(w,&b);/*//p=p/2*/

	if(cmp(c,l)==0) /*/余数c==1*/
	{
		for(i=0;i<MAX;i++)
			w.bignum[i]=0;

		mul(temp,*m,&w);

		mov(w,&temp);
		
		for(i=0;i<MAX;i++)
			w.bignum[i]=c.bignum[i]=0;

		 divt(temp,n,&w,&c);/* /c为余c=temp % n，w为商w=temp/n */

		 mov(c,&temp);
	}

	for(i=0;i<MAX;i++)
		s.bignum[i]=0;

	mul(*m,*m,&s);//s=a*a

	for(i=0;i<MAX;i++)
		c.bignum[i]=0;

	divt(s,n,&w,&c);/*/w=s/n;c=s mod n*/

	mov (c,m);

	}

	for(i=0;i<MAX;i++)
		s.bignum[i]=0;

	mul(*m,temp,&s);

	for(i=0;i<MAX;i++)
		c.bignum[i]=0;

	divt(s,n,&w,&c);

	mov (c,m);/*余数s给m*/

	m->bignum[MAX-1]=a.bignum[MAX-1];/*为后面的汉字显示需要，用第99位做为标记*/

	return;/*/k=temp*k%n;*/

}


int   is_prime_san(struct slink p )
{
 
   int i;
   struct slink a,t,s,o; 
   for(i=0;i<MAX;i++)
	   s.bignum[i]=o.bignum[i]=a.bignum[i]=t.bignum[i]=0;
   t.bignum[0]=1;
   t.length=1;
   a.bignum[0]=2;// { 2,3,5,7 }
   a.length=1;

   sub(p,t,&s);

   expmod ( a, s, p ,&o);
   if ( cmp(o,t) != 0 ) 
   {
	  return 0;
   }
   a.bignum[0]=3;
   for(i=0;i<MAX;i++)  
	   o.bignum[i]=0;
   expmod ( a, s, p ,&o);
   if ( cmp(o,t) != 0 ) 	   
	{
	  return 0;
	}

   a.bignum[0]=5;
   for(i=0;i<MAX;i++) 
	   o.bignum[i]=0;

   expmod ( a, s, p ,&o);
   if ( cmp(o,t) != 0 ) 
   {	   
	  return 0;
   }

   a.bignum[0]=7;
   for(i=0;i<MAX;i++)  
	   o.bignum[i]=0;

   expmod ( a, s, p ,&o);

   if ( cmp(o,t) != 0 ) 
   {
	  return 0;
   }

   return 1;
}


int coprime(struct slink e,struct slink s) /*//// 求两个大数之间是否互质////*/

{
    struct slink a,b,c,d,o,l;
    int i;
	for(i=0;i<MAX;i++)
		l.bignum[i]=o.bignum[i]=c.bignum[i]=d.bignum[i]=0;
	o.bignum[0]=0;o.length=1;
	l.bignum[0]=1;l.length=1;
	mov(e,&b);
	mov(s,&a);
	do
	{
	if(cmp(b,l)==0)
	{
		return 1;
	}
	for(i=0;i<MAX;i++)
		c.bignum[i]=0;
	 divt(a,b,&d,&c);
	 mov(b,&a);/*b--->a*/
	 mov(c,&b);/*c--->b*/

	}while(cmp(c,o)!=0);
	/*	printf("Ihey are  not coprime!\n");*/
	return 0;
}
