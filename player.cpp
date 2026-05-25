#include "player.h"

// funções auxiliares
void Player::set_inv_false() {
    this->keys = {
        {'W', false},
        {'A', false},
        {'S', false},
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
        this->vel_x = -velocidade; 
    }

    else if (!mov_esq && mov_dir) { 
        this->vel_x = velocidade; 
    }

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
        if ((keys['U'] || keys['W']) && this->pulo_duplo && this->pulo_duplo_timer >= 12) {
            this->pulo_duplo = false;
            this->vel_y = 1;
            this->pulou = true;
        }

        if (keys['U'] || keys['W']) {
            this->pulo_duplo = (this->inventario.count("pipa") > 0) ? true : false;
            this->vel_y = 1;
            this->pulou = true;
        }
    }

    if (this->pos_y>= 1 && !this->pulou) this->vel_y -= gravidade;

    // atualizar posição
    this->pos_x += vel_x;
    this->pos_y += vel_y;
}

void Player::shoot() {
    // precisa de bullet_group b, objetos_solidos_pedra o, coletaveis c, Pedra p    

}

void Player::update(char key) {
    // reconfigura todas as keys para falso
    set_inv_false();

    // ativa key se alguma for fornecida
    if (key != '0') {
        keys[key] = true;
    }
    std::cout << "Posição(x, y): (" << this->pos_x << "," << this->pos_y << ")" << std::endl;

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
    std::cout << "Dano Recebido! Vida restante: " << this->vida << "/8." << std::endl;

}

void Player::die() {
    std::cout << "O Player morreu!" << std::endl; 
    this->~Player();
}
