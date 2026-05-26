#include "player.h"

// funções auxiliares
void Player::set_inv_false() {
    this->keys = {
        {'W', false},
        {'A', false},
        {'D', false},
        {'U', false}
    };
}

void Player::movimentacao() {
    // reiniciar velocidades e bool do pulo
    this->vel_x = 0; this->vel_y = 0; pulou = false;

    bool mov_esq(false), mov_dir(false);
    if (!this->atirando) {
        if (keys['A']) mov_esq = true;
        if (keys['D']) mov_dir = true;
    }

    if (mov_esq && !mov_dir) { 
        this->vel_x = velocidade * (-1); 
        std::cout << "Player andou para a esquerda." << std:: endl;
    }

    else if (!mov_esq && mov_dir) { 
        this->vel_x = velocidade; 
        std::cout << "Player andou para a direita." << std:: endl;
    }

    if (this->pulo_duplo) this->pulo_duplo_timer += 1;
    else this->pulo_duplo_timer = 0;

    if(!this->atirando) {
        if ((keys['U'] || keys['W']) && this->pulo_duplo && this->pulo_duplo_timer >= 12) {
            this->pulo_duplo = false;
            this->vel_y = 1;
            this->pulou = true;
            std::cout << "Player pulou." << std:: endl;
        }

        if (keys['U'] || keys['W']) {
            this->pulo_duplo = (this->inventario.count("pipa") > 0) ? true : false;
            this->vel_y = 1;
            this->pulou = true;
            std::cout << "Player pulou." << std:: endl;
        }
    }

    if (this->pos_y>= 1 && !this->pulou) this->vel_y -= gravidade;

    // atualizar posição
    try {
        this->pos_x += vel_x;
        this->pos_y += vel_y;
        if (pos_x < 0 || pos_x > 10) {throw ForaDoMapa("Saiu do Mapa!");} 
    }
    catch(ForaDoMapa& e)
    {}
}

void Player::shoot(char dir) {
    Bullet bullet(this->pos_x, this->pos_y, dir); 
    tiro_cooldown = 5;
    std::cout << "TIRO DISPARADO!" << std::endl;
}

void Player::update(char key) {
    // reconfigura todas as keys para falso
    set_inv_false();

    // ativa key se alguma for fornecida
    if (key != '0') {
        keys[key] = true;
    }
    std::cout << "Posição(x, y): (" << this->pos_x << "," << this->pos_y << ")" << std::endl;

    if (tiro_cooldown > 0) {
         tiro_cooldown -= 1; 
    }
    else {
         atirando = false; 
    }

    if (tiro_cooldown > 0) {--tiro_cooldown; }

    this->movimentacao();
}

void Player::take_damage() {
    this->vida -= 1;
    if (this->vida <= 0) { this->die(); }
    std::cout << "Dano Recebido! Vida restante: " << this->vida << "/8." << std::endl;

}

void Player::die() {
    std::cout << "O Player morreu!" << std::endl; 
    this->~Player();
}
