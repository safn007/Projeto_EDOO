#ifndef _ONCA_H_
#define _ONCA_H_
#include "Inimigo.h"
#include <iostream>
#include <string>
using namespace std;

class Onca : public Inimigo{
private:
    float velocidade;
    int direcao;
    bool atacando;
    int ataque_timer;
    int ataque_cooldown;
public:
    Onca(float pos_x, float pos_y, int vida, bool voador, float vel);
    void update(float player_x, float player_y) override;
};


#endif