#include "libstr.h"

int is_letter(char ch){
    if ((L_BIG < ch && ch < H_BIG) || (L_SMALL < ch && ch < H_SMALL)){
        return 1;
    }

    return 0;
}