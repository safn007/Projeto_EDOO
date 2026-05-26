#include "Onca.h"
#include <iostream>
using namespace std;

Onca::Onca(float pos_x, float pos_y, int vida, bool voador, float vel) : Inimigo(pos_x, pos_y, vida, voador), velocidade(vel){

    direcao = -1;
    atacando = false;
    ataque_timer = 0;
    ataque_cooldown = 0;

    cout << "Objeto do tipo Onça CRIADO!"<< endl;
}

void Onca::update(float player_x, float player_y){
    
}



