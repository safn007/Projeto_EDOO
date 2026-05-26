#include "Capivara.h"
using namespace std;
<<<<<<< HEAD
=======

Capivara::Capivara(float pos_x, float pos_y, int vida, std::vector<Projetil*>& tiros)
    : Inimigo(pos_x, pos_y, vida, false), grupo_tiros(tiros) 
{
    this->cooldown = 0;
    this->max_cooldown = 100;
    
    cout << "Objeto do tipo Capivara CRIADO!" << endl;
}

Capivara::~Capivara() {
    cout << "Objeto do tipo Capivara DESTRUÍDO" << endl;
}

void Capivara::update(int player_x, int player_y) {
    float distancia = player_x - getX();

    if (std::abs(distancia) < 1000.0f) {
        cooldown++;

        if (cooldown > max_cooldown) {
            cooldown = 0;
            
            float direcao_tiro = (distancia < 0) ? -10.0f : 10.0f;
            
            Projetil* bomba = new Projetil(getX(), getY(), direcao_tiro, 0.0f);
            grupo_tiros.push_back(bomba);
        }
    }

    Inimigo::update(player_x, player_y);
}
>>>>>>> ceac183ef39e7b197a8c30da83078980193d55da
