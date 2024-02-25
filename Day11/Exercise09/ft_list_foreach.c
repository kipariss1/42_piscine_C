#include "ft_list.h"
#include <stdlib.h>

void replace_first_char(char *str){
    str[0] = '0';
}

void ft_list_foreach(t_list *begin_list, void (*f)(void*)){
    t_list *curr;
    for (curr=begin_list; curr->next!=0x00; curr=curr->next){
        f(curr->data);
    }
}

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

    t_list **list_array = (t_list**)malloc(sizeof(t_list));
    ft_list_push_back(list_array, "1 test data");
    ft_list_push_back(list_array, "2 test data");
    ft_list_push_back(list_array, "3 test data");
    ft_list_push_back(list_array, "4 test data");
    ft_list_push_back(list_array, "5 test data");

    ft_list_foreach(*list_array, &replace_first_char);

    return (0);
}