// Proicet.cpp : Defines the entry point for the console application.
//


#include<stdio.h>
#include<string.h>
#include <stdlib.h>   
#include <time.h>  
#include <math.h>
#include <malloc.h>
#include<iostream>
#include"BigData.h"
#include"RandData.h"

using namespace std;
int Q_length=0;
int P_length=0;
#define LEN sizeof(struct slink)
void sub(struct slink a,struct slink b ,struct slink *c );


 struct slink *input(void)/*/输入明文并且返回头指针，没有加密时候转化的数字*/
{   
  struct  slink *head;
  struct  slink *p1,*p2;
     int  i,n,c,temp;
    char  ch;
     n=0;
	p1=p2=(struct slink * )malloc(LEN);
	head=NULL;
	printf("\n请输入你所要加密的内容 : \n");
while((ch=getchar())!='\n')
   {
	i=0;
	c=ch;
	if(c<0)
	{
		c=abs(c);/*/把负数取正并且做一个标记*/
		p1->bignum[MAX-1]='0';
	}
    else
	{
		p1->bignum[MAX-1]='1';
	}
	while(c/10!=0)
	{
		temp=c%10;
		c=c/10;
		p1->bignum[i]=temp;
		i++;
	}
	p1->bignum[i]=c;
	p1->length=i+1;
	n=n+1;
	if(n==1)
		head=p1;
	else p2->next=p1;
	p2=p1;
    p1=(struct slink * )malloc(LEN);
	}
    p2->next=NULL; 
	return(head);
}



struct slink *jiami(struct slink  e,struct slink  n,struct  slink *head)
{
	struct  slink *p;
	struct  slink *h;
	struct  slink *p1, *p2;
	int  m = 0, i;
	printf("\n");
	printf("加密后形成的密文内容：\n");
	p1 = p2 = (struct slink*)malloc(LEN);
	h = NULL;
	p = head;
	if (head != NULL)
		do
		{

			expmod(*p, e, n, p1);

			for (i = 0; i < p1->length; i++)
			{
				printf("%d", p1->bignum[p1->length - 1 - i]);
			}

			m = m + 1;
			if (m == 1)
				h = p1;
			else p2->next = p1;
			p2 = p1;
			p1 = (struct slink *)malloc(LEN);
			p = p->next;
		} while (p != NULL);
		p2->next = NULL;
		p = h;
		printf("\n");

		return(h);

}

void jiemi(struct slink d, struct slink n, struct  slink *h)
{
	int   i, j, temp;
	struct slink *p, *p1;
	char ch[65535];
	p1 = (struct slink*)malloc(LEN);
	p = h;
	j = 0;

	if (h != NULL)
		do
		{
			for (i = 0; i < MAX; i++)
				p1->bignum[i] = 0;

			expmod(*p, d, n, p1);

			temp = p1->bignum[0] + p1->bignum[1] * 10 + p1->bignum[2] * 100;
			if ((p1->bignum[MAX - 1]) == '0')
			{
				temp = 0 - temp;
			}

			ch[j] = temp;
			j++;
			p = p->next;
		} while (p != NULL);
		printf("\n");
		printf("解密密文后所生成的明文:\n");
		for (i = 0; i < j; i++)
			printf("%c", ch[i]);
		printf("\n");
		return;

}


void menu()
{
	printf("欢迎测试加密解密系统\n");
	printf(" 1、产生随机大素数密钥      \n");
	printf(" 2、加密解密测试     \n");
	printf(" 3、退出            \n");
	printf("请选择一种操作：");

}



               			




/*/-------------------------------------------------主MAIN函数-----------------------------------/*/
void main()
{
	   int  i;
	  char  c;
       struct slink  p,q,n,d,e,m,p1,q1;
	struct slink *head,*h1;
 
	 while (1)
	 {
		 menu();
		 c=getchar();
		 getchar();//接受回车符
	if ((c=='1'))//操作r产生密钥对
	{        
		 for(i=0;i<MAX;i++)
             m.bignum[i]=p.bignum[i]=q.bignum[i]=n.bignum[i]=d.bignum[i]=e.bignum[i]=0;
		 m.length=p.length=q.length=n.length=d.length=e.length=0;
			printf("产生随机大素数P,Q：\n");
			printf("请输入大素数P,Q的位数：");
			printf("p=");
			/*P_length=getchar();*/
			cin >> P_length;
			printf("q=");
			cin >> Q_length;
            /*Q_length=getchar();*/
	        prime_random(&p,&q,P_length,Q_length);/*/随机产生两个大素数*/
			//p.length = 3;
			//q.length = 4;
			//p.bignum[0] = 1;
			//p.bignum[1] = 0;
			//p.bignum[2] = 6;
			//q.bignum[0] = 3;
			//q.bignum[1] = 4;
			//q.bignum[2] = 4;
			//q.bignum[3] = 8;
			//e.length = 3;
			//e.bignum[0] = 7;
			//e.bignum[1] = 4;
			//e.bignum[2] = 2;
			//d.length = 7;
			//d.bignum[0] = 3;
			//d.bignum[1] = 8;
			//d.bignum[2] = 5;
			//d.bignum[3] = 6;
			//d.bignum[4] = 1;
			//d.bignum[5] = 7;
			//d.bignum[6] = 4;
	        mul(p,q,&n);
			printf("由 p、q 得出 n :");
			print(&n);
	        mov(p,&p1);
			p1.bignum[0]--;      
            mov(q,&q1);
			q1.bignum[0]--;      /*/q-1;*/
	        mul(p1,q1,&m);//m=(p-1)*(q-1)
	        erand(e,m);
	        rsad(e,m,&d);
			printf("密钥对产生完成，现在可以直接进行加解密!\n");
				printf("\n按任意键回主菜单…………");
			getchar();
	}
		
		else if((c=='2'))
		{
			  head=input();
              h1=jiami(  e,  n, head);
                 jiemi(  d,  n, h1);
				 printf("\nRSA测试工作完成!\n");
			 printf("\n按任意键回主菜单…………");
			 getchar();
		}
		else if ((c=='3'))
			break;
	 }
	

}


