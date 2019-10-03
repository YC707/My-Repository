#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *fp;
    char ch, filename[10];
    scanf("%s", filename);
    if((fp = fopen(filename, "w")) == NULL)
    {
        printf("打不开文件");
        exit(0);
    }
    ch = getchar();
    ch = getchar();
    while(ch != '!')
    {
        fputc(ch, fp);
        putchar(ch);
        ch = getchar();
    }
    fclose(fp);
    putchar(10);
    return 0;
    
}