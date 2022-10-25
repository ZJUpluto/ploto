#include <stdio.h>
void copy(char *src, char *dst)
{
    int c=(*src++ =*dst++);

}

int main()
{
char string[] = {'a', 'b', 'c', '\0'};
char *string1 = string+10;
//printf("%p",string);
//printf("%p",string1);
copy(string, string1);
printf("%s", string);
return 0;
}