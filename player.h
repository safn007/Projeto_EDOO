#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <string>
#include "itens.h"
#include "bullet.h"

class ForaDoMapa {
    private:
        std::string text;
    public:
        ForaDoMapa(std::string text) : text(text) {
            std::cout << text << std:: endl;
        }
};

class Player {
    private:
        //pos_x e pos_y não estao no jogo original, mas foram adicionados para substituir rect
        int max_vida, vida, vel_x, vel_y, pos_x, pos_y, velocidade, pulo_duplo_timer, tiro_cooldown, tiro_cooldown_max;
        bool atirando, pulo_duplo, pulou;

        static const int gravidade = 1;
        std::unordered_map<std::string, int> inventario;
        std::unordered_map<char, bool> keys;
        inline void set_inv_false();

    public:
        Player() : max_vida(8), vida(8), vel_x(0), vel_y(gravidade), pos_x(0), pos_y(0), atirando(false), pulou(false), pulo_duplo(false),
        velocidade(1), pulo_duplo_timer(0),
        tiro_cooldown(0), tiro_cooldown_max(40)
        {
            this->inventario.insert({"pedra", 10});
            this->keys = {
                {'W', false},
                {'A', false},
                {'D', false},
                {'U', false}
            };
        }
        ~Player() {}
        
        // métodos
        int get_vida () {return this->vida;}
        int get_x() {return this->pos_x;}
        int get_y() {return this->pos_y;}
        void movimentacao();
        void shoot(char dir);
        void update(char key = '0');
        void take_damage();
        void die();
};

#endif
