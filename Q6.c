int dequeue[100005];
int front=0;
int back=-1;

int getfront()
{
    return front;
}

int getback()
{
    return back;
}
void push(int val)
{
    back++;
    dequeue[back]=val;
}

void pop()
{
    front++;
}

int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    *returnSize=0;
    int n=numsSize;
    int *ans = (int*) calloc(numsSize, sizeof(int));
    int l=k-1;
    
    for(int i=0;i<=l;i++)
        push(i);
    int idx=0;
    while(l<n)
    {
        int temp=getfront();
        int temp1=getback();
        int mx=-1e9;
        
        for(int j=temp;j<=temp1;j++)
        {
            mx=max(mx,nums[j]);
        }
        ans[idx++]=mx;
        l++;a
        push(l);
        pop();
        (*returnSize)++;
    }
    front=0;
    back=-1;
    return ans;
}