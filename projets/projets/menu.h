#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "graphe.h"
#include "rectangle.h"
#include "cercle.h"
#include "ligne.h"

 class Menu
 {

 private:

     Rectangle m_fond;
     Rectangle m_titre;
     Rectangle m_grapheFinal;
     Ligne m_choix_1;
     Ligne m_choix_2;

 public :

    Menu (Rectangle fond,Rectangle titre, Rectangle grapheFinal, Ligne choix_1, Ligne choix_2);
    Menu ();
    ~Menu ();
    void dessinerBasique (BITMAP* page, graphe g);
    void dessinerKrusP1 (BITMAP* page, graphe g);
    void dessinerPareto (BITMAP* page, graphe g);
 } ;


#endif // MENU_H_INCLUDED
