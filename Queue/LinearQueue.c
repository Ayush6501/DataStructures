//Program showcasing operations on a linear queue
#include "stdio.h"

struct pizza
{
    int id, qty;
    char name[20], address[30];
};

int id = 1, rear = -1, front = -1;
int MAX = 6;
struct pizza p[6];

int IsFull()
{
    if(rear == MAX -1)
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
    if(front == rear)
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
        rear++;
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
        front++;
        printf("\nDispatched Order is: ");
        printf("\n%d\t%s\t%s\t%d", p[front].id, p[front].name, p[front].address, p[front].qty);
    }
    else
    {
        printf("\nThere are no orders to be dispatched");
    }
}

void Display()
{
    printf("\nThe pending Orders are: ");
    for (int i = front+1; i <= rear; i++)
    {
        printf("\n%d\t%s\t%s\t%d", p[i].id, p[i].name, p[i].address, p[i].qty);
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
