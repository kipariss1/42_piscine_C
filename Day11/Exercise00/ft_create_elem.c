#include "ft_list.h"
#include <stdlib.h>

t_list* ft_create_elem(void *data){

    t_list *new_list_el = (t_list*)malloc(sizeof(t_list));
    new_list_el->data = data;
    new_list_el->next = NULL;

    return new_list_el;
}

int main(){

    int a = 18;
    char *b = "this is one type of data";
    t_list* res = ft_create_elem((char*)b);
    res->next = ft_create_elem((int*)&a);

    return (0);
}
