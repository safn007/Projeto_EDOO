#include"bullet.h"
using namespace std;

Bullet::Bullet(int startX, int startY, int dir,
    std::vector<SolidObject*>& solidos, std::vector<Coletavel*>& col)
    : GRAVITY(0.2f), objetos_solidos(solidos), coletaveis(col){

         //valores genéricos
        this->width = 10.0f;
        this->height = 10.0f;
        this->x = startX - this->width/2.0f;
        this->y = startY - this->height/2.0f;

        //variáveis de movimento
        this->speed_x = 20.0f;
        this->vel_y = 0.0f;
        this->direction = dir;

        this->alive = true;

    }

void Bullet::apply_gravity(){
    this->vel_y += this->GRAVITY;
    this->y += this->vel_y;
}

void Bullet::kill(){
    this->alive = false;
}

bool Bullet::isAlive() const {
    return this->alive;
}

void Bullet::update(){

    //movimento horizontal
    this->x += this->speed_x * this->direction;

    //checar colisão após movimento horizontal
    SolidObject* plataforma_colidida_h = nullptr;

    for(SolidObject* obj : this->objetos_solidos){

        if(this->getLeft() < obj->getRight() &&
            this->getRight() > obj->getLeft() &&
            this->getTop() < obj->getBottom() &&
            this->getBottom() > obj->getTop()){

                plataforma_colidida_h = obj;
                break;

            }
    }

    if(plataforma_colidida_h != nullptr){

        if(this->direction > 0){
            this->setRight(plataforma_colidida_h->getLeft());
        }
        else{
            this->setLeft(plataforma_colidida_h->getRight());
        }

        direction *= -1;
        this->speed_x = 30.0f;

    }

    this->apply_gravity();

    //checar colisão vertical
    SolidObject* plataforma_colidida_v = nullptr;

    for(SolidObject* obj : this->objetos_solidos){

        if(this->getLeft() < obj->getRight() &&
            this->getRight() > obj->getLeft() &&
            this->getTop() < obj->getBottom() &&
            this->getBottom() > obj->getTop()){

                plataforma_colidida_v = obj;
                break;

            }

    }

    if(plataforma_colidida_v != nullptr){

        this->setBottom(plataforma_colidida_v->getTop());

        Coletavel* nova_pedra = new Coletavel();
        this->coletaveis.push_back(nova_pedra);

        this->kill();

    }

    if(this->getTop() > 770.0f){
        this->kill();
    }

}
