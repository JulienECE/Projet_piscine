#include "ligne.h"

Ligne:: Ligne ( int x1, int y1,int x2, int y2, int couleur)
:m_x1(x1),m_y1(y1),m_x2(x2),m_y2(y2),m_couleur(couleur)
{}

Ligne:: Ligne ()
:m_x1(0),m_y1(0),m_x2(0),m_y2(0),m_couleur(0)
{}



Ligne:: ~Ligne ()

{}

void Ligne::dessiner(BITMAP *page)
{
line (page, m_x1,m_y1,m_x2,m_y2, m_couleur);
}

