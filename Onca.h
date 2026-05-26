#ifndef _ONCA_H_
#define _ONCA_H_
#include "Inimigo.h"
#include <iostream>
#include <string>
using namespace std;

class Onca : public Inimigo{
private:
    int velocidade;
    int direcao;
    bool atacando;
    int ataque_timer;
    int ataque_cooldown;
public:
    Onca(int pos_x, int pos_y, int vida, bool voador, int vel);
    void update(int player_x, int player_y) override;
};


#endif