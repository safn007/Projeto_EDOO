#ifndef GAME_H
#define GAME_H

#include "player.h"
#include <cstdlib>

void gerar_itens(Coletavel c, Item i, int quantidade, int y=600);

void carregar_nivel(Player p, bullet_group, tiros_inimigos, inimigos, coletaveis, subboss);

#endif