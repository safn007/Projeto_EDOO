#include "Tucano.h"

#include <iostream>
using namespace std;

Tucano::Tucano(float pos_x, float pos_y, int vida, float velocidade, std::vector<Projetil*>& tiros)
    : Inimigo(pos_x, pos_y, vida, true), grupo_tiros(tiros) 
{
    this->velocidade = velocidade;
    this->direction = 1; 
    this->cooldown = 0;
    this->max_cooldown = 50;
    
    cout << "Objeto do tipo Tucano CRIADO!" << endl;
}

Tucano::~Tucano() {
    cout << "Objeto do tipo Tucano DESTRUÍDO" << endl;
}

// Getters e setters
float Tucano::getVelocidade() { return velocidade; }
void Tucano::setVelocidade(float nova_vel) { velocidade = nova_vel; }
int Tucano::getDirection() { return direction; }
void Tucano::setDirection(int dir) { direction = dir; }

void Tucano::update(int player_x, int player_y) {
    cooldown++;
    if (cooldown > max_cooldown) {
        cooldown = 0;
        Projetil* bomba = new Projetil(getX(), getY() + 20, 0, 0, 1);
        grupo_tiros.push_back(bomba);
    }
    
    // vem da classe mãe
    float novo_x = getX() + (velocidade * direction);
    setPX(novo_x);

    Inimigo::update(player_x, player_y);
}