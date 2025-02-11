#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAXZEILENLENG 1028

typedef struct listelement {
    char *fn;
    int zn;
    char *content;
    struct listelement *next;
}n_list;

typedef struct listconnect {
    n_list *head;
    n_list *tail;
}n_listconnect;


void fun(n_listconnect mylist[], char *fn, int zn, char *content)
{
    n_list *p = (n_list *)(malloc(sizeof(n_list)));
    p->content = strdup(content);
    p->zn = zn;
    p->fn = fn;
    p->next = NULL;
    size_t linelen = strlen(content);
    
    if(mylist[linelen].head == NULL){
        mylist[linelen].head = p;
    }
    else{
        mylist[linelen].tail->next = p;
    }
    mylist[linelen].tail = p;
}

void readlist(n_listconnect mylist[], char *fn)
{
    FILE *f;
    char line[MAXZEILENLENG];
    if((f = fopen(fn, "r")) == NULL){
        fprintf(stderr, ": Can't open %s: %s\n", fn,
            strerror(errno));
    exit(EXIT_FAILURE);
    }

    for(int i = 1; fgets(line, sizeof(line), f);i++){

    fun(mylist, fn, i, line);
    }
    if(ferror(f)){
        fprintf(stderr, "cant read %s: %s\n", fn, strerror(errno));
        exit(EXIT_FAILURE);
    }
    fclose(f);
}

void ausgabe(n_listconnect mylist[])
{
    for(int i = 0; i < MAXZEILENLENG; i++)
    {
        if(mylist[i].head == NULL){ continue;}
        for(n_list *p; p->next != NULL; p = p->next)
        {
            printf("%s:%d: %s", p->fn, p->zn, p->content);
        }
    }
}



int main(int argc, char *argv[])
{
    //für jede fucking längenmöglichkeit einer Zeile eine Liste
    n_listconnect mylist[MAXZEILENLENG];
    for(int i = 0; i < MAXZEILENLENG; i++){
        mylist[i].head = NULL;
        mylist[i].tail = NULL;
    }
    for (int i = 1; i < argc; i++) {
        readlist(mylist, argv[i]);
      }
      ausgabe(mylist);
}

