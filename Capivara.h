#ifndef _CAPIVARA_H_
#define _CAPIVARA_H_

#include "Inimigo.h"
#include <vector>

class Projetil;

class Capivara : public Inimigo {
private:
    int cooldown;
    int max_cooldown;
    
    std::vector<Projetil*>& grupo_tiros;

public:
    Capivara(float pos_x, float pos_y, int vida, std::vector<Projetil*>& tiros);
    
    ~Capivara() override;

    void update(float player_x, float player_y) override;
};

#endif