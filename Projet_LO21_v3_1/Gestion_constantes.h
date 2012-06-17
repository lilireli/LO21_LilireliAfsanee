/*
  Hamici Mathilde
  Suzanne Aurélie
  Projet LO21 - Calculatrice à notation polonaise inversée
*/
#ifndef GESTION_CONSTANTES_H
#define GESTION_CONSTANTES_H

#include <QString>
#include "Constantes.h"

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
    ~Stack(){delete[] tab;}
    bool isEmpty(void) const {return (nbElements==0);}
    bool isFull(void) const {return (taille==nbElements);}
    int size() const {return nbElements;}
    int push(Constante *nb);  // retourne -1 si la pile est pleine
    Constante* pop();
//    void Swap(Entier* x, Entier*y);
//    void Sum(Entier* x);
//    void Mean(Entier* x);
//    void Clear(){this->~Stack();}
//    void Dup();
//    void Drop();
};



#endif // GESTION_CONSTANTES_H
