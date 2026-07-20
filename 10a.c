#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int a[10000], n;

void input()
{
    printf("Enter size: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
        a[i]=rand()%1000;
}

void swap(int i,int j)
{
    int t=a[i];
    a[i]=a[j];
    a[j]=t;
}

int partition(int l,int r)
{
    int pivot=a[l];
    int i=l,j=r;

    while(i<j)
    {
        while(a[i]<=pivot) i++;
        while(a[j]>pivot) j--;

        if(i<j)
            swap(i,j);
    }

    swap(l,j);

    return j;
}

void quick(int l,int r)
{
    if(l<r)
    {
        int p=partition(l,r);

        quick(l,p-1);
        quick(p+1,r);
    }
}

int main()
{
    input();

    clock_t start=clock();
    quick(0,n-1);
    clock_t end=clock();

    printf("\nSorted Array:\n");
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);

    printf("\nTime=%lf ns",(double)(end-start)/CLOCKS_PER_SEC*1000000000);

    return 0;
}
