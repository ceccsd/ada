#include<stdio.h>

int set[10], x[10];
int n, sum;

void subset(int k, int s)
{
    if(s == sum)
    {
        printf("{ ");
        for(int i = 1; i < k; i++)
        {
            if(x[i] == 1)
                printf("%d ", set[i]);
        }
        printf("}\n");
        return;
    }

    if(k > n || s > sum)
        return;

    x[k] = 1;
    subset(k + 1, s + set[k]);

    x[k] = 0;
    subset(k + 1, s);
}

int main()
{
    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter elements:\n");
    for(int i = 1; i <= n; i++)
        scanf("%d",&set[i]);

    printf("Enter required sum: ");
    scanf("%d",&sum);

    printf("Subsets are:\n");

    subset(1,0);

    return 0;
}
