#include "stdio.h"
#include "stdlib.h"

typedef struct node
{
    int number;
    struct node *next;
}node;

node *list = NULL;
node *list2 = NULL;

void Display(node *head)
{
    node *temp = head;

    //iterate the entire linked list and print the data
    while(temp != NULL)
    {
        printf("%d -> ", temp->number);
        temp = temp->next;
    }
    printf("NULL\n");
}

void CreateLinkedList(int num, node** list)
{
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        exit(1);
    }

    n -> number = num;
    n -> next = NULL;

    node *last = *list;
    if (*list == NULL)
    {
        *list = n;
        return;
    }
    while(last->next != NULL)
    {
        last = last->next;
    }
    last->next = n;
}

// void AddAtBeginning(int num, node** list)
// {
//     node *n = malloc(sizeof(node));
//     if (n == NULL)
//     {
//         exit(1);
//     }

//     n -> number = num;
//     n -> next = *list;

//     *list = n;    
// }

void Deletion(int pos, node **list)
{
    if (*list == NULL)
    {
        return;
    }

    node *temp = *list;
    if (pos == 0)
    {
        *list = temp -> next;
        free(temp);
        return;
    }

    for (int i=0; temp!=NULL && i < pos-1; i++) 
    {
        temp = temp->next; 
    }

    if (temp == NULL || temp->next == NULL) 
        return;

    node *next = temp->next->next; 
    free(temp->next);
    temp -> next = next;
}

void Insertion(int num, int pos, node **list)
{
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        exit(1);
    }

    n -> number = num;
    if(pos == 0)
    {
        n -> next = *list;
        *list = n;
        printf("\nNode inserted at Index %d\n", pos);
        return;
    }

    node *temp = *list;

    for (int i = 0; temp!=NULL && i < pos-1; i++) 
    {
        temp = temp->next; 
        if (temp == NULL)
        {
            printf("\nCan't Insert\n");
            return;
        }
    }

    n -> next = temp -> next;
    temp -> next = n;
    printf("\nNode inserted at Index %d\n", pos);
}

void ReverseLinkedList(node **list)
{
    node* prev = NULL;
    node* curr = *list;
    node* after = NULL;
    while (curr != NULL)
    {
        after = curr->next;
        curr->next = prev;
        prev = curr;
        curr = after;
    }
    *list = prev;
    printf("\nLinked List is Reversed\n");
}

void SortLinkedList(node **list)
{
    int swap, i, temp;
    node *ptr1;
    node *lptr = NULL;

    // Checking if list is empty
    if (*list == NULL)
    {
        printf("\nLinked list is empty\n");
        return;
    }

    do
    {
        swap = 0;
        ptr1 = *list;

        while (ptr1->next != lptr)
        {
            if (ptr1->number > ptr1->next->number)
            {
                temp = ptr1 -> number;
                ptr1 -> number = ptr1->next->number;
                ptr1->next->number = temp;
                swap = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swap);

    printf("\nLinked List is Sorted\n");
}

void MoveNode(node **destRef, node **sourceRef)  
{  
    node* newNode = *sourceRef;  
    *sourceRef = newNode->next;  
  
    newNode->next = *destRef;  
    *destRef = newNode;  
}

node* MergeLinkedList(node *list, node *list2)
{
    node* result = NULL; 
    
  /* point to the last result pointer */
    node** lastPtrRef = &result;  
    
  while(1)  
  { 
    if (list == NULL)  
    { 
      *lastPtrRef = list2; 
       break; 
    } 
    else if (list2 == NULL)  
    { 
       *lastPtrRef = list; 
       break; 
    } 
    if(list->number <= list2->number)  
    { 
      MoveNode(lastPtrRef, &list); 
    } 
    else 
    { 
      MoveNode(lastPtrRef, &list2); 
    } 
    
    // to move the pointer to the last posn of the result LL
    lastPtrRef = &((*lastPtrRef)->next);  
  } 
  return(result);
}

int main()
{
    int n, num, choice, pos, posn;
    do
    {
        printf("\n\n**** MENU ****");
        printf("\n1. Create a Linked List");
        printf("\n2. Insert Element");
        printf("\n3. Delete an Element from Linked List");
        printf("\n4. Display LinkedList");
        printf("\n5. Reverse the LinkedList");
        printf("\n6. Sort the LinkedList");
        printf("\n7. Merge the LinkedList");
        printf("\n8. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter no. of elements: ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++)
                {
                    printf("\nEnter element: ");
                    scanf("%d", &num);
                    CreateLinkedList(num, &list);
                }
                break;               
            
            case 2:
                printf("\nEnter the position to be inserted: ");
                scanf("%d", &posn);
                printf("\nEnter the element to be inserted: ");
                scanf("%d", &num);
                Insertion(num, posn, &list);
                break;

            case 3:
                printf("\nEnter the position to be deleted: ");
                scanf("%d", &pos);
                Deletion(pos, &list);
                // printf("\nElement has been deleted");
                

            case 4:
                Display(list);
                break;

            case 5:
                ReverseLinkedList(&list);
                Display(list);
                break;

            case 6:
                SortLinkedList(&list);
                Display(list);
                break;   

            case 7:
                printf("\nEnter no. of elements: ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++)
                {
                    printf("\nEnter element: ");
                    scanf("%d", &num);
                    CreateLinkedList(num, &list2);
                }
                SortLinkedList(&list2);
                Display(list);
                Display(list2);

                node *merged = NULL;
                merged = MergeLinkedList(list, list2);
                Display(merged);
                break;             
        }
    } while (choice != 8);
    return 0;

}
