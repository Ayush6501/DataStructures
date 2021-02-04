#include <stdio.h>

struct student
{
    int rno;
    char name[10];
    int marks;
    char div[2];
};

void accept(struct student s[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the name of the student: ");
        scanf("%s", &s[i].name);
        printf("\nEnter the Roll No: ");
        scanf("%d", &s[i].rno);
        printf("\nEnter the Marks: ");
        scanf("%d", &s[i].marks);
        printf("\nEnter the Div: ");
        scanf("%s", &s[i].div);
    }
}

void DisplayAll(struct student s[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\n\nName: %s", s[i].name);
        printf("\tRoll No: %d", s[i].rno);
        printf("\tMarks: %d", s[i].marks);
        printf("\tDiv: %s", s[i].div);
    }
}

void DisplayStudent(struct student s[], int n)
{
    printf("\n\nName: %s", s[n].name);
    printf("\tRoll No: %d", s[n].rno);
    printf("\tMarks: %d", s[n].marks);
    printf("\tDiv: %s", s[n].div);
}

void LinearSearch(struct student s[], int n)
{
    int key, flag = 0, pos;
    printf("Enter the Roll No. you want search: ");
    scanf("%d", &key);
    for(int i = 0; i < n; i++)
    {
        if(key == s[i].rno)
        {
            flag = 1;
            pos = i;
        }
    }  
    if (flag == 1)
    {
        printf("Roll No. exists at location index: %d", pos+1);
        DisplayStudent(s, pos);
    }
    else
    {
        printf("Roll No. doesnt exist");
    }
}

void BinarySearch(struct student s[],int n)
{
    int i,low=0,high=n-1,mid,key;
    printf("\nEnter roll number:");
    scanf("%d",&key);
    while(low<=high)
    {
        mid=(low+high)/2;
        if(s[mid].rno==key)
        {
            printf("\nRoll number found");
            DisplayStudent(s,mid);
            break;
        }
        else
        {
            if(s[mid].rno<key)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        if (low == high)
        {
            printf("\nRoll no. not found");
        }
    }
}

int RecursiveBinarySearch(struct student s[],int low,int high,int key)
{
    int mid;
    if(low<=high)
    {
        mid=(low+high)/2;
        if(s[mid].rno==key)
        {
            return mid;
        }
        else
        {
            if(key<s[mid].rno)
            {
                return RecursiveBinarySearch(s,low,mid-1,key);
            }
            else
            {
                return RecursiveBinarySearch(s,mid+1,high,key);
            }
        }
    }
    return -1;
}

void BubbleSort(struct student s[], int n)
{
    struct student temp;
    printf("Sorting roll no.s on the basis of marks: ");
    for(int i=0; i < n; i++)
    {
        for(int j=0; j < n-1; j++)
        {
            if (s[j].rno > s[j+1].rno)
            {
                temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
        printf("\nAfter pass %d : ", i+1);
        for (int k = 0; k < n; k++) 
        {
            printf("%d ", s[k].rno);
        }
    }
    printf("\n\nAfter Final sort: ");
    DisplayAll(s, n);
}

void SelectionSort(struct student s[], int n)
{
    int smallest, posn;
    struct student temp;
    printf("Sorting roll no.s: ");
    for(int i=0; i < n; i++)
    {
        smallest = s[i].rno;
        posn = i;
        for(int j=i+1; j < n; j++)
        {
            if (s[j].rno < smallest)
            {
                smallest = s[j].rno;
                posn = j;   
            }
            temp = s[i];
            s[i] = s[posn];
            s[posn] = temp;
        }
        printf("\nAfter pass %d : ", i+1);
        for (int k = 0; k < n; k++) 
        {
            printf("%d ", s[k].rno);
        }
    }
    printf("\n\nAfter Final sort: ");
    DisplayAll(s, n);
}

void InsertionSort(struct student s[], int n) 
{ 
    int i, key, j; 
    for (i = 1; i < n; i++) 
    { 
        key = s[i].rno; 
        j = i - 1; 
        while (j >= 0 && s[j].rno < key) 
        { 
            s[j + 1].rno = s[j].rno; 
            j = j - 1; 
        } 
        s[j + 1].rno = key; 
        printf("\nAfter pass %d : ", i);
        for (int k = 0; k < n; k++) 
        {
            printf("%d ", s[k].rno);
        }
	}
    printf("\n\nAfter Final sort: ");
    DisplayAll(s, n);
}

int main()
{
    struct student s[20];
    int num, choice;
    printf("\nEnter the no. of students: ");
    scanf("%d", &num);
    accept(s, num);
    do
    {
        printf("\n\n*** MENU ***");
        printf("\n1. Display");
        printf("\n2. Linear search");
        printf("\n3. Binary search");
        printf("\n4. Binary search with recursion");
        printf("\n5. Bubble sort");
        printf("\n6. Selection sort");
        printf("\n7. Insertion sort");
        printf("\n8. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            DisplayAll(s, num);
            break;
        
        case 2 :
            LinearSearch(s, num);
            break;
        
        case 3:
            BinarySearch(s, num);
            break;
        
        case 4:
            int f,key;
            printf("\nEnter roll no:");
            scanf("%d",&key);
            f = RecursiveBinarySearch(s,0,num-1,key);
            if(f == -1)
            {
                printf("\nRoll number not found");
            }
            else
            {
                printf("\nRoll number found");
                DisplayStudent(s,f);
            }
            break;
        
        case 5:
            BubbleSort(s, num);
            break;
            
        case 6:
            SelectionSort(s, num);
            break;

        case 7:
            InsertionSort(s, num);
            break;

        default:
            printf("Enter a valid choice.");
        }
    } while (choice != 8);
    
    return 0;
}
