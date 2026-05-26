#ifndef _PROJETIL_H_
#define _PROJETIL_H_

class Projetil {
private:
    float posicao_x;
    float posicao_y;
    float velocidade_x;
    float velocidade_y;
    int tipo;

public:
    // Construtor 
    Projetil(float x, float y, float vel_x, float vel_y, int tipo = 0);
    
    // Destrutor
    ~Projetil();

    // Getters
    float getX();
    float getY();
    float getVelX();
    float getVelY();
    int getTipo();

    // Setters
    void setX(float novo_x);
    void setY(float novo_y);
    void setVelX(float nova_vel_x);
    void setVelY(float nova_vel_y);

    
    void update();
};

#endif