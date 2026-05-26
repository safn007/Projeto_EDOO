#ifndef _INIMIGO_H_
#define _INIMIGO_H_
#include <iostream>
#include <string>
using namespace std;

class Inimigo{
private:
    int posicao_x, posicao_y;
    int vida;
    bool voador;
    int vel_y;
    bool no_chao;

    public:
    Inimigo(int pos_x, int pos_y, bool voador, int vida = 1);
    virtual ~Inimigo();
    //setters
    void setPX(int novo_pos_x);
    void setPY(int novo_pos_y);
    void setVida(int novo_vida);
    void setVoador(bool voa);
    //getters
    int getX();
    int getY();
    int getVida();
    bool getVoador();
    //métodos
    void take_damage(int amount);
    void apply_gravity();
    
    virtual void handle_collisions(); //parâmetro é um endereço de ponteiro do tipo Objetos_Solidos, que podem ser chao, plataformas ou parede
    
    virtual void update(int player_x, int player_y); //roda handle_collisions --> passar o vector<ObjetosSOlidos*> como parâmetro



};
#endif