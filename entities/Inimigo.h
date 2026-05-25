#ifndef _INIMIGO_H_
#define _INIMIGO_H_
#include <iostream>
#include <string>
using namespace std;

class Inimigo{
private:
    float posicao_x, posicao_y;
    int vida;
    bool voador;
    float vel_y;
    bool no_chao;

    public:
    Inimigo(float pos_x, float pos_y, int vida = 1, bool voador);
    virtual ~Inimigo();
    //setters
    void setPX(float novo_pos_x);
    void setPY(float novo_pos_y);
    void setVida(int novo_vida);
    void setVoador(bool voa);
    //getters
    float getX();
    float getY();
    int getVida();
    bool getVoador();
    //métodos
    void take_damage(int amount);
    void apply_gravity();
    
    virtual void handle_collisions(); //parâmetro é um endereço de ponteiro do tipo Objetos_Solidos, que podem ser chao, plataformas ou parede
    
    virtual void update(float player_x, float player_y); //roda handle_collisions --> passar o vector<ObjetosSOlidos*> como parâmetro



};
#endif