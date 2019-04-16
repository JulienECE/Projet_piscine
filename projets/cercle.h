#ifndef CERCLE_H_INCLUDED
#define CERCLE_H_INCLUDED
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include <time.h>
#include <unistd.h>

class Cercle {

private :
    int m_x1;
    int m_y1;
    int m_rayon;
    int m_couleur;
public:
    Cercle ( int x1, int y1,int rayon, int couleur);
    Cercle ();
    ~Cercle ();
    void dessinerFill (BITMAP * page);
    void dessiner (BITMAP * page);
};



#endif // CERCLE_H_INCLUDED
