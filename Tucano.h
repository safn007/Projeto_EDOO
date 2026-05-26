#ifndef _TUCANO_H_
#define _TUCANO_H_

#include "Inimigo.h"
#include <vector>
#include "Projetil.h"

class Tucano : public Inimigo {
private:
    float velocidade;
    int direction; 
    int cooldown;
    int max_cooldown;
    
    std::vector<Projetil*>& grupo_tiros; 

public:
    Tucano(float pos_x, float pos_y, int vida, float velocidade, std::vector<Projetil*>& tiros);
    
    ~Tucano() override;
    // Getters e setters

    float getVelocidade();
    void setVelocidade(float nova_vel);
    int getDirection();
    void setDirection(int dir);

    void update(int player_x, int player_y) override;
};

#endif