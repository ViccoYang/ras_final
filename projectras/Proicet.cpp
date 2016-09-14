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


 struct slink *input(void)/*/�������Ĳ��ҷ���ͷָ�룬û�м���ʱ��ת��������*/
{   
  struct  slink *head;
  struct  slink *p1,*p2;
     int  i,n,c,temp;
    char  ch;
     n=0;
	p1=p2=(struct slink * )malloc(LEN);
	head=NULL;
	printf("\n����������Ҫ���ܵ����� : \n");
while((ch=getchar())!='\n')
   {
	i=0;
	c=ch;
	if(c<0)
	{
		c=abs(c);/*/�Ѹ���ȡ��������һ�����*/
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
	printf("���ܺ��γɵ��������ݣ�\n");
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
		printf("�������ĺ������ɵ�����:\n");
		for (i = 0; i < j; i++)
			printf("%c", ch[i]);
		printf("\n");
		return;

}


void menu()
{
	printf("��ӭ���Լ��ܽ���ϵͳ\n");
	printf(" 1�����������������Կ      \n");
	printf(" 2�����ܽ��ܲ���     \n");
	printf(" 3���˳�            \n");
	printf("��ѡ��һ�ֲ�����");

}



               			




/*/-------------------------------------------------��MAIN����-----------------------------------/*/
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
		 getchar();//���ܻس���
	if ((c=='1'))//����r������Կ��
	{        
		 for(i=0;i<MAX;i++)
             m.bignum[i]=p.bignum[i]=q.bignum[i]=n.bignum[i]=d.bignum[i]=e.bignum[i]=0;
		 m.length=p.length=q.length=n.length=d.length=e.length=0;
			printf("�������������P,Q��\n");
			printf("�����������P,Q��λ����");
			printf("p=");
			/*P_length=getchar();*/
			cin >> P_length;
			printf("q=");
			cin >> Q_length;
            /*Q_length=getchar();*/
	        prime_random(&p,&q,P_length,Q_length);/*/�����������������*/
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
			printf("�� p��q �ó� n :");
			print(&n);
	        mov(p,&p1);
			p1.bignum[0]--;      
            mov(q,&q1);
			q1.bignum[0]--;      /*/q-1;*/
	        mul(p1,q1,&m);//m=(p-1)*(q-1)
	        erand(e,m);
	        rsad(e,m,&d);
			printf("��Կ�Բ�����ɣ����ڿ���ֱ�ӽ��мӽ���!\n");
				printf("\n������������˵���������");
			getchar();
	}
		
		else if((c=='2'))
		{
			  head=input();
              h1=jiami(  e,  n, head);
                 jiemi(  d,  n, h1);
				 printf("\nRSA���Թ������!\n");
			 printf("\n������������˵���������");
			 getchar();
		}
		else if ((c=='3'))
			break;
	 }
	

}


