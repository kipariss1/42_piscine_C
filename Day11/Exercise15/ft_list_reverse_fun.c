#include "ft_list.h"
#include <stdlib.h>

void ft_reverse_fun(t_list *begin_list){
    t_list *last_changed_with = 0x00;   // node, that was changed from other half of the list
    for (t_list *curr_outer = begin_list; curr_outer->next!=last_changed_with; curr_outer=curr_outer->next){
        t_list *curr_inner;
        for (curr_inner = begin_list; curr_inner->next!=last_changed_with; curr_inner=curr_inner->next){}
        void *temp_data = curr_outer->data;
        curr_outer->data = curr_inner->data;
        curr_inner->data = temp_data;
        last_changed_with = curr_inner;
        if (curr_outer->next==curr_inner){
            break;
        }
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

    t_list **list_array = (t_list**)malloc(sizeof(t_list*));

    char a[] = "1 test data";
    char b[] = "2 test data";
    char c[] = "3 test data";
    char d[] = "4 tets data";
    char e[] = "5 test data";

    ft_list_push_back(list_array, a);
    ft_list_push_back(list_array, b);
    ft_list_push_back(list_array, c);
    ft_list_push_back(list_array, d);
    ft_list_push_back(list_array, e);

    ft_reverse_fun(*list_array);

    return (0);
}
