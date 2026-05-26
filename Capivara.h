#ifndef CAPIVARA_H_
#define CAPIVARA_H_

#include "Inimigo.h"
<<<<<<< HEAD
=======
#include <vector>
#include "Projetil.h"
>>>>>>> ceac183ef39e7b197a8c30da83078980193d55da

class Capivara : public Inimigo {

public:
<<<<<<< HEAD
    Capivara(int pos_x, int pos_y, int vida = 1) : Inimigo(pos_x, pos_y, false, vida) { std::cout << "Objeto do tipo Capivara CRIADO!" << endl; }
    ~Capivara() override {}
=======
    Capivara(float pos_x, float pos_y, int vida, std::vector<Projetil*>& tiros);
    
    ~Capivara() override;

    void update(int player_x, int player_y) override;
>>>>>>> ceac183ef39e7b197a8c30da83078980193d55da
};

#endif