#include "Projetil.h"
#include <iostream>

using namespace std;

  // Construtor
Projetil::Projetil(float x, float y, float vel_x, float vel_y, int tipo) {
    this->posicao_x = x;
    this->posicao_y = y;
    this->velocidade_x = vel_x;
    this->velocidade_y = vel_y;
    this->tipo = tipo;
    

    cout << "Projétil do tipo " << this->tipo << " CRIADO em (" << x << ", " << y << ")" << endl;
}
// Destrutor
Projetil::~Projetil() {
    cout << "Projétil DESTRUÍDO" << endl;
}

// Getters
float Projetil::getX() { return posicao_x; }
float Projetil::getY() { return posicao_y; }
float Projetil::getVelX() { return velocidade_x; }
float Projetil::getVelY() { return velocidade_y; }
int Projetil::getTipo() { return tipo; }

// Setters
void Projetil::setX(float novo_x) { posicao_x = novo_x; }
void Projetil::setY(float novo_y) { posicao_y = novo_y; }
void Projetil::setVelX(float nova_vel_x) { velocidade_x = nova_vel_x; }
void Projetil::setVelY(float nova_vel_y) { velocidade_y = nova_vel_y; }

void Projetil::update() {
    this->posicao_x += this->velocidade_x;
    this->posicao_y += this->velocidade_y;
}