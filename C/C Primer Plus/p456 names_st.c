//names_st.c

#include <stdio.h>
#include "p456 names_st.h"

void get_names(names * pn){
    int i=0;

    printf("please enternyour first name:");
    fgets(pn->first,SLEN,stdin);
    while ((pn->first[i]!='\n') && (pn->first[i]!='\0'))
    {
        i++;
    }

    if (pn->first[i]=='\n')
    {
        pn->first[i]='\0';
    }
    else
    {
        while(getchar()!='\n'){
            continue;
        }
    }

    printf("please enternyour last name:");
    fgets(pn->last,SLEN,stdin);
    while ((pn->last[i]!='\n') && (pn->last[i]!='\0'))
    {
        i++;
    }
    
    if (pn->last[i]=='\n')
    {
        pn->last[i]='\0';
    }
    else
    {
        while(getchar()!='\n'){
            continue;
        }
    }
}

void show_names(const names*pn){
    printf("%s %s\n",pn->first,pn->last);
}