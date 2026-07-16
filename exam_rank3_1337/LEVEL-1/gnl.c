#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>



#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif



char *ft_strdup(char *s)
{
    char *new = malloc(strlen(s) + 1);
    int i = -1;
    while(s[++i])
        new[i] = s[i];
    new[i] = '\0';
    return new;
}

char *gnl(int fd)
{
    static char buffer[BUFFER_SIZE];
    char line[70000];
    static int b_read;
    static int pos;
    int i = 0;
    if(fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
    while(1)
    {
        if(pos >= b_read)
        {
            b_read = read(fd, buffer, BUFFER_SIZE);
            pos = 0;
            if(b_read <= 0)
                break;
        }
        line[i++] =  buffer[pos++];
        if(line[i - 1] == '\n')
            break;
    }
    line[i] = '\0';
    if(i == 0)
        return NULL;
    return (ft_strdup(line));
}


// int main(int ac , char **av)
// {
// 	int fd = open(av[1], O_RDONLY);
// 	char *line ;
// 	while((line = gnl(fd)))
// 	{
// 			printf("%s", line);
// 	}

// }