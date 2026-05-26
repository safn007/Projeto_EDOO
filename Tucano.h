#ifndef _TUCANO_H_
#define _TUCANO_H_

#include "Inimigo.h"
#include <vector>
#include "Projetil.h"

class Tucano : public Inimigo {

public:
    Tucano(int pos_x, int pos_y, int vida = 1) : Inimigo(pos_x, pos_y, true, vida) { std::cout << "Objeto do tipo Tucano CRIADO!" << endl; }
    ~Tucano() override {}

    float getVelocidade();
    void setVelocidade(float nova_vel);
    int getDirection();
    void setDirection(int dir);

    void update(int player_x, int player_y) override;
};

#endif