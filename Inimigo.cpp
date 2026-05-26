#include "Inimigo.h"
#include <iostream>
using namespace std;

Inimigo::Inimigo(int pos_x, int pos_y, bool voador, int vida){
    this->posicao_x = pos_x;
    this->posicao_y = pos_y;
    this->vida = vida;
    this->voador = voador;
};

Inimigo::~Inimigo(){};

//setters
void Inimigo::setPX(int novo_pos_x){posicao_x = novo_pos_x;}

void Inimigo::setPY(int novo_pos_y){posicao_y = novo_pos_y;}

void Inimigo::setVida(int novo_vida){vida = novo_vida;}

void Inimigo::setVoador(bool voa){voador = voa;}

//getters
int Inimigo::getX(){return posicao_x;}

int Inimigo::getY(){return posicao_y;}

int Inimigo::getVida(){return vida;}

bool Inimigo::getVoador(){return voador;}

//métodos
void Inimigo::take_damage(){
    this->vida -= 1;
    if (this->vida <= 0){
        cout << "Inimigo morreu!" << endl;
        Inimigo::~Inimigo();
        
    }
    else {cout << "Inimigo sofreu dano!" << endl;}
}
