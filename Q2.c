#include<stdio.h>
#include<stdbool.h>
#define MAX 1000
int st[MAX]; 
int top=-1;
bool push(int x);
int pop();



bool push(int x)
	{if (top >= (MAX - 1)) {

		return false;
	}
	else {
		st[++top] = x;

		return true;
	}
}
int gettop()
{
	return st[top];
}

int pop()
{
	if (top < 0) {

		return 0;
	}
	else {
		int x = st[top--];
		return x;
	}
}
bool isEmpty()
{
	return (top < 0);
}

int prec(char c)
{
	if(c == '^')
		return 3;
	else if(c == '/' || c=='*')
		return 2;
	else if(c == '+' || c == '-')
		return 1;
	else
		return -1;
}

int main()
{

	char a[]="(1+((3-1)*(4/2)))";
	int l=sizeof(a)/sizeof(a[0]);
	char res[l];
	int k=-1;

	for(int i=0;i<l;i++)
	{
		if(a[i]>='1'&&a[i]<='9')
		{
			res[++k]=a[i];
		}
		else if(a[i]=='(')
		{
			push(a[i]);
		}
		else if(a[i]==')')
		{
			while(!isEmpty()&&gettop()!='(')
			{
				res[++k]=gettop();
				pop();
			}
			pop();
		}
		else
		{
			while(!isEmpty()&&prec(a[i])<=prec(gettop()))
			{
				res[++k]=gettop();
				pop();
			}
			push(a[i]);
		}
	}
	while(!isEmpty())
	{
		res[++k]=gettop();
		pop();

	}
	printf("%s",res);

	return 0;
}