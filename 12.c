#include<stdio.h>
#include<stdlib.h>
int place(int);
int x[10];
int main()
{
int i, j, n, k, count = 0;
printf("\n\n********** N-QUEEN PROBLEM ***********\n\n");
printf("Enter the number of elements: ");
scanf("%d", &n);
if(n==0||n==2||n==3)
{
printf("\n\nNo solution\n");
printf("\n\n********** ******************* ***********");
exit(0);
}
k=1;
x[k]=0;
while(k)
{
x[k] = x[k] + 1;
while(x[k] <= n && !place(k))
x[k] = x[k] + 1;
if(x[k] <= n)
{
if(k == n)
{
printf("\nSolution %d\n\n", ++count);
for(i=1; i<=n; i++)
{
for(j=1; j<x[i]; j++)
printf("*\t");
printf("Q\t");
for(j=x[i]+1; j<=n; j++)
printf("*\t");
printf("\n");
}
}
else
{
k = k + 1;
x[k] = 0;
}
}
else
k = k-1;
}
printf("\n\n********** ******************* ***********");
return 0;
}
int place(int p)
{
int i;
for(i=1; i<=p-1; i++)
{
if(x[i] == x[p]||abs(i-p) == abs(x[i]-x[p]))
return 0;
}
return 1;
}
