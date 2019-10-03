#include<stdio.h>
void copy_string1(char *a, char *b)
{
    for(; *a != '\0'; *a++, *b++)
        *b = *a;
    *b = '\0';
}

void copy_string2(char *a, char *b)
{
    while((*b = *a) != '\0')
    {
        a++;
        b++;
    }
}
void copy_string3(char *a, char *b)
{
    while((*b++ = *a++) != '\0');
}
void copy_string4(char *a, char *b)
{
    while(*b++ = *a++);
}
int main()
{
    char *a = "I am a boy!";
    char *b;
    copy_string4(a, b);
    printf("%s", b);
}