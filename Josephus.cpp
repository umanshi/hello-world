// Josephus Problem Using Circcular Linked List :)
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
struct node
{
	char name;
	struct node* link;
} *LAST = NULL;

int n;

/*void display ( struct node** last )
{
 struct node* p;
 if(last==NULL)
   {printf("List is Empty!\n");
    return;}
 p = last->link;
 do
  {
   	 printf("%c", p->name);
  }
 while( p!=last->link);
 printf("\n");
}
*/

void display (struct node* LAST)  // mosify so that one element can also be sisplayed
{
 struct node *p;
 //last = *l;
 if(LAST==NULL)
  { printf("List is Empty ;;;;;;;;;;;;;;;;;;;;");
    return;
  }
 p = LAST->link;
 do
 {
 	printf("%c ",p->name);
 	p=p->link;
 }
 while(p!=LAST->link);
 printf("\n"); 
}//End of display
/*//ORIGINAL PUSH THAT DIDN'T WORK
struct node* push (struct node* LAST, char data) // at address l, last is stored
{
  struct node* newNode, *temp;
  newNode = (struct node*)malloc(sizeof (struct node));
  newNode->name= data;
 
 if(LAST == NULL)
   {
   	LAST = newNode;  // last = mewNode
   	newNode->link=newNode;
   	return LAST;
   } 
  else
   {
   	temp = LAST;
    newNode->link=temp->link;
    temp->link=newNode;
    return LAST;
   }
  printf("\n______________________PUSHED;");
}
*/
///////////////////////////////////////////////////////////
//   SECOND PUSH

void push ( char data) // at address l, last is stored
{
  struct node* newNode, *temp;
  newNode = (struct node*)malloc(sizeof (struct node));
  newNode->name= data;
 
 if(LAST == NULL)
   {
   	LAST = newNode;  // last = mewNode
   	newNode->link=newNode;
   	return;
   } 
  else
   {
   	temp = LAST;
    newNode->link=temp->link;
    temp->link=newNode;
    return;
   }
  printf("\n______________________PUSHED;");
}


struct node* addAtLast ( struct node* last, char data)
{
 struct node* tmp;
 tmp = (struct node*)malloc(sizeof(struct node));
 tmp->name = data;
 tmp->link = last->link;
 last->link = tmp;
 last = tmp;
 return last;
}
struct node* create_list(struct node* LAST)
{
	int i;

	printf("\n\nEnter the number of soldiers in the circle :\n ");
   // printf("                                              ");
	scanf("%d",&n);
    char Name[2];
	//struct node* last;
	LAST = NULL;
//	if(n==0)
//	   return last;
    
	for(i=1; i<=n; i++)
	{    
		printf("Enter the soldier's name at position %d : ", i);
		scanf("%s", &Name);
		
		//printf( "\nThe name of the soldier is : %c\n", Name[0]);
		push(Name[0]);
	 //  last = addAtLast(last, 'a');
	   // continue;
	}
	//last = push ( *last, Name[0]);
	return LAST;
} // end of Create list

 void Delete ( int skip)
{ struct node *p, *haha, *tmp;
 if(LAST->link==LAST)
   {
   printf(" \n %c is the Soldier who will live... :)", p->name);
   printf(" \nRest all will have to die! :(", p->name);
   //break;
   return;
   }  
 else
   {//	printf("\nPREV LAST is : %c", LAST->name);
   	p = LAST;
	for (int i=0; i<skip-1; i++)
	  {
	    p=p->link;
	  }	  
	haha = p;  
	tmp = p->link;
	p->link = tmp->link;
	
	
	printf(" \nThe soldier who is removed from the circle is : %c", tmp->name);
	free(tmp);
	LAST = haha;
		//printf("\nNEW LAST is : %c", LAST->name);
	//printf(" \n New List ::  ");
    printf("\n  Soldiers in the circle are : ");
	display(LAST);
	

	Delete(skip);
   }
  
  return;
}

int main ()
{   int skip;
    struct node *tmp, *p;
    //char oneName;
	printf("                 THE SOLDIER'S PROBLEM \n");
	Sleep(50);
	printf("                _");
	for(int i=0; i<22;i++)
	{
	Sleep(45);
	printf("_");
    }
	create_list(LAST);
	display (LAST);
	time_t t;
	srand((unsigned)time(&t));
	skip = rand()%n+1;
	printf("\nThe number of soldiers to skip : %d", skip);
	//scanf("%d", &skip);

    p = LAST;
     for (int i=0; i<skip-1; i++)  // Brings you to the element one short of skip th element 
	  {
	    p=p->link;
	  }	  
  LAST = p;
	Delete(skip);        // DEltes from (skip)th Node.
}
