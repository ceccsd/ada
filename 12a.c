#include<stdio.h>
#include<stdlib.h>

int n,queen[10];   // queen[row] = column

int safe(int row)
{
    for(int i = 1; i < row; i++)
    {
        if(queen[i] == queen[row] || abs(i-row) == abs(queen[i]-queen[row]))
            return 0;
    }
    return 1;
}

void solve(int row)
{
    for(int col = 1; col <= n; col++)
    {
        queen[row] = col;

        if(safe(row))
        {
            if(row == n)
            {
                printf("\nSolution:\n");

                for(int i = 1; i <= n; i++)
                {
                    for(int j = 1; j <= n; j++)
                    {
                        if(queen[i] == j)
                            printf("Q ");
                        else
                            printf("* ");
                    }
                    printf("\n");
                }
            }
            else
            {
                solve(row + 1);
            }
        }
    }
}

int main()
{
    printf("Enter number of queens: ");
    scanf("%d",&n);

    solve(1);

    return 0;
}
