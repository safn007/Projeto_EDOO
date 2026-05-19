#ifndef PLAYER_H
#define PLAYER_H

#include <unordered_map>
#include <string>

class Player {
    private:
        int max_vida, vida, vel_x, vel_y;
        bool no_ar, flip, atirando;
        std::unordered_map<std::string, int> inventario;

    public:
        static int gravidade, velocidade, pulo_duplo_timer, invencib_timer, invencib_duracao, tiro_cooldown, tiro_cooldown_max;  
        static float inercia_x;
        static bool pulo_duplo, tecla_pulo;

        Player() : max_vida(8), vida(8), vel_x(0), vel_y(gravidade), no_ar(true), flip(false), atirando(false) {
            this->inventario.insert({"pedra", 10});
        }
        ~Player() {}
        
        void movimentacao();
        void animar();
        void shoot();
        void update();
        void take_damage();
        void die();
};

#endif
