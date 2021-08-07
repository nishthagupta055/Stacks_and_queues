#include <stdio.h>
#include<stdlib.h>

int queue[256];
int max_size;
int front = -1, back = -1;
void enqueue(int value) {
    if((front == 0 && back == 256 - 1) || ((back + 1) % 256 == front)) {
        return;
    }
     if(back == -1 || back == 256 - 1) {
       back = 0;
        if(front == -1)
            front++;
        
        queue[back] = value;
    }else {
      
        back++;
        queue[back] = value;
    }    
}

int dequeue() {
    if(front == -1) {
        return -1;
    }
    
  
    int res = queue[front];
    if(front == back) {
       front = back = -1;
    } else {
        front++;
        if(front == 256) {
            front = 0;
        }
    }
   return res;
}

int is_empty() {
    return front == -1;
}

int peek() {
    if(is_empty()) {
        return -1;
    }
    return queue[front];
}

int main() {
    
    
     for(int i = 0;  i < 20; i++) {
        if(i & 1) {
            dequeue();
        }
        enqueue(i + 1);
    }
    while(!is_empty()) {
        printf("%d ", dequeue());
    }
}