#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>



int is_safe(int *bord, size_t col, size_t row)
{
    for(size_t i =0; i < col; i++)
    {
        if(bord[i] == row || bord[i] - i == row - col || bord[i] + i == row + col)
            return 0;
    }
    return 1;
}

void solve(int *bord, int col, int n)
{
    if(col == n)
    {
        for(size_t i = 0; i < col; i++)
        {
            if(i > 0)
            {
                printf(" ");
            }
            printf("%d", bord[i]);
        }
        printf("\n");
    }
    for(size_t row = 0; row < n; row++)
    {
        if(is_safe(bord, col, row))
        {
            bord[col] = row;
            solve(bord, col+1, n);
        }
    }
}




int main(int ac, char **av)
{
    if(ac == 2 && av[1][0])
    {
        int n = atoi(av[1]);
        int *bord = malloc(n * sizeof(int));
        solve(bord, 0, n);
        free(bord);
    }
    return 0;
}