#include "player.h"
#include "game.h"
using namespace std;

int main() {

    // inicializando objetos
    Player player;
    Game game(&player); 

    // ações
    cout << "Ação 1" << endl;
    game.acao('D');
    game.acao('W');
    cout << "Ação 2" << endl;
    game.acao('D');
    cout << "Ação 3" << endl;
    game.acao('D');
    game.acao('D');
    game.acao('W');
    game.acao('A');
    game.acao('A');
}