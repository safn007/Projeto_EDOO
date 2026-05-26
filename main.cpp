#include "player.h"
#include "game.h"
using namespace std;

int main() {

    // inicializando objetos
    Player player;
    Game game(&player); 

    // ações
    game.acao('D');
    game.acao('D');
    game.acao('D');
}