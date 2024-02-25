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

int main(){

    t_list **p_test_arr = (t_list**)malloc(sizeof(t_list*));
    int a = 5;

    ft_list_push_front(p_test_arr, "test data");
    ft_list_push_front(p_test_arr, &a);

    return (0);
}
