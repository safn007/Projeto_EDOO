#ifndef BULLET_H
#define BULLET_H
#include<vector>
#include"itens.h"

class SolidObject {
    public:
        //métodos só pra compilar de boas
        int getLeft() const { return 0; }
        int getRight() const { return 0; }
        int getTop() const { return 0; }
        int getBottom() const { return 0; }
};

//------------------------
//Código da classe Bullet:
//------------------------

class Bullet {

    private:

        //x,y,width,height vão simular as propriedades do pygame    
        int x, y, width, height, speed_x, vel_y;
        const int GRAVITY;
        int direction;

        bool alive;

        std::vector<SolidObject*>& objetos_solidos;
        std::vector<Coletavel*>& coletaveis;

    public:

        Bullet(int startX, int startY, int dir, 
            std::vector<SolidObject*>& solidos, std::vector<Coletavel*>& col);

        //------ MÉTODOS ------

        void apply_gravity();
        void update();
        void kill();
        bool isAlive() const;

        //---- SIMULANDO O PYGAME -----

        int getLeft() const {
            return x;
        }
        void setLeft(int val){
            x = val;
        }
        int getRight() const {
            return x+width;
        }
        void setRight(int val){
            x = val - width;
        }
        int getTop() const {
            return y;
        }
        int getBottom() const {
            return y+height;
        }
        void setBottom(int val) {
            y = val - height;
        }
        int getCenterX() const{
            return x + (width/2.0f);
        }

};

#endif