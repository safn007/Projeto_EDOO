#include "player.h"
#include "game.h"
#include "Tucano.h"
#include "Capivara.h"
using namespace std;

int main() {
    cout << "//// SIMULAÇÃO INICIADA ////" << endl << endl;
    // inicializando objetos
    Player player;
    Capivara i1(1, 0, false); Tucano i2(5, 0, false);
    vector<Inimigo*> inimigos = {&i1, &i2};
    Game game(&player, inimigos); 

    // ações
    game.acao('D');
    game.acao('W');
    game.acao('A');
    game.acao('R');
    game.acao('D');
    game.acao('D');
    game.acao('W');
    game.acao('A');
    game.acao('A');
    game.acao('A');
}