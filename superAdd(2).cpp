// also do it for n numbers later on XD It'll be fun!!!
// One node stores 4 digits; gives sum... Handles negative numbers as well.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int digits[2], nodes[2];
struct node
 {int info;
  struct node *link, *prev;
 } *L[2], *sum=NULL;
 
void push (struct node **list, int n)
{
 struct node* tmp;
 tmp = (struct node*)malloc(sizeof(struct node)); 
 if (tmp==NULL)
   {
    printf("Stack Overflow!!  :(\n");
    return;
   }
 tmp->info = n;  
 tmp->link = *list;
 *list = tmp;
 //printf("\n________Pushed %d\n", n);
}

int isEmpty(struct node** top)
{
  if( *top == NULL)
    return 1;
  else
    return 0;
}

int pop (struct node** list)
{   struct node* tmp = *list; 
   if (isEmpty(&tmp))
       {printf("Empty List!");
        exit(1);
	   }
	else   
	 {
	 int item = tmp->info;

	 *list = tmp->link;
	 free(tmp);
	 return item;
     }
}

void display (struct node** list)
{ //printf("____________________________________________________________________");
//printf("Displaying a linked list!!!!!!!!!!!!!!!!!!!");
  int result;
  struct node* ptr;
  ptr = *list;
  if (isEmpty(list))             // isEmpty wants this Data Type
    {printf("The List is empty! :(");
	 return;
	}
  while (ptr!= NULL)
    {
    	printf("%04d", ptr->info);
    	ptr = ptr->link;
	}
	printf("\n");
}
/*void showArray (char arr[])
{ printf("\n ARRAY IS : ");
	for(int i=0; i<digits; i++)
      {
      	printf(" %c", arr[i]);
	  }
}*/
void add (struct node** l1, struct node** l2)
{//printf("\nInside add function loop");
 int max = nodes[0];
 int min = nodes[1];
 int i, temp, carry = 0;
 for (i=0; i<min; i++)
  { 
    temp = pop(&L[0])+pop(&L[1])+carry;
   	carry=temp/10000;
  
  	push (&sum, temp%10000);
  }

if (min<max)
  {   	
  	  if (L[0]==NULL)  	
  	     {  
		    for (i=0; i<max-min; i++) 
  	  	    {  
				int t = pop(&L[1])+carry;
  	
				push(&sum, t%10000);
				carry = t/10000;
  	  	    }
         }
	  else if (L[1]==NULL)
	      {  
	        for(i=0; i<max-min; i++)	
			   {    
				int t = pop(&L[0])+carry;
				push(&sum, t%10000);	
  	  	        carry = t/10000;
   	           }
		 }
  }  
//printf("\n before carry, all pushed to sum");
if(carry)
    {push(&sum, carry);
	}
//printf("\n Everything pushed into sum\n");
display(&sum);
}

