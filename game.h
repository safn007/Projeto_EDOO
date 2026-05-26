#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "Inimigo.h"
#include <cstdlib>

class Game {
    private:
        void gerar_itens(Coletavel c);
        std::vector<int> camada0, camada1;
        Player player;

    public:
        static std::vector<std::vector<int>> mapa;
        static std::vector<Coletavel> Item;
        
        Game(Player* player) : camada0({0, 0, 0, 0, 0, 0, 0, 0, 0, 0}), camada1({0, 0, 0, 0, 0, 0, 0, 0, 0, 0}) {
            // inimigo 0, 5
            mapa = {camada0, camada1};
            this->player = *player;
        }

        void carregar_nivel();
        void acao(char c);
};


#endif