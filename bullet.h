#ifndef BULLET_H
#define BULLET_H
#include <vector>
#include"itens.h"

class Bullet {

    private:
        // x, y vão simular as propriedades do pygame    
        int x, y;
        char direction;

        bool alive;

    public:

        Bullet(int startX, int startY, char direction) : x(startX), y(startY), direction(direction), alive(true) {}

        //------ MÉTODOS ------
        void update();
        void kill();
        bool isAlive() const;

        int getX() const {
            return x;
        }
        int getY() const {
            return y;
        }
        void setX(const int x) {
            this->x = x;
        }
        void setY(const int y) {
            this->y = y;
        }
};

#endif