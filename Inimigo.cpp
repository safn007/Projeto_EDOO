#include "Inimigo.h"
#include <iostream>
using namespace std;

Inimigo::Inimigo(int pos_x, int pos_y, bool voador, int vida){
    this->posicao_x = pos_x;
    this->posicao_y = pos_y;
    this->vida = vida;
    this->voador = voador;
    cout<< "Objeto do tipo Inimigo CRIADO!" << endl;
};

Inimigo::~Inimigo(){};

//setters
void Inimigo::setPX(float novo_pos_x){posicao_x = novo_pos_x;}

void Inimigo::setPY(float novo_pos_y){posicao_y = novo_pos_y;}

void Inimigo::setVida(int novo_vida){vida = novo_vida;}

void Inimigo::setVoador(bool voa){voador = voa;}

//getters
float Inimigo::getX(){return posicao_x;}

float Inimigo::getY(){return posicao_y;}

int Inimigo::getVida(){return vida;}

bool Inimigo::getVoador(){return voador;}

//métodos
void Inimigo::take_damage(int amount){
    this->vida -= amount;
    if (this->vida <= 0){
        //deletar
    }
}

void Inimigo::apply_gravity(){
    vel_y += 1; //GRAVITY == 1;
    //não usa rect.y
}

void Inimigo::handle_collisions(){

}

void Inimigo::update(int player_x, int player_y) {}

