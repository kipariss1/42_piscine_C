#ifndef __FT_ULTIMATE_FIGHT_H__
#define __FT_ULTIMATE_FIGHT_H__

#include "ft_perso.h"

typedef enum {
    KICK,
    PUNCH,
    HEADBUTT,
    KICK1,
    KICK2,
    KICK3,
    KICK4,
    KICK5,
    KICK6,
    KICK7,
    KICK8,
    KICK9,
    KICK10,
    KICK11,
    KICK12, 
    DEAD,
} t_attack;

int ATTACK_POINTS[] = {15, 5, 20, 13, 3, 18, 9, 11, 13, 8, 6, 11, 9, 18, 10};
char *ATTACK_NAMES[] = {"KICK", "PUNCH", "HEADBUTT", "chop ichi", "chop ni", "chop san", "chop shi", "chop go", "chop roku", "chop shichi", "chop hachi", "chop ku", "chop ju", "chop hyaku", "chop sen"};

void ft_ultimate_fight(t_perso *attacker, t_perso *defendant, t_attack attack);

#endif