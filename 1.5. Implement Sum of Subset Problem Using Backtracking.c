#include <stdio.h>

int a[100], subset[100];
int result[1000][100], len[1000];
int count = 0, n, target;

void backtrack(int index, int sum, int k)
{
    if (index == n)
    {
        if (sum == target)
        {
            len[count] = k;
            for (int i = 0; i < k; i++)
                result[count][i] = subset[i];
            count++;
        }
        return;
    }

    // Include current element
    subset[k] = a[index];
    backtrack(index + 1, sum + a[index], k + 1);

    // Exclude current element
    backtrack(index + 1, sum, k);
}

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    scanf("%d", &target);

    backtrack(0, 0, 0);

    if (count == 0)
    {
        printf("-1");
    }
    else
    {
        for (int i = count - 1; i >= 0; i--)
        {
            for (int j = 0; j < len[i]; j++)
                printf("%d ", result[i][j]);   // trailing space required
            printf("\n");
        }
    }

    return 0;
}
