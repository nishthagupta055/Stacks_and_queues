typedef struct {
    int value;      
    int mn;
} MinStack;

int sz;
MinStack* minStackCreate() {
    MinStack *stack = (MinStack *)malloc(1000000 * sizeof(MinStack)); 
    sz = 0;
    return stack;
}

void minStackPush(MinStack* obj, int val) {
    obj[sz].value = val;
    if(sz==0)
    {
        obj[sz].mn = val;
    }
    else
    {
        obj[sz].mn = val < minStackGetMin(obj) ? val : minStackGetMin(obj);
    }
    sz++;
}

void minStackPop(MinStack* obj) {
  sz--;
}

int minStackTop(MinStack* obj) {
  return obj[sz-1].value;
}

int minStackGetMin(MinStack* obj) {
  return obj[sz-1].mn;
}

void minStackFree(MinStack* obj) {
  free(obj);
}