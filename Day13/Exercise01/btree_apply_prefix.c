#include <stdlib.h>
#include "ft_btree.h"

void f_ch(char *desc_char){
    desc_char[5] = '0';
    return;
}

void btree_apply_prefix(t_btree *root, void(*apply_prefix)(void *)){

    if (root == NULL){
        return;
    }

    // visit node
    apply_prefix(root->item);

    if (root->left){
        btree_apply_prefix(root->left, apply_prefix);
    }

    if (root->right){
        btree_apply_prefix(root->right, apply_prefix);
    }

    return;

}

int main(){

    t_btree *node1 = malloc(sizeof(t_btree));
    t_btree *node2 = malloc(sizeof(t_btree));
    t_btree *node3 = malloc(sizeof(t_btree));
    t_btree *node22 = malloc(sizeof(t_btree));
    t_btree *node23 = malloc(sizeof(t_btree));

    char d_1[] = "node 1";
    node1->item = d_1;
    char d_2[] = "node 2";
    node2->item = d_2;
    char d_3[] = "node 3";
    node3->item = d_3;
    char d_22[] = "node 22";
    node22->item = d_22;
    char d_23[] = "node 23";
    node23->item = d_23;

    node1->left = node2;
    node1->right = node3;
    node2->left = node22;
    node2->right = node23;

    btree_apply_prefix(node1, f_ch);

    return 0;
}
