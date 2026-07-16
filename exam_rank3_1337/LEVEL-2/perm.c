#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>



int checkdup(char *s)
{
    int char_seen[256] = {0};
    for (int i = 0; s[i]; i++)
    {
        if (char_seen[(unsigned char)s[i]])
            return 1;
        char_seen[(unsigned char)s[i]] = 1;
    }
    return 0;
}



void ft_swap(char *a, char *b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}
void sort_str(char *str)
{
    int i, j;
    for (i = 0; str[i]; i++)
    {
        for (j = i + 1; str[j]; j++)
        {
            if (str[i] > str[j])
            {
                ft_swap(&str[i], &str[j]);
            }
        }
    }
}

void permute(char *str, int start, int end)
{
    if (start == end)
    {
        puts(str);
        return;
    }
    for (int i = start; i <= end; i++)
    {
        ft_swap(&str[start], &str[i]);
        sort_str(str+start+1);
        permute(str, start + 1, end);
        sort_str(str+start+1);
        ft_swap(&str[start], &str[i]);
    }
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        sort_str(av[1]);
        permute(av[1], 0, strlen(av[1]) - 1);
    }
    return 0;
}