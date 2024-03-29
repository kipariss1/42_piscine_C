#include "ft_list.h"
#include <stdlib.h>

void ft_list_push_back(t_list **begin_list, void *data){
    if (*begin_list==0){
        *begin_list = (t_list*)malloc(sizeof(t_list));
        (*begin_list)->data = data;
        return;
    }

    t_list *last; 
    for (last = *begin_list; last->next!=0x00; last = last->next){}

    t_list *new = (t_list*)malloc(sizeof(t_list));
    new->data = data;
    last->next = new;

}

int main(){

    t_list **p_test_array = (t_list**)malloc(sizeof(t_list*));

    int a = 3;

    ft_list_push_back(p_test_array, "this is data");
    ft_list_push_back(p_test_array, &a);

    return (0);
}
