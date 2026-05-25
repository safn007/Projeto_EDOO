#ifndef GAME_H
#define GAME_H

#include "player.h"
#include <cstdlib>

class Game {
    private:
        void gerar_itens(Coletavel c, int x, int y);
    public:
        static std::vector<Coletavel> Item;
        // precisa de varias classes
        

        void carregar_nivel(Player player, bullet_group, tiros_inimigos, inimigos, coletaveis, subboss);
};


#endif