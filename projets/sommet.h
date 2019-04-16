#ifndef SOMMET_H_INCLUDED
#define SOMMET_H_INCLUDED
#include "cercle.h"


class Sommet {

private :
    int m_x1;
    int m_y1;
    int m_numero_de_sommet;
    Cercle bot;
public:
    Sommet ( int x1, int y1,int numero_de_sommet, Cercle bot);
    Sommet ();
    ~Sommet ();
    void dessiner (BITMAP * page);
};


#endif // SOMMET_H_INCLUDED
