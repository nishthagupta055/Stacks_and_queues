int top=-1;
int stack[100005];

bool isempty()
{
    if(top<=-1)
        return true;
    else
        return false;
}

int gettop()
{
    return stack[top];
}

void pop()
{
    top--;
}

void push(int val)
{
    top++;
    stack[top]=val;
}
int largestRectangleArea(int* heights, int heightsSize){
    
    int prevsmaller[heightsSize],nextsmaller[heightsSize];
    prevsmaller[0]=-1;
    push(0);
    for(int i=1;i<heightsSize;i++)
    {
        while(!isempty() && heights[gettop()]>=heights[i])
        {
            pop();
        }
        if(isempty())
        {
            prevsmaller[i]=-1;
        }
        else
        {
            prevsmaller[i]=gettop();
        }
        push(i);
    }
    top=-1;
    push(heightsSize-1);
    nextsmaller[heightsSize-1]=heightsSize;
    for(int i=heightsSize-2;i>=0;i--)
    {
        while(!isempty() && heights[gettop()]>=heights[i])
        {
            pop();
        }
        if(isempty())
        {
            nextsmaller[i]=heightsSize;
        }
        else
        {
            nextsmaller[i]=gettop();
        }
        push(i);
    }
    int ans=0;
    for(int i=0;i<heightsSize;i++)
    {
         if((nextsmaller[i]-prevsmaller[i]-1)*heights[i]>ans)
            ans=(nextsmaller[i]-prevsmaller[i]-1)*heights[i];
    }
    top=-1;
    return ans;
}