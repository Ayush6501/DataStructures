//Program showcasing different operations on a linear queue
#include "stdio.h"

struct pizza
{
    int id, qty;
    char name[20], address[30];
};

int id = 1, rear = -1, front = -1;
int MAX = 4;
struct pizza p[4];

int IsFull()
{
    if(rear == front - 1 || front == 0 && rear == MAX -1 )
    {
        return 1;
    }
    else
    {
        return 0;
    }    
}

int IsEmpty()
{
    if(front == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void PlaceOrder()
{
    if(!IsFull())
    {
        if (front == -1)
        {
            front = 0;
        }
        rear =  (rear + 1) % MAX;
        p[rear].id = id++;
        printf("\nEnter name: ");
        scanf("%s", p[rear].name);
        printf("\nEnter address: ");
        scanf("%s", p[rear].address);
        printf("\nEnter quantity: ");
        scanf("%d", &p[rear].qty);
    }
    else
    {
        printf("Order Capacity is full");
    }
}

void DispatchOrder()
{
    if(!IsEmpty())
    {
        printf("\nDispatched Order is: ");
        printf("\n%d\t%s\t%s\t%d", p[front].id, p[front].name, p[front].address, p[front].qty);
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else 
        {
            front = (front + 1) % MAX;
        }
    }
    else
    {
        printf("\nThere are no orders to be dispatched");
    }
}

void Display()
{
    printf("\nThe pending Orders are: ");
    if (front == -1) 
    { 
        printf("\nQueue is Empty"); 
        return; 
    } 
    if (rear >= front) 
    { 
        for (int i = front; i <= rear; i++) 
        {
            printf("\n%d\t%s\t%s\t%d", p[i].id, p[i].name, p[i].address, p[i].qty); 
        }
    } 
    else
    { 
        for (int i = front; i < MAX; i++)
        { 
            printf("\n%d\t%s\t%s\t%d", p[i].id, p[i].name, p[i].address, p[i].qty); 
        }
        for (int i = 0; i <= rear; i++) 
        {
            printf("\n%d\t%s\t%s\t%d", p[i].id, p[i].name, p[i].address, p[i].qty); 
        }
    }
}

int main()
{   
    int choice;
    do
    {
        printf("\n\n**** Pizza MENU ****");
        printf("\n1. Place order");
        printf("\n2. Dispatch Order");
        printf("\n3. Pending Orders");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                PlaceOrder();
                break;
            
            case 2 :
                DispatchOrder();
                break;

            case 3:
                Display();
                break;
        }
    } while (choice != 4);
    return 0;
}
