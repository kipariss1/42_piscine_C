#include "ft_list.h"
#include <stdlib.h>

void ft_list_sort(t_list **begin_list, int (*cmp)()){

    t_list *sorted_devider = 0x00;      // var to be devider of sorted part of list (j!=len-1-i)

    for (t_list *curr_outer = *begin_list; curr_outer->next!=0x00; curr_outer=curr_outer->next){
        t_list *curr_inner;
        for (curr_inner = *begin_list; curr_inner->next!=sorted_devider; curr_inner=curr_inner->next){
            if (cmp(curr_inner->data, curr_inner->next->data)>0){
                void *temp_data = curr_inner->data;
                curr_inner->data = curr_inner->next->data;
                curr_inner->next->data = temp_data;
            }
        }
        sorted_devider = curr_inner;
    }

}

int compare_func(char *s1, char *s2){
    return *s1-*s2;
}

void replace_to_zero(char *digit){
    char replacement = '0';
    digit[0] = replacement;
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
    char a[] = "9 test data";
    char b[] = "6 test data";
    char c[] = "2 test data";
    char d[] = "8 tets data";
    char e[] = "5 test data";
    ft_list_push_back(list_array, a);
    ft_list_push_back(list_array, b);
    ft_list_push_back(list_array, c);
    ft_list_push_back(list_array, d);
    ft_list_push_back(list_array, e);

    ft_list_sort(list_array, compare_func);

    return (0);
}
