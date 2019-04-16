#ifndef LIGNE_H_INCLUDED
#define LIGNE_H_INCLUDED
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include <time.h>
#include <unistd.h>

class Ligne {

private :
    int m_x1;
    int m_y1;
    int m_x2;
    int m_y2;
    int m_couleur;
public:
    Ligne ( int x1, int y1,int x2, int y2, int couleur);
    Ligne ();
    ~Ligne ();
    void dessiner (BITMAP * page);
};



#endif // LIGNE_H_INCLUDED
