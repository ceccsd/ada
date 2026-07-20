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

void selection()
{
    int i,j,min,temp;

    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
                min=j;
        }

        temp=a[i];
        a[i]=a[min];
        a[min]=temp;
    }
}

int main()
{
    input();

    clock_t start=clock();
    selection();
    clock_t end=clock();

    printf("\nSorted Array:\n");
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);

    printf("\nTime=%lf ns",(double)(end-start)/CLOCKS_PER_SEC*1000000000);

    return 0;
}