void subtract (void)
{int temp, less = 0;
 int max = nodes[0];
 int min = nodes[1];	
 for (int i =0; i<min; i++)
   {
   	temp = pop(&L[0])-less-pop(&L[1]);
//   	printf("\n\ntemp is %d +++++++++++++++", temp);
	if (temp<0)
   	  {
		 push(&sum, 10000+temp);
         less = 1;
	  }
	else
   	  {
		 push(&sum, temp);
         less=0;
	  }
   }
for(int i = min+1; i<=max; i++)
  { temp = pop(&L[0])-less;
    if (temp<0)
      {
      	 push(&sum, 10000+temp);
      	 less = 1;
	  }
	else 
	  {
	  	push(&sum,temp);
	  	less = 0;
	  }
  }
 display(&sum);
}
int main()
{
 char num[2][1000], n1[1000], n0[1000], sign='o';
 int temp,j=0,i=0,len0,len1,right;
 
/** Take in User's Input and store it in character arrays num1 and num2*/
 printf("Enter the first number: ");
 scanf("%s", n0);
 printf("Enter the second number: ");
 scanf("%s", n1);

//********* Put BIGGER ARRAY IN NUM1 ****************
if(n0[0]=='-')
  len0 = strlen(n0)-1;
else
  len0 = strlen(n0);
if(n1[0]=='-')
  len1 = strlen(n1)-1;
else
  len1 = strlen(n1);
       
if (len0>len1)
   right = 1;
else if(len0==len1)
   {
   	 for (int p=0;p<len0;p++)
   	   {//TAKE CARE OF NEG SIGN.. DON'T COMPARE IT TOO...
   	    int p0, p1;
	    if (n0[0]=='-')
   	        p0 = p+1;
   	    else p0 = p;
		if(n1[0]=='-')
		    p1 = p+1;
		else p1 = p;
		 
   	   	if (n0[p0]==n1[p1])
   	   	  continue;
   	   	else if ( n0[p0]>n1[p1])
   	   	  {	right = 1;
   	   	    break;
   	      }
		else if(n0[p0]<n1[p1])
   	   	  { right = 0;
   	        break;     
		  }
	   }
   }
else
   right = 0;
//printf("\nright = %d", right);
//showArray(n0);
//4showArray(n1);   
//int p0, p1;
if (right == 1)
{ 
 // if(n0[0]!='-')   // ENTERING NUM0 IF POSI
   // printf("\n\nnum0 will have %d characters ", len0);
    //p0=p;
	for(int p = 0; p<len0; p++)  // p is independent of earlier variable
       { int p0,p1;
	     if (n0[0]=='-')
   	         p0 = p+1;   	
	     else p0 = p;
        num[0][p] = n0[p0] ;
	   }
    for(int p = 0; p<len1; p++)  // p is independent of earlier variable
       { int p0,p1;
	     if(n1[0]=='-')
		    p1 = p+1;
	     else p1 = p;
	    num[1][p] = n1[p1] ;
	   }
}
else
{
    for(int p = 0; p<len1; p++)  // p is independent of earlier variable
       { int p0, p1; 
	    if (n1[0]=='-')
   	        p1 = p+1;   	
	     else p1 = p;
        num[0][p] = n1[p1] ;
	   }
    for(int p = 0; p<len0; p++)  // p is independent of earlier variable
       {int p0, p1; 
	    if(n0[0]=='-')
		    p0 = p+1;
	     else p0 = p;
	    num[1][p] = n0[p0] ;
	   }
} /*   
  {   
     for(int p = ; p<len0+1; p++)  //ENTERING IF NUM0 NEGATIVE // p is independent of earlier variable
       { num[0][p] = n0[p0] ;}
  }
  
  
   for(int p =0; p<len1; p++)   // eNTER NUM1.. POSITIVE AND NEGATIVE
    {  num[1][p] = n1[p];}
    }
else 
  {for(int p = 0; p<len0; p++)
    {  num[1][p] = n0[p]; }
   for(int p = 0; p<len1; p++)
    {  num[0][p] = n1[p]; }*/
  //}//******************************************8
 //** calculate digits;&&&&&&&&&&&&&&&&&&&7
for (int u=0; u<2; u++)
{ digits[u]=0;
  nodes[u]=0;
}
//printf("\nlen0=%d\nlen1=%d",len0, len1);
if (right==1)
 {
 	digits[0]=len0;
 	digits[1]=len1;
 }
else
 {
 	digits[0]=len1;
 	digits[1]=len0;
 }
	
//printf("\ndigits[0] =%d\ndigits[1] =%d", digits[0], digits[1])	;
//display array
/*printf("\nThe Larger array is : **\n ");
for (int p = 0; p<digits[0]; p++)
{
	printf("%c", num[0][p]);
}*/
//digits=digits[0];
//showArray(num[0]);
//for(int i=0; i<digits[0]; i++)
  //    {
    //  	printf(" %c", num[0][i]);
	  //}
//** Put the two char arrays into linked lists as long integers
for (int k=0; k<2; k++)
{ 
  int x, y;	

  if (num[k][0]=='-')
  { x = (digits[k]-1)%4;
    y = (digits[k]-1)/4;
    i =1;  //Insertion will begin from i;
  }
  else
  { x = digits[k]%4;
    y = digits[k]/4;
    i = 0; // Insertion begins 
   // printf("\nPositive number");
  }
   // i=0;
  nodes[k]= y+1;  // will be changed later if wrong in case 1

//printf( "\n x=%d\n y=%d\n i=%d\n",x,y,i);
 switch (x)
 {
	case 0:
		    nodes[k] = y;
		    break;
	case 1:
	    	push(&L[k], num[k][i]-48 );
	    	i=i+1;
			break;
	case 2:
		    push (&L[k], 10*(num[k][i]-48)+num[k][i+1]-48);
	        i=i+2;
			break;
    case 3:
    	    push(&L[k], 100*(num[k][i]-48)+10*(num[k][i+1]-48)+num[k][i+2]-48);
    	    i=i+3;
			break;
 }
for ( int  m=0; m<y; m++)
  { 
  	push (&L[k], 1000*(num[k][i]-48)+100*(num[k][i+1]-48)+10*(num[k][i+2]-48)+ num[k][i+3]-48);
    i = i+4;
  }  
} //Filling in ends **//

//COMPARE AND PUT THE LARGERST ARRAY IN l1; (UPWARDS)
printf("The sum of two numbers is: ");
if( (n0[0]=='-'&&n1[0]=='-') || (n0[0]!='-'&&n1[0]!='-') ) // BOTH POSITIVE OR NEGATIVE
   {
   	if(n0[0]=='-')
   	  printf("\n-");
   	add(&L[0],&L[1]);
   }
else
{   if( ( (right==1)&&(n0[0]=='-') ) || ( (right==0)&&(n1[0]=='-') ) )
       printf("\n-");
	subtract(); // with other conditions  \\ Subtract linked lists ....> here no argument for this function because this function uses value by reference	
}
}
