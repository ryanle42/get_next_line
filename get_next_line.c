#include "get_next_line.h"
#include <sys/stat.h> 
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

/*
b_list      *make_head(b_list *head)
{   
    if (!head)
    {
        head = (b_list *)malloc(sizeof(b_list));
        head->file = -1;
        head->extra = "\0";
        head->next = NULL;
    }
    return (head);
}
*/
b_list     *find_make_node(b_list *head, const int fd)
{
    b_list *current;

    if (!head)
    {
        head = (b_list *)malloc(sizeof(b_list));
        head->file = -1;
        head->extra = "\0";
        head->next = NULL;
        return (head);
    }
    current = head;
    while (current->next)
    {
        current = current->next;
        if (current->file == fd)
            return (current);
    }
    current->next = (b_list *)malloc(sizeof(b_list));
    current = current->next;
    current->file = fd;
    current->extra = "\0";
    current->next = NULL;
    return (current);
}

int         check_newline(b_list *current, char **total)
{
    int i;

    i = 0;
    if (!current->extra[i])
    {
        (*total)[i] = '\0';
        return (0);
    }
    while (current->extra[i])
    {
        if (current->extra[i] == '\n')
        {
            (*total)[i] = '\0';
            i++;
            current->extra = ft_copystr(current->extra + i);
            return (1); 
        }
        (*total)[i] = current->extra[i];
        i++;
    }
    (*total)[i] = '\0';
    return (0);
}

char        *buff_it(const int fd, b_list *current, char *str)
{
    char *buffer;
    char *total;
    char *cpy;
    int t;
    int i;

    t = 1000;
    total = (char *)malloc(sizeof(char) * ft_strlen(current->extra) + 1);
    if (!(check_newline(current, &total))) // Set to stored bytes
    {
        while (buffer[i] != '\n' && buffer[i])                         // Keep reading until hit new line
        {
            i = 0;
            cpy = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
            buffer = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
            current->ret = read(fd, buffer, BUFF_SIZE);
            while (buffer[i] && buffer[i] != '\n')
            {
                cpy[i] = buffer[i];
                i++;
            }
            total = ft_str_append(total, cpy);
        }
        current->extra = ft_copystr(buffer + i + 1); // Store bytes if read over newline
    }
    return (total);
}

int get_next_line(const int fd, char **line)
{
    static b_list *head;
    b_list *current;
    char *str;

    if (!head)
        head = find_make_node(head, fd);                // Make head node if necessary
    current = find_make_node(head, fd);                 // Find or make node for file
    *line = buff_it(fd, current, str);                  // Read file and store result
    if (current->ret > 0)
        return (1);
    return (current->ret);
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
    get_next_line(fd, &ptr);
    printf("%s\n", ptr);    
    get_next_line(fd, &ptr);    
    printf("%s\n", ptr);
 /*   
    fd2 = open("file2", O_RDONLY);
    
    get_next_line(fd2, &ptr);
    printf("%s\n", ptr);
    
    get_next_line(fd2, &ptr);
    printf("%s\n", ptr);
    
    get_next_line(fd, &ptr);
    printf("%s\n", ptr);*/
    return (1);
}