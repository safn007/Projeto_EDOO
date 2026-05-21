#include "player.h"

void Player::movimentacao() {
    bool mov_esq(false), mov_dir(false);
    if (!this->atirando) {
        if (keys['A']) mov_esq = true;
        if (keys['D']) mov_dir = true;
    }

    if (mov_esq && !mov_dir) { 
        this->vel_x = -velocidade; 
    }

    else if (!mov_esq && mov_dir) { 
        this->vel_x = velocidade; 
    }

    if (!this->no_ar) {
        inercia_x = 1.5;
        pulo_duplo = false;
    }
    else inercia_x = 0.7;

    if (this->vel_x < 0) {
        this->vel_x += inercia_x;
        if (this->vel_x > 0) this->vel_x = 0;
    }

    else if (this->vel_x < 0) {
        this->vel_x -= inercia_x;
        if (this->vel_x < 0) this->vel_x = 0;
    }

    if (this->pulo_duplo) this->pulo_duplo_timer += 1;
    else this->pulo_duplo_timer = 0;

    if(!this->atirando) {
        if ((keys['U'] || keys['W']) && !this->tecla_pulo && this->no_ar && this->pulo_duplo && this->pulo_duplo_timer >= 12) {
            this->pulo_duplo = false;
            this->vel_y = -20;
        }

        if ((keys['U'] || keys['W']) && !this->tecla_pulo && !this->no_ar) {
            this->pulo_duplo = (this->inventario.count("pipa") > 0) ? true : false;
            this->vel_y = -25;
        }
    }

    this->tecla_pulo = (keys['U'] || keys['W']);

    if (this->vel_y <= 25) this->vel_y += gravidade;
}

void Player::shoot() {
    // precisa de bullet_group b, objetos_solidos_pedra o, coletaveis c, Pedra p    

}

void Player::update() {
    std::unordered_map<char, bool> keys = {
        {'W', false},
        {'A', false},
        {'S', false},
        {'D', false},
        {'U', false}
    };

    if (invencib_timer > 0) invencib_timer -= 1;

    if (tiro_cooldown > 0) {
         tiro_cooldown -= 1; 
    }
    else {
         atirando = false; 
    }

    if (atirando && tiro_cooldown == 30) {
        // precisa da classe Bullet
        // Bullet bullet(spawn_x, self.hitbox.centery - 25, direction, objetos, gp_coletáveis, pedra);
        // static vector<Bullet> Balas;
        // Balas.push_back(new_bullet)
    }

    this->movimentacao();

}

void Player::take_damage() {
    if (invencib_timer <= 0) {
        this->vida -= 1;
        invencib_timer = 60;
        if (this->vida <= 0) {
            this->die();
        }
    }

}

void Player::die() {
    this->~Player();
}
