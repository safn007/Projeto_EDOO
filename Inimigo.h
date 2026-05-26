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
    void take_damage();
    
};
#endif