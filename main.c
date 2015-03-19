#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct student
{
	char name[20];
	int num;
	float grade;
	struct student *next;
};
struct student *creat()
{
	struct student *x,*y,*head;
	int n=0;
	head=NULL;
	x=y=(struct student *)malloc(sizeof(struct student));
	printf("\n");
	printf("          ===========inputing==============                \n");
	printf("\n");
	printf("num: ");
	scanf("%d",&x->num);
	printf("name: ");
	scanf("%s",x->name);
	printf("grade: ");
	scanf("%f",&x->grade);
	printf("\n");
	printf("          ===========next===================               \n");
	printf("\n");
	while(x->num!=0)
	{
		if(n==0)
			head=x;
		else
			y->next=x;
		y=x;
		x=(struct student *)malloc(sizeof(struct student));
		printf("num: ");
        scanf("%d",&x->num);
        printf("name: ");
	    scanf("%s",x->name);
	    printf("grade: ");
	    scanf("%f",&x->grade);
	    printf("\n");
	    printf("          ===========next===================               \n");
	    printf("\n");
		n++;
	}
	y->next=NULL;
	return(head);
}
void print(struct student *head)
{

    struct student *hea;
    hea=head;
    printf("\n");
    printf("             =========print=============              \n");
    printf("\n");
    while(hea!=NULL)
	{

		printf("num: %d    name: %s     grade: %f\n",hea->num,hea->name,hea->grade);
		hea=hea->next;
	}
	printf("\n");
	printf("             ==============finished==============               \n");
	printf("\n");
}
void delet(struct student *head)
{

	int x;
    struct student *hea;
    printf("\n");
    printf("             ==================delete============                \n");
    printf("\n");
    hea=head;
	printf("which num do you want to delete: ");
	scanf("%d",&x);
	while(hea->next->num!=x)
	{
		hea=hea->next;
	}
    hea->next=hea->next->next;
    printf("\n");
	printf("             =========finished===================               \n");
    printf("\n");

}
void add(struct student *head)
{

	int x;
	struct student *mid;
	struct student *mid2;
	printf("\n");
	printf("             ===============add==================               \n");
	printf("\n");
	mid=(struct student *)malloc(sizeof(struct student));
	mid2=(struct student *)malloc(sizeof(struct student));
	printf("which num do you want to add after: ");
	scanf("%d",&x);
	while(head->num!=x)
	{
		head=head->next;
	}
    printf("\n");
	printf("=======input your dates===========\n ");
	printf("\n");
    printf("num: ");
	scanf("%d",&mid->num);
	printf("name: ");
	scanf("%s",mid->name);
	printf("grade: ");
	scanf("%f",&mid->grade);
    mid2=head->next;
	head->next=mid;
	mid->next=mid2;
	printf("\n");
	printf("             =========finished===================               \n");
    printf("\n");
}
void change(struct student *head)
{
    int x;
    printf("\n");
    printf("             ===============change===============               \n");
    printf("\n");
    printf("which num do you want to change: ");
    scanf("%d",&x);
    while(head->num!=x)
	{
		head=head->next;
	}
	printf("\n");
	printf("==========input new date=========\n");
	printf("\n");
	printf("num: ");
	scanf("%d",&head->num);
	printf("name: ");
	scanf("%s",head->name);
	printf("grade: ");
	scanf("%f",&head->grade);
	printf("\n");
    printf("             =============finished================                \n");
    printf("\n");
}
void find(struct student *head)
{
    int x;
    printf("\n");
    printf("             ===============find===============               \n");
    printf("\n");
    printf("which num do you want to find: ");
    scanf("%d",&x);
    while(head->num!=x && head->next!=NULL)
	{
		head=head->next;
	}
	printf("\n");
	printf("             ==============result==============                \n");
	printf("\n");
	if(head->next==NULL && head->num!=x)
    {
        printf("No Found\n");
    }
    else if(head->next==NULL && head->num==x)
    {
        printf("num: %d    name: %s     grade: %f\n",head->num,head->name,head->grade);
    }
    else
    {
         printf("num: %d    name: %s     grade: %f\n",head->num,head->name,head->grade);
    }
    printf("\n");
	printf("             ==============finished============                 \n");
	printf("\n");
}
int main()
{
	int x=5;
    struct student *head;

	head=creat();

	while(x!=0)
	{
       printf("\n");
       printf("===============choosing===========\n");
       printf("1=====print\n");
	   printf("2=====delete\n");
	   printf("3=====add\n");
	   printf("4=====change\n");
	   printf("5=====find\n");
	   printf("0=====back\n");
	   printf("==================================\n");
	   printf("\n");
	   printf("what's your choose: ");
	   scanf("%d",&x);
	   if(x==1)
		   print(head);
	   else if(x==2)
		   delet(head);
	   else if(x==3)
		   add(head);
       else if(x==4)
           change(head);
       else if(x==5)
            find(head);
	   else if(x==0)
		   break;
	}
	return 0;

}
