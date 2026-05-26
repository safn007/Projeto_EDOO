#ifndef _TUCANO_H_
#define _TUCANO_H_

#include "Inimigo.h"
#include <iostream>

class Tucano : public Inimigo {

public:
    Tucano(int pos_x, int pos_y, int vida = 1) : Inimigo(pos_x, pos_y, true, vida) { std::cout << "Objeto do tipo Tucano CRIADO!" << endl; }
    ~Tucano() override {}

};

#endif