#ifndef _TUCANO_H_
#define _TUCANO_H_

#include "Inimigo.h"
<<<<<<< HEAD
#include <iostream>
=======
#include <vector>
#include "Projetil.h"
>>>>>>> ceac183ef39e7b197a8c30da83078980193d55da

class Tucano : public Inimigo {

public:
    Tucano(int pos_x, int pos_y, int vida = 1) : Inimigo(pos_x, pos_y, true, vida) { std::cout << "Objeto do tipo Tucano CRIADO!" << endl; }
    ~Tucano() override {}

<<<<<<< HEAD
=======
    float getVelocidade();
    void setVelocidade(float nova_vel);
    int getDirection();
    void setDirection(int dir);

    void update(int player_x, int player_y) override;
>>>>>>> ceac183ef39e7b197a8c30da83078980193d55da
};

#endif