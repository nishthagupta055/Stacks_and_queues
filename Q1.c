#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char stack[100005];
int top=-1;
//Function to find the length of the string
int strlength(char * s)
{
    int size=0;
    while(s[size]!='\0')
    {
        size++;
    }
    return size;
}
//Function to push element in stack
void push(char c)
{
    top++;
    stack[top]=c;
}
//Function to pop element from stack
void pop()
{
    top--;
}
//Function to check whether stack is empty or not
bool isempty()
{
    if(top==-1)
    return true;
    else
    return false;
}
//Function to get top element of stack
int gettop()
{
    return stack[top];
}
//Function to check whether string is balanced or not
bool isBalanced(char * s){
    
    int length = strlength(s);
    for(int i = 0; i < length ; i++){
        if(s[i] == '{' || s[i] == '[' || s[i] == '(')
        {
           push(s[i]);
        }
        else{
            //If the top of stack is same as the character present at ith position then pop else return false
            if(isempty())
            return false;
                if(s[i]==')')
                {
                    if(gettop()!='(')
                        return false;
                    else
                        pop();
                }
                else if(s[i]=='}')
                {
                    if(gettop()!='{')
                        return false;
                    else
                        pop();
                }
                else
                {
                    if(gettop()!='[')
                        return false;
                    else
                        pop();
                }
            }
        }
    if(isempty()) 
    return true;
    else 
    return false;
}

int main()
{
    char str[100005];
  printf("Enter the String : ");
    scanf("%s",str);
    
    bool ans = isBalanced(str);
    
    if(ans == true){
        printf("true");
    }else{
        printf("false"); 
    }
    
    
}