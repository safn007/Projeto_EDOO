#ifndef BULLET_H
#define BULLET_H
#include<vector>

//classes que serão criadas depois
//to colocando só pro codigo funcionar
//depois remover essas classes e colocar tipo "#include "collectible.h"#

class SolidObject {
    public:
        //métodos só pra compilar de boas
        float getLeft() const { return 0; }
        float getRight() const { return 0; }
        float getTop() const { return 0; }
        float getBottom() const { return 0; }
};

class Collectible{

};

//------------------------
//Código da classe Bullet:
//------------------------

class Bullet {

    private:

        //x,y,width,height vão simular as propriedades do pygame    
        float x, y, width, height, speed_x, vel_y;
        const float GRAVITY;
        int direction;

        bool alive;

        std::vector<SolidObject*>& objetos_solidos;
        std::vector<Collectible*>& coletaveis;

    public:

        Bullet(float startX, float startY, int dir, 
            std::vector<SolidObject*>& solidos, std::vector<Collectible*>& col);

        //------ MÉTODOS ------

        void apply_gravity();
        void update();
        void kill();
        bool isAlive() const;

        //---- SIMULANDO O PYGAME -----
        
        float getLeft() const {
            return x;
        }
        void setLeft(float val){
            x = val;
        }
        float getRight() const {
            return x+width;
        }
        void setRight(float val){
            x = val - width;
        }
        float getTop() const {
            return y;
        }
        float getBottom() const {
            return y+height;
        }
        void setBottom(float val) {
            y = val - height;
        }
        float getCenterX() const{
            return x + (width/2.0f);
        }

};

#endif