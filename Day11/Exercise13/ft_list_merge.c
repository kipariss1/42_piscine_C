#include "ft_list.h"
#include <stdlib.h>

void ft_list_merge(t_list **begin_list1, t_list *begin_list2){
    // traverse to end of begin_list1
    t_list *begin_list1_last;
    for (begin_list1_last = *begin_list1; begin_list1_last->next!=0x00; begin_list1_last = begin_list1_last->next){}

    begin_list1_last->next = begin_list2;
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

    t_list **list_array1 = (t_list**)malloc(sizeof(t_list*));
    char a[] = "1 test data";
    char b[] = "2 test data";
    char c[] = "3 test data";
    char d[] = "4 tets data";
    char e[] = "5 test data";
    ft_list_push_back(list_array1, a);
    ft_list_push_back(list_array1, b);
    ft_list_push_back(list_array1, c);
    ft_list_push_back(list_array1, d);
    ft_list_push_back(list_array1, e);

    t_list **list_array2 = (t_list**)malloc(sizeof(t_list*));
    char f[] = "6 test data";
    char g[] = "7 test data";
    char h[] = "8 test data";
    ft_list_push_back(list_array2, f);
    ft_list_push_back(list_array2, g);
    ft_list_push_back(list_array2, h);

    ft_list_merge(list_array1, *list_array2);

    return (0);
}