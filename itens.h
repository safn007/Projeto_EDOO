#ifndef ITENS_H
#define ITENS_H

class Coletavel {
    private:
        int pos_x, pos_y;

    public:
        Coletavel() : pos_x(0), pos_y(0) {};
        Coletavel(int x, int y) : pos_x(x), pos_y(y) {};

        int get_x() {return this->pos_x;}
        int get_y() {return this->pos_y;}

        void set_x(int x) {this->pos_x = x;}
        void set_y(int y) {this->pos_y = y;}
};

// como no codigo original as classes filhas só tratam da animação, nao ha nada a adicionar nelas
class Pipa : public Coletavel { };

class Pedra : public Coletavel { };

class Guarana : public Coletavel { };

class Raio : public Coletavel { };

#endif