#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
 {int info;
  struct node* link;
 } *Last[2], *sum = NULL;
int nodes[2], digits[2];

void push (struct node** l, int data) // at address l, last is stored
{ 
  struct node* newNode, *temp;
  newNode = (struct node*)malloc(sizeof (struct node));
  newNode->info= data; 
 if(*l == NULL)
   {
   	*l = newNode;  // last = mewNode
   	newNode->link=newNode;
   } 
  else
   {
   	temp = *l;
    newNode->link=temp->link;
    temp->link=newNode;
   }
}
int pop ( struct node** l)
{   int popped;
	struct node *last, *dying;
	last = *l;
	dying = (struct node*)malloc (sizeof(struct node*));
	dying = last->link; // last->link means first node;
	popped = dying->info;
	last->link = dying->link;
	free(dying);	
	return popped;
}
void display (struct node** l)
{
 struct node *p, *last;
 last = *l;
 if(last==NULL)
  { printf("List is Empty");
    return;
  }
 else
 { p = last->link;
  do
  {	printf("%04d",p->info);
 	p=p->link;
  }
  while(p!=last->link);
 }
  printf("\n"); 
}
void add (void)
{
 int max = nodes[0];
 int min = nodes[1];
 int i, temp, carry = 0;
 for (i=0; i<min; i++)
  { temp = pop(&Last[0])+pop(&Last[1])+carry;
   	carry=temp/10000;
  	push (&sum, temp%10000);
  }
 if (min<max)
  {   	      for(i=0; i<max-min; i++)	
			   {    
				int t = pop(&Last[0])+carry;
				push(&sum, t%10000);	
  	  	        carry = t/10000;
   	           }
  }  
if(carry)
    {push(&sum, carry);
	}
display(&sum);
}
void subtract (struct node** l1, struct node**l2)
{int i;
int temp, less = 0;
 int max = nodes[0];
 int min = nodes[1];	
 for ( i =0; i<min; i++)
   {
   	temp = pop(&Last[0])-less-pop(&Last[1]);
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
  { temp = pop(&Last[0])-less;
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
 int temp,j=0,i=0,p, u, len0,len1,right;
 printf(" ADDITION OF LONG INTEGERS USING\n");
 printf("       CIRCULAR LINKED LIST\n\n\n");
 printf("\nEnter the first number: ");
 scanf("%s", n0);
 printf("\nEnter the second number: ");
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
   	 for (p=0;p<len0;p++)
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
if (right == 1)
{ 
	for( p = 0; p<len0; p++)  // p is independent of earlier variable
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
    for( p = 0; p<len1; p++)  // p is independent of earlier variable
       { int p0, p1; 
	    if (n1[0]=='-')
   	        p1 = p+1;   	
	     else p1 = p;
        num[0][p] = n1[p1] ;
	   }
    for( p = 0; p<len0; p++)  // p is independent of earlier variable
       {int p0, p1; 
	    if(n0[0]=='-')
		    p0 = p+1;
	     else p0 = p;
	    num[1][p] = n0[p0] ;
	   }
} 
for ( u=0; u<2; u++)
{ digits[u]=0;
  nodes[u]=0;
}
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
  }
  nodes[k]= y+1;  // will be changed later if wrong in case 1
 Last[k]=NULL;
 switch (x)
 {
	case 0:
		    nodes[k] = y;
		    break;
	case 1:
	    	push(&Last[k], num[k][i]-48 );
	    	i=i+1;
			break;
	case 2:
		    push (&Last[k], 10*(num[k][i]-48)+num[k][i+1]-48);
	        i=i+2;
			break;
    case 3:
    	    push(&Last[k], 100*(num[k][i]-48)+10*(num[k][i+1]-48)+num[k][i+2]-48);
    	    i=i+3;
			break;
 }
for ( int  m=0; m<y; m++)
  { 
  	push (&Last[k], 1000*(num[k][i]-48)+100*(num[k][i+1]-48)+10*(num[k][i+2]-48)+ num[k][i+3]-48);
    i = i+4;
  }  
} 
printf("\n\nThe sum of two numbers is: ");
if( (n0[0]=='-'&&n1[0]=='-') || (n0[0]!='-'&&n1[0]!='-') ) // BOTH POSITIVE OR NEGATIVE
   {
   	if(n0[0]=='-')
   	  printf("\n-");
   	add();
   }
else
{   if( ( (right==1)&&(n0[0]=='-') ) || ( (right==0)&&(n1[0]=='-') ) )
       printf("\n-");
	subtract(&Last[0],&Last[1]); // with other conditions  \\ Subtract linked lists	
}
}
