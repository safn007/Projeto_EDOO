#include "player.h"
#include "game.h"
#include "Tucano.h"
#include "Onca.h"
using namespace std;

int main() {

    // inicializando objetos
    Player player;
    Tucano i1(1, 0, false); Onca i2(5, 0, false);
    vector<Inimigo*> inimigos = {&i1, &i2};
    Game game(&player, inimigos); 

    // ações
    game.acao('D');
    game.acao('W');
    game.acao('D');
    game.acao('D');
    game.acao('D');
    game.acao('W');
    game.acao('A');
    game.acao('A');
}