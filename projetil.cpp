#include "projetil.h"
using namespace std;

Projetil::Projetil(float startX, float startY, float vX, float vY, int tipo_projetil){

    this->tipo = tipo_projetil;

    if(this->tipo==0){
        this->width = 10.0f;
        this->height = 10.0f;
    }
    else if(this->tipo == 1){
        this->width = 25.0f;
        this->height = 25.0f;
    }

    this->x = startX - this->width/2.0f;
    this->y = startY - this->height/2.0f;

    this->vel_x = vX;
    this->vel_y = vY;

    this->alive = true;

}

void Projetil::kill(){
    this->alive = false;
}

bool Projetil::isAlive() const{
    return this->alive;
}

void Projetil::update(){

    if(this->tipo == 1){
        vel_y += 1.0f;
    }

    this->x += this->vel_x;
    this->y += this->vel_y;

    if(x<0.0f || x>15000.0f){
        this->kill();
    }

}