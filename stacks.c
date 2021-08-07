#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int stack[256];
int count=0;

void push(int x)
{
    stack[count++]=x;
}
int is_empty() {
    
    return count == 0;
}
int pop() {
    
    if(is_empty()) {
        return -1;
    }
    int res=stack[count-1];
    count--;
    return res;
}

int peek() {
    
    if(is_empty()) {
        
        return -1;
    }
    
    return stack[count - 1];
}

int main()
{
    for(int i = 0; i < 5; i++) {
        push(i);
    }
    
    
    while(!is_empty()) {
        printf("%d ", pop());
    }

    return 0;
}
