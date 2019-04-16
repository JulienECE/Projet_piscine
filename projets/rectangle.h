#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include <time.h>
#include <unistd.h>

class Rectangle {

private :
    int m_x1;
    int m_y1;
    int m_x2;
    int m_y2;
    int m_couleur;
public:
    Rectangle ( int x1, int y1,int x2, int y2, int couleur);
    Rectangle ();
    ~Rectangle ();
    void dessinerFill (BITMAP * page);
    void dessiner (BITMAP * page);
};


#endif // RECTANGLE_H_INCLUDED
