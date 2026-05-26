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
    player.update(c);
    if (mapa[player.get_y()][player.get_x()] != 0){
        player.take_damage();
    }
}