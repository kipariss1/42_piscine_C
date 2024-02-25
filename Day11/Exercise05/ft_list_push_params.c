#include "ft_list.h"
#include <stdlib.h>

void ft_list_push_front(t_list **begin_list, void *data){

    if (*begin_list == 0x00){
        *begin_list = (t_list*)malloc(sizeof(t_list));
        (*begin_list)->data = data;
        return;
    }

    t_list *old_head = *begin_list;

    t_list *new_head = (t_list*)malloc(sizeof(t_list));

    new_head->data = data;
    new_head->next = old_head;

    *begin_list = new_head;

    return;
}

t_list* ft_list_push_params(int ac, char **av){

    t_list **begin_list = (t_list**)malloc(sizeof(t_list*));

    for (int i=0; i<ac; i++){
        ft_list_push_front(begin_list, av[i]);
    }

    return *begin_list;
}

int main(int argc, char **argv){

    t_list *res = ft_list_push_params(argc, argv);

    return (0);
}
