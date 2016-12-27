
#include "get_next_line.h"
#include <stdio.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

  /*
    printf(ANSI_COLOR_RED     "This text is RED!"     ANSI_COLOR_RESET "\n");
    printf(ANSI_COLOR_GREEN   "This text is GREEN!"   ANSI_COLOR_RESET "\n");
    printf(ANSI_COLOR_YELLOW  "This text is YELLOW!"  ANSI_COLOR_RESET "\n");
    printf(ANSI_COLOR_BLUE    "This text is BLUE!"    ANSI_COLOR_RESET "\n");
    printf(ANSI_COLOR_MAGENTA "This text is MAGENTA!" ANSI_COLOR_RESET "\n");
    printf(ANSI_COLOR_CYAN    "This text is CYAN!"    ANSI_COLOR_RESET "\n");
*/

int main()
{
    char *ptr;
    int fd1;
    int fd2;
    int fd3;
    int fd4;
    int fd5;
    char color[100];
    int i;
    int j = 0;
    
    printf("How many lines to read?\n");
    fflush( stdout );
    scanf("%i", &i);
    while (color[0] != 'y' && color[0] != 'n')
    {
        printf("Color? y/n\n");
        fflush( stdout );
        scanf("%s", color);
    }
    fd1 = open("./files/file", O_RDONLY);
    fd2 = open("./files/file2", O_RDONLY);
    fd3 = open("./files/file3", O_RDONLY);
    fd4 = open("./files/file4", O_RDONLY);
    fd5 = open("./files/file5", O_RDONLY);
    
    if (color[0] == 'y')
        while (j < i)
        {
            printf(ANSI_COLOR_RED "------------------------------\n" ANSI_COLOR_RESET);
            printf(ANSI_COLOR_GREEN "Line %i\n" ANSI_COLOR_RESET, j + 1);
        
            printf(ANSI_COLOR_BLUE "\nret: %i\n" ANSI_COLOR_RESET, get_next_line(fd1, &ptr));
            printf(ANSI_COLOR_BLUE "File1: %s\n" ANSI_COLOR_RESET, ptr);
        
            printf(ANSI_COLOR_MAGENTA "\nret: %i\n" ANSI_COLOR_RESET, get_next_line(fd2, &ptr));
            printf(ANSI_COLOR_MAGENTA "File2: %s\n" ANSI_COLOR_RESET, ptr);
        
            printf(ANSI_COLOR_CYAN "\nret: %i\n" ANSI_COLOR_RESET, get_next_line(fd3, &ptr));
            printf(ANSI_COLOR_CYAN "File3: %s\n" ANSI_COLOR_RESET, ptr);
        
            printf(ANSI_COLOR_RED "\nret: %i\n" ANSI_COLOR_RESET, get_next_line(fd4, &ptr));
            printf(ANSI_COLOR_RED "File4: %s\n" ANSI_COLOR_RESET, ptr);

            printf(ANSI_COLOR_YELLOW "\nret: %i\n" ANSI_COLOR_RESET, get_next_line(fd5, &ptr));
            printf(ANSI_COLOR_YELLOW "File5: %s\n" ANSI_COLOR_RESET, ptr);
    
            j++;
        }
    if (color[0] == 'n')
        while (j < i)
        {
            printf("------------------------------\n");
            printf("Line %i\n", j + 1);
            
            printf("\nret: %i\n", get_next_line(fd1, &ptr));
            printf("File1: %s\n", ptr);
            
            printf("\nret: %i\n", get_next_line(fd2, &ptr));
            printf("File2: %s\n", ptr);
            
            printf("\nret: %i\n", get_next_line(fd3, &ptr));
            printf("File3: %s\n", ptr);
            
            printf("\nret: %i\n", get_next_line(fd4, &ptr));
            printf("File4: %s\n", ptr);
            
            printf("\nret: %i\n", get_next_line(fd5, &ptr));
            printf("File5: %s\n", ptr);
            
            j++;
        }
    
    return (1);
}