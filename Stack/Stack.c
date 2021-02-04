//Program to convert a postix expression to prefix and vice versa
#include "stdio.h"
#include "string.h"

int const MAX = 10;
int top = -1;
char stack[20], stack2d[20][20], postfix[20];

int IsFull()
{
    if (top == MAX)
    {
        printf("Stack Overflow");
        return 1;
    }
    else
    {
        return 0;
    }
    
}

int IsEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int pop() {
   int data;
   if(!IsEmpty()) 
   {
      data = stack[top];
      top -= 1;   
      return data;
   } 
   else 
   {
      printf("Could not retrieve data, Stack is empty.\n");
      return 0;
   }
}

void* pop2d()
{
    char *temp = stack2d[top];
    top--;
    return(temp);
}

void push(int data) {

   if(!IsFull()) 
   {
      top += 1;   
      stack[top] = data;
   } 
   else 
   {
      printf("Could not insert data, Stack is full.\n");
   }
}

void push2d(char str1[20])
{
    top++;
    strcpy(stack2d[top], str1);
}

void Display()
{
    if(IsEmpty())
    {
        printf("Could not display data, Stack is empty.\n");
    }
    else
    {
        printf("The Elements in the stack are: \n");
        for(int i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

int Icp(char ch)
{
    if(ch == '+' || ch == '-')
    {
        return 1;
    }
    if(ch == '*' || ch == '/')
    {
        return 2;
    }
    if(ch == '^')
    {
        return 4;
    }
    if(ch == '(')
    {
        return 5;
    }
    else
    {
        return 0;
    } 
}

int Isp(char ch)
{
    if(ch == '+' || ch == '-')
    {
        return 1;
    }
    if(ch == '*' || ch == '/')
    {
        return 2;
    }
    if(ch == '^')
    {
        return 3;
    }
    else
    {
        return 0;
    } 
}

int IsOperator(char x)
{
    if(x == '+' || x == '-' || x == '*' || x == '/' || x == '^')
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

void ToPostfix(char infix[20])
{
    int i = 0, j = 0;
    while(infix[i] != '\0')
    {
        if (infix[i] >= 65 && infix[i] <= 90  || infix[i] >= 97 && infix[i] <= 122)
        {
            postfix[j] = infix[i];
            j++;
        }
        else if(infix[i] == '(')
        {
            push(infix[i]);
        }
        else if(infix[i] == ')')
        {
            while ((infix[i] = pop()) != '(')
            {
                postfix[j] = infix[i];
                j++;
            }
        }
        else if(!IsEmpty() && Isp(stack[top]) >= Icp(infix[i]))
        {
            postfix[j] = pop();
            j++;
            push(infix[i]);
        }
        else
        {
            push(infix[i]);
        }
        i++;
    }
    while(!IsEmpty())
    {
        postfix[j] = stack[top];
        top -= 1;
        j++;
    }
    printf("The Postfix expression is: ");
    for(int i = 0; i < 20; i++)
    {
        printf("%c", postfix[i]);
    }
    // EmptyArray(postfix);
}

void PostfixToInfix(char exp[20])
{
    char str[20], str1[20], operand1[20],operand2[20],str2[20];
    int i, l;
    for(i=0; exp[i]!= '\0'; i++){
        if(IsOperator(exp[i]))
        {
            strcpy(operand1, pop2d());
            strcpy(operand2, pop2d());
            str2[0] = '\0';
            str2[0] = '(';
            str2[1] = '\0';
            strcat(str2, operand2);
            l = strlen(str2);
            str2[l] = exp[i];
            str2[l+1] = '\0';
            strcat(str2, operand1);
            l = strlen(str2);
            str2[l] = ')';
            str2[l+1] = '\0';
            push2d(str2);
        }
        else{
            str1[0] = '\0';
            str1[0] = exp[i];
            str1[1] = '\0';
            push2d(str1);
        }
    }
    strcpy(str1,pop2d());
    printf("\nInfix expression is: ");
    printf("\t%s", str1);
}

int main()
{   
    char infixexp[20], postfixexp[20], data;
    int choice, n;
    do
    {
        printf("\n\n*** MENU ***");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Peek");
        printf("\n4. Display");
        printf("\n5. Convert Infix to Postfix");
        printf("\n6. Convert Postfix to Infix");
        printf("\n7. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter no. of Element to pushed: ");
                scanf("%d", &n);
                for(int i = 0; i < n; i++)
                {
                    printf("\nEnter Element to pushed: ");
                    scanf("%c", &data);
                    push(data);
                }
                break;
            
            case 2 :
                printf("\nElement has been popped.");
                pop();
                break;

            case 3:
                break;
            
            case 4:
                Display();
                break;
                
            case 5:
                printf("\nEnter an Infix expression: ");
                scanf("%s", &infixexp);
                ToPostfix(infixexp);
                break;
            
            case 6:
                printf("\nEnter a Postfix expression: ");
                scanf("%s", &postfixexp);
                PostfixToInfix(postfixexp);
                break;

            default:
                printf("Enter a valid choice.");
        }
    } while (choice != 7);
    return 0;
}
