#include"bullet.h"
using namespace std;

void Bullet::kill(){
    this->alive = false;
}

bool Bullet::isAlive() const {
    return this->alive;
}

void Bullet::update(){}