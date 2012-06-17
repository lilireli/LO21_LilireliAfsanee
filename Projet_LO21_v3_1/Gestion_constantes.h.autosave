/*
  Hamici Mathilde
  Suzanne Aurélie
  Projet LO21 - Calculatrice à notation polonaise inversée
*/
#ifndef GESTION_CONSTANTES_H
#define GESTION_CONSTANTES_H

#include <QString>
#include "Constantes.h"
#include "Logger.h"

extern LoggerConsole* logger1;
extern LoggerFile* logger2;

using namespace Calcul;

int NombreValide(QString chaine);

int FormuleValide(QString s);
// retourne :
// 1 pour entier
// 2 pour reel
// 3 pour rationnel
// 4 pour complexe
// 5 pour expression
// 0 pour expression non valide


class Stack
{
    int nbElements;
    int taille;
    Constante** tab;
public:
    Stack(int nb=50):taille(nb), nbElements(0), tab(new Constante*[nb]) {}
    ~Stack(){clear(); delete[] tab;}
    bool isEmpty(void) const {return (nbElements==0);}
    bool isFull(void) const {return (taille==nbElements);}
    int size() const {return nbElements;}
    int push(Constante *nb);  // retourne -1 si la pile est pleine
    Constante* pop();
    void clear();
    int Swap(Entier* x, Entier*y);
    void afficherPile(); // why
    QString retournePileS(); // why

    class iterator{
        Constante** courant;
    public :
        iterator(Constante** c = 0) : courant(c) {}
        iterator& operator++() {courant--; return *this;}
        iterator& operator--() {courant++; return *this;}
        iterator operator+(int i) {return iterator(courant -i);}
        iterator operator-(int i) {return iterator(courant +i);}
        bool operator== (const iterator& it) const {return courant == it.courant;}
        bool operator!= (const iterator& it) const {return courant != it.courant;}
        Constante* operator* () const {return *courant;}
        Constante* getIt() const { return *courant;}
        void swap(iterator& it) {Constante* tmp = *courant; *courant = *it.courant; *it.courant = tmp;}
    };
    iterator begin() {return iterator(tab + nbElements - 1);}
    iterator end() {return iterator(tab - 1);}
    // on parcoure la pile de l'élement le plus récent au plus vieux

    Stack* clone() {
        Stack* nouvellePile = new Stack(nbElements);
        nouvellePile->taille = taille;
        for(iterator it = (this->end()-1); it != (this->begin()-1); --it){
            nouvellePile->push(*it);
        }
        return nouvellePile;
    }

};



#endif // GESTION_CONSTANTES_H
