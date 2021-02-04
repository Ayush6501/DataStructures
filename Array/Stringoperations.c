#include <stdio.h>

void accept(char str[20])
{
    printf("\nEnter the string: ");
    scanf("%s", str);
}

void display(char str[20])
{
    printf("\nThe String is: ");
    printf("%s", str);
}

int length(char str[20])
{
    int i = 0;
    while(str[i] != '\0')
        i++;
    return i;
}

void copy(char str1[20], char str2[20])
{
    int i = 0;
    while(str1[i] != '\0')
    {
        str2[i]=str1[i];
        i++;
    }
    str2[i] = '\0';
    printf("\nThe copied String is: %s", str2);
}

void concate(char str1[20], char str2[20])
{
    int i=0,j;
    int l = length(str1);
    while(str2[i] != '\0')
    {
        str1[l]=str2[i];
        i++;
        l++;
    }
    str1[l] = '\0';
    printf("\nConcatenated String is : %s", str1);
}

void reverse(char str1[20], char str2[20])
{
    int l = length(str1), i = 0;
    while(str1[i] != '\0')
    {
        str2[i] = str1[l-i-1];
        i++;
    }
    str2[l] = '\0';
}

void substring(char str1[20], char str2[20])
{
    int flag, count = 0;
    int len1 = length(str1);
    int len2 = length(str2);
    
    for(int i = 0; i < len1; i++)
    {
        if (str1[i] == str2[0])
        {
            for (int j = 0; j < len2; j++)
            {
                if(str1[i] == str2[j])
                {
                    i++;
                }
            }
            i -= len2;
            count ++;
        }
    }
    if(count > 0)
    {
        printf("The substring is present and has occurred %d times", count);
    }
    else
    {
        printf("Substring not available");
    }
    
}

int LengthPointer(char *ptr)
{
    int count = 0;
    while((*ptr) != '\0')
    {
        count++;
        ptr++;
    }
    return count;
}

void CopyPointer(char *ptr1, char *ptr2)
{
    while(*ptr1 != '\0')
    {
        *ptr2++ = *ptr1;
    }
}

void ConcatenatePointer(char *ptr1, char *ptr2)
{
    int i=0,j;
    int l = LengthPointer(ptr1);
    while(*ptr1 != '\0')
    {
        ptr1++;
    }
    while(*ptr2 != '\0')
    {
        *ptr1 = *ptr2;
        ptr2++;
        ptr1++;
    }
    *ptr1 = '\0';
}

int main()
{
    char s1[20];
    char s2[20];
    int ch;
    int l;
   do
   {
        printf("\n***** MENU *****");
    printf("\n1.Length \n2.Copy \n3.Concatenate \n4.Reverse \n5.Substring \n6.Length using pointer \n7.Copy using pointer\n8.Concatenate using pointer");
    printf("\nEnter your choice: ");
    scanf("%d", &ch);
    switch(ch)
    {
        case 1:
            
            accept(s1);
            display(s1);
            l = length(s1);
            printf("\nLength of string is: %d", l);
            break;
            
        case 2:
            accept(s1);
            copy(s1, s2);
            break;
            
        case 3:
            accept(s1);
            accept(s2);
            concate(s1, s2);
            break;
        
        case 4:
            accept(s1);
            reverse(s1, s2);
            printf("\nThe reversed String is : %s", s2);
            break;

        case 5:
            accept(s1);
            accept(s2);
            substring(s1, s2);
            
        case 6:
            accept(s1);
            l = LengthPointer(s1);
            printf("\nLength of string is: %d", l);
            break;
            
        case 7: 
            accept(s1);
            
            CopyPointer(s1, s2);
            printf("Copied string is: %s ", s2);
            break;
            
        case 8:
            accept(s1);
            accept(s2);
            ConcatenatePointer(s1, s2);
            printf("\n Concatenated String is : %s", s1);
            break;
    }
   } while (ch != 9);
   
    return 0;
}
