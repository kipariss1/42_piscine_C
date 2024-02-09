#ifndef __FT_FIGHT_H__
#define __FT_FIGHT_H__

#include "ft_perso.h"

typedef enum {
    KICK,
    PUNCH,
    HEADBUTT,
    DEAD,
} t_attack;

void ft_fight(t_perso *attacker, t_perso *defendant, t_attack attack);

#endif