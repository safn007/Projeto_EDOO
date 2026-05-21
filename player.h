#ifndef PLAYER_H
#define PLAYER_H

#include <unordered_map>
#include <string>
#include <vector>

class Player {
    private:
        int max_vida, vida, vel_x, vel_y, gravidade, velocidade, pulo_duplo_timer, invencib_timer, invencib_duracao, tiro_cooldown, tiro_cooldown_max;
        bool no_ar, atirando, pulo_duplo, tecla_pulo;
        float inercia_x;
        std::unordered_map<std::string, int> inventario;
        std::unordered_map<char, bool> keys;

    public:
        Player() : max_vida(8), vida(8), vel_x(0), vel_y(gravidade), no_ar(true), atirando(false),
        inercia_x(1.5), gravidade(2), velocidade(10), pulo_duplo_timer(0), invencib_timer(0), invencib_duracao(60),
        tiro_cooldown(0), tiro_cooldown_max(40), pulo_duplo(false), tecla_pulo(false) 
        {
            this->inventario.insert({"pedra", 10});
        }
        ~Player() {}
        
        void movimentacao();
        void shoot();
        void update();
        void take_damage();
        void die();
};

#endif
