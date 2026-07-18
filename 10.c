#include <stdio.h>
#include<stdlib.h>
#include <time.h>

void swap(int *a,int *b)
{
int temp;
temp=*a;
*a=*b;
*b=temp;
}

int partition(int a[],int left,int right)
{
int p,i,j;
p=a[left];
i=left;
j=right+1;
while(i<=j)
{
do
 i++;
 while(a[i]<=p) ; //find elt>p
do
 j--;
while(a[j]>p); //find elt<p
if(i<j)
swap(&a[i],&a[j]);
}
swap(&a[left],&a[j]); //swap pivot and a[j]
return j;
}

void quicksort(int a[],int left,int right)
{
int s;
if(left<right)
{
s=partition(a,left,right);
quicksort(a,left,s-1);
quicksort(a,s+1,right);
}
}

int main()
{
int n;
int *a;
printf("Enter the number of elements:");
scanf("%d", &n);

a = (int *)malloc((n+1) * sizeof(int)); // n+1 to safely hold the sentinel

for (int i = 0; i < n; i++)
{
a[i] = rand() % 1000;
}
printf("randomly generated elements are:\nArray is:");
for (int i = 0; i < n; i++)
{
printf("%d\t ", a[i]);
}
printf("\n");
a[n]=9999; // sentinel value, now safely within allocated memory

clock_t start = clock();
quicksort(a,0,n-1);
clock_t end = clock();

double duration = ((double)(end - start)) / CLOCKS_PER_SEC*1000;

printf("Sorted array is:\n");
for (int i = 0; i < n; i++)
{
printf("%d\t ", a[i]);
}
printf("\n");
printf("\nTime for sorting is %f milli seconds\n", duration);
free(a);
return 0;
 }
