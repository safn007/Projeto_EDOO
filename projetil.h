#ifndef PROJETIL_H
#define PROJETIL_H

class Projetil{

    private: 
        float x, y, width, height, vel_x, vel_y;
        int tipo;
        bool alive;

    public:

        Projetil(float startX, float startY, float vX, float vY, int tipo_projetil = 0);

        void update();
        void kill();
        bool isAlive() const;

        float getX() const{
            return x;
        }

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