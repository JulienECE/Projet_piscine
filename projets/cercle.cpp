#include "cercle.h"

Cercle:: Cercle ( int x1, int y1, int rayon, int couleur)
:m_x1(x1),m_y1(y1),m_rayon(rayon),m_couleur(couleur)
{}

Cercle:: Cercle ()
:m_x1(0),m_y1(0),m_rayon(0),m_couleur(0)
{}



Cercle:: ~Cercle ()

{}

void Cercle::dessinerFill(BITMAP *page)
{
circlefill (page, m_x1,m_y1, m_rayon,m_couleur);
}


void Cercle::dessiner(BITMAP *page)
{
circle (page, m_x1,m_y1,m_rayon, m_couleur);
}

