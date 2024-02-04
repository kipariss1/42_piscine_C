#include "libstr.h"

int is_uppercase(char ch){
    if (L_BIG < ch && ch < H_BIG){
        return 1;
    }

    return 0;
}