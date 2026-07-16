#include <stdio.h>
#include <stdlib.h>



void power(int *nums, int target, int size, int *subset, int index, int sub_size, int cur_some)
{
    if (index == size)
    {
        if (target == cur_some)
        {
            for (int i = 0; i < sub_size; i++)
            {
                printf("%d", subset[i]);
                if (i != sub_size - 1)
                    printf (" ");
            }
            printf("\n");
        }
        return;
    }
    power(nums, target, size, subset, index + 1, sub_size, cur_some);
    subset[sub_size] = nums[index];
    power(nums, target, size, subset, index + 1, sub_size + 1, cur_some + nums[index]);
}

int main(int ac, char **av)
{
    if (ac < 2 ) 
        return (1);
    int target = atoi(av[1]);

    int size = ac - 2;

    int *nums = malloc(sizeof(int) * size);
    if (!nums)
        return (1);
    
    for (int i = 0; i < size; i++)
    {
        nums[i] = atoi(av[i + 2]);
    }

    int *subset = malloc(sizeof(int) * size);
    if (!subset)
    {
        free(nums);
        return (1);
    }

    power(nums, target, size, subset, 0, 0 , 0);
    free(subset);
    free(nums);
    return (0);
}