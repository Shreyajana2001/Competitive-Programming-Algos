#include <stdio.h>
#include <stdlib.h>


struct Node
{
    char data;
    int priority;
    struct Node* next;
};

struct Node* enqueue(struct Node* head, char d, int p)
{
    struct Node* strt = head;

    struct Node* temp = (struct Node*)(malloc(sizeof(struct Node)));
    temp->data=d;
    temp->priority=p;
    temp->next=NULL;
   if(head==NULL)
   {
   head=temp;
   return head;
   }

    if (head->priority > p)
    {
        temp->next = head;
        head= temp;
		return head;
    }
    else
    {
        while (strt->next != NULL && strt->next->priority < p)
            strt = strt->next;

        temp->next = strt->next;
        strt->next = temp;
        return head;
    }

}

struct Node* dequeue(struct Node* head)
{
	if(head==NULL)
	printf("UNDERFLOW");
	else
	{
		struct Node* temp =head;
		printf("popped out item is %c ",head->data);
    head= head->next;
    free(temp);
		}
		return head;

}

void display(struct Node *head)
{
      struct Node* temp=head;
    while(temp)
    {
    	printf(" %c ",temp->data);
    	temp=temp->next;
	}
}

int main()
{

    struct Node* head=NULL;

    int choice;

    while(1)
    {
        printf("\n 1.enqueue \n 2.dequeue\n 3.display \n 4.exit ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            {
            char val;
            int priority;
            printf("Enter the value you want to add ");
            scanf(" %c",&val);
            printf("Enter its priority ");
            scanf("%d",&priority);
            head=enqueue(head,val,priority);
            }
            break;

            case 2:
            head=dequeue(head);
            break;

            case 3:
            display(head);
            break;

            case 4:
            exit(0);
            break;

            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
