#include <stdio.h>
#include <stdlib.h>
int type(const char *fileName);
/*argc 是argument count的缩写，表示传入main函数中的参数个数，包括这个程序本身。
argv 是 argument vector的缩写，表示传入main函数中的参数列表，其中argv[0]表示这个程序的名字。
在上面两个名词的解释中提到“这个程序”，所谓的“这个程序”就是包含main函数的程序。*/
int main(int argc, char *argv[])
{
    int i;
    if (argc < 2)
    {
        printf("the syntax of command is incorrect.\n");
        exit(0);
    }
    for (i = 1; i < argc; i++)
    {
        if (type(argv[i]) == 0)
        {
            printf("file %s cannot be found.\n", argv[i]);
        }
    }
    return 0;
}
int type(const char *fileName)
{
    int val = 1;
    FILE *fp;
    char ch;
    if ((fp = fopen(fileName, "r")) == NULL)
    {
        val = 0;
    }
    else
    {
        printf("contents of file %s:\n", fileName);
        while (ch = fgetc(fp) != EOF)
        {
            fputc(ch, stdout);
        }
        fclose(fp);
    }
    return val;
}