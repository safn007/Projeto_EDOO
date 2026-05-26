#include "game.h"

std::vector<std::vector<int>> Game::mapa;
std::vector<Coletavel> Game::Item;

void Game::gerar_itens(Coletavel c) {
    Game::Item.push_back(c);
}

void Game::carregar_nivel() {
    if (Game::mapa[player.get_x()][player.get_y()] != 0) {}
}

void Game::acao(char c) {
    if (c == 'R' || c == 'L') {
        player.shoot(c);
        if (c == 'R') {
            for (int i = player.get_x(); i < 10; ++i) {
                if (mapa[player.get_y()][i] != 0) {
                    Inimigo i1(0, 0, false);
                    i1.take_damage();
                    mapa[player.get_y()][i] = 0;
                    break;
                }
            }
        }
        
    }
    else {
        player.update(c);
        if (mapa[player.get_y()][player.get_x()] != 0){
            player.take_damage();
        }
    }
    
}