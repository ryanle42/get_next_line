#include "get_next_line.h"
#include <sys/stat.h> 
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

b_list      *make_head(b_list *head)
{   
    if (head == NULL)
    {
        head = (b_list *)malloc(sizeof(b_list));
        head->pos = 0;
        head->file = 0;
        head->next = NULL;
    }
    return (head);
}

char        *buff_it(const int fd, b_list *current)
{
    char *buffer;
    char *total;
    char *cpy;
    int nl;
    int i;

    nl = 0;
    buffer = (char *)malloc(sizeof(char) * current->pos);
    total = NULL;
    read(fd, buffer, -5);
    while (!nl)
    {
        i = 0;
        cpy = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
        buffer = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
        read(fd, buffer, BUFF_SIZE);
        while (buffer[i])
        {
            if (buffer[i] == '\n')
            {
                nl = 1;
                break;
            }
            cpy[i] = buffer[i];
            i++;
        }
        if (!total)
            total = cpy;
        else
            total = ft_strjoin(total, cpy);
        printf("buff: %s\n", total);
        current->pos += i;
        if (i < BUFF_SIZE)
            return (total);
    }
    return (total);
}

b_list      *get_node(b_list **head, const int fd)
{
    b_list *current;

    current = *head;
    while (current)
    {
        if (current->file == fd)
            return (current);
        current = current->next;
    }
    current = (b_list *)malloc(sizeof(b_list));
    current->file = fd;
    current->pos = 0;
    current->next = NULL;
    return (current);
}

int get_next_line(const int fd, char **line)
{
    static b_list *head;
    b_list *current;

    head = make_head(head);
    current = get_node(&head, fd);
    *line = buff_it(fd, current);
    return (1);
}

int main()
{
    char *ptr;
    int fd;
    int fd2;

    fd = open("file", O_RDONLY);

    get_next_line(fd, &ptr);
    printf("%s\n", ptr);

    get_next_line(fd, &ptr);
    printf("%s\n", ptr);
    
    /*fd2 = open("file2", O_RDONLY);
    
    get_next_line(fd2, &ptr);
    printf("%s\n", ptr);
    
    get_next_line(fd2, &ptr);
    printf("%s\n", ptr);
    
    get_next_line(fd, &ptr);
    printf("%s\n", ptr);
    */return (1);
}