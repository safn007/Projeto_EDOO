#ifndef CAPIVARA_H_
#define CAPIVARA_H_

#include "Inimigo.h"
#include <vector>
#include "Projetil.h"

class Capivara : public Inimigo {

public:
    Capivara(int pos_x, int pos_y, int vida = 1) : Inimigo(pos_x, pos_y, false, vida) { std::cout << "Objeto do tipo Capivara CRIADO!" << endl; }
    ~Capivara() override {}
};

#endif