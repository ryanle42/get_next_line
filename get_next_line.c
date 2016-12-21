#include "get_next_line.h"
#include <sys/stat.h> 
#include <fcntl.h>

t_list      *make_head(t_list *head)
{   
    if (head == NULL)
    {
        head = (t_list *)malloc(sizeof(t_list));
        head->pos = 0;
        head->file = 0;
        head->next = NULL;
    }
    return (head);
}

t_list      *get_node(t_list **head, const int fd)
{
    t_list *current;

    current = *head;
    while (current)
    {
        if (current->file == fd)
            return (current);
        current = current->next;
    }
    current = (t_list *)malloc(sizeof(t_list));
    current->file = fd;
    current->pos = 0;
    current->next = NULL;
    return (current);
}

int get_next_line(const int fd, char **line)
{
    int i;
    int j;
    static t_list *head;
    t_list *current;
    char *buffer;

    head = make_head(head);
    current = get_node(&head, fd);
    i = current->pos;
    buffer = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
    read(fd, buffer, BUFF_SIZE);
    while (buffer[i] && buffer[i] != '\n')
        i++;
    *line = (char *)malloc(sizeof(char) * (i - current->pos));
    i = current->pos;
    j = 0;
    while (buffer[i] && buffer[i] != '\n')
    {
        (*line)[j] = buffer[i];
        i++;
        j++;
    }
    current->pos += j;
    //printf("pos: %i\n", j);
    (*line)[j] = '\0';
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
    fd2 = open("file2", O_RDONLY);
    get_next_line(fd2, &ptr);
    printf("%s\n", ptr);
    get_next_line(fd2, &ptr);
    printf("%s\n", ptr);
    get_next_line(fd, &ptr);
    printf("%s\n", ptr);
    return (1);
}