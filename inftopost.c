#include<stdio.h> 
#include<stdlib.h> 
#include<ctype.h> 
#include<string.h> 
# define MAX 30 
 
char stack[MAX]; 
int top = -1; 
int count1=0,count2=0; 
 
void push(char x) 
{ 
    stack[++top] = x; 
} 
 
char pop() 
{ 
    if(top == -1) 
        return -1; 
    else 
        return stack[top--]; 
} 
 
int precedence(char x) 
{ 
    if(x == '(') 
        return 0; 
    if(x == '+' || x == '-') 
        return 1; 
    if(x == '*' || x == '/') 
        return 2; 
    return 0; 
} 
 
int main() 
{ 
    int j=0; 
    char exp[100]; 
    char output[100]; 
    char *e, x; 
    printf("Enter the expression : "); 
    scanf("%s",exp); 
    printf("\n"); 
    e = exp; 

    for(int i=0;i<strlen(exp);i++) 
    { 
        if(exp[i]=='(') 
            count1++; 
        else if(exp[i]==')') 
            count2++; 
    } 
 
    while(*e != '\0') 
    { 
        if(isalnum(*e)) 
            output[j++]=*e; 
        else if(*e == '(') 
            push(*e); 
        else if(*e == ')') 
        { 
            while((x = pop()) != '(') 
                output[j++]=x; 
        } 
        else 
        { 
            while(precedence(stack[top]) >= precedence(*e)) 
                output[j++]=pop(); 
            push(*e); 
        } 
        e++; 
    } 
 
    while(top != -1) 
        output[j++]=pop(); 
 
    if(count1 == count2) 
        printf("%s",output); 
    else  
    {  
        printf("Invalid expression\n"); 
        exit(0); 
    } 
    return 0; 
}