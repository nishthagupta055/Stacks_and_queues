typedef struct {
    int front;
    int back;
    int *a;
} queue;

queue* generatequeue() {
    queue *obj = (queue *)malloc(sizeof(queue));
    obj->a = (int*)calloc(100, sizeof(int));
    obj->front = 0;
    obj->back = -1;
    return obj;
}
int top(queue *q){
    return q->a[q->front];
}
int move(queue *q) {
    return q->a[q->front++];
}
void push(queue *q, int x) {
    q->a[++q->back] = x;
}

int isempty(queue *q) {
    return q->front > q->back;
}
typedef struct {
    queue *q1;
    queue *q2;
} MyStack;

MyStack* myStackCreate() {
     MyStack *obj = (MyStack *)malloc(sizeof(MyStack));
    obj->q1 = generatequeue();
    obj->q2 = generatequeue();
    return obj;
}



void myStackPush(MyStack* obj, int x) {
  push(obj->q2, x);
    int res;
    while(!isempty(obj->q1)) {
        res = move(obj->q1);
        push(obj->q2, res);
    }
    queue *temp = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = temp;
}

int myStackPop(MyStack* obj) {
  if(isempty(obj->q1)){
        return -1;
    }else{
        return move(obj->q1);
    }
}
int myStackTop(MyStack* obj) {
   if(isempty(obj->q1)){
        return -1;
    }else{
        return top(obj->q1);
    }
}

bool myStackEmpty(MyStack* obj) {
  return isempty(obj->q1);
}

void myStackFree(MyStack* obj) {
    free(obj);
}
