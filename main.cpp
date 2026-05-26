#include "player.h"
using namespace std;

int main() {
    Player player;
    player.update();
    player.update('W');
    player.update();
    player.update('D');
    player.update('D');
    player.update('W');
    player.update();
    player.update();
}