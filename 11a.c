#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int a[10000], temp[10000], n;

void input()
{
    printf("Enter size: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
        a[i]=rand()%1000;
}

void merge(int l,int m,int r)
{
    int i=l,j=m+1,k=l;

    while(i<=m && j<=r)
    {
        if(a[i]<a[j])
            temp[k++]=a[i++];
        else
            temp[k++]=a[j++];
    }

    while(i<=m)
        temp[k++]=a[i++];

    while(j<=r)
        temp[k++]=a[j++];

    for(i=l;i<=r;i++)
        a[i]=temp[i];
}

void sort(int l,int r)
{
    if(l<r)
    {
        int m=(l+r)/2;

        sort(l,m);
        sort(m+1,r);

        merge(l,m,r);
    }
}

int main()
{
    input();

    clock_t start=clock();
    sort(0,n-1);
    clock_t end=clock();

    printf("\nSorted Array:\n");
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);

    printf("\nTime=%lf ns",(double)(end-start)/CLOCKS_PER_SEC*1000000000);

    return 0;
}
