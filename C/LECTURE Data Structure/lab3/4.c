#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int g_chmap[64];
int cmp(const void *a, const void *b)
{
    char tmpa = *(char *)a;
    char tmpb = *(char *)b;
    if (g_chmap[tmpb] == g_chmap[tmpa])
    {
        return tmpa - tmpb;
    }
    return g_chmap[tmpb] - g_chmap[tmpa];
}
char *frequencySort(char *s)
{
    int slen = strlen(s);
    memset(g_chmap, 0, sizeof(int) * 256);
    for (int i = 0; i < slen; i++)
    {
        g_chmap[s[i]]++;
    }
    qsort(s, slen, sizeof(char), cmp);
    return s;
}

int main()
{
    char s[1000];
    scanf("%s", s);

    char *result = frequencySort(s);
    printf("%s\n", result);

    return 0;
}