#include "menu.h"

/*
Menu:: Menu ( Rectangle fond,Rectangle titre, Rectangle grapheFinal)
:m_fond(fond),m_titre(titre),m_grapheFinal(grapheFinal)
{}
*/
Menu:: Menu ()
{
int couleur_fond = makecol(254, 254, 226);
int noir = makecol(0,0,0);
m_fond = Rectangle (0,0,SCREEN_W,SCREEN_H, couleur_fond);
m_titre = Rectangle (20, 20,300,70, noir);
m_grapheFinal = Rectangle (450,250,750,550,noir);
m_choix_1 = Ligne (450,90,720,90,noir);
m_choix_2 = Ligne (450,180,720,180,noir);
}



Menu:: ~Menu ()

{}


void Menu::dessiner(BITMAP *page)
{
    int noir = makecol(0,0,0);
    int rouge = makecol (255,0,0);
    m_fond.dessinerFill (page);
    m_titre.dessiner (page);
    m_grapheFinal.dessiner (page);
    m_choix_1.dessiner (page);
    m_choix_2.dessiner (page);
    /// TEXT + SOURIS
    textprintf_ex(page,font,50, 45, noir,-1,"Voici le graphe original : ");
    textprintf_ex(page,font,450, 73, noir,-1,"Cliquez pour le graphe de Kruskal : ");
    textprintf_ex(page,font,452, 163, noir,-1,"Cliquez pour le graphe de Pareto : ");
    circle(page, mouse_x, mouse_y,10, rouge);
    circle(page, mouse_x, mouse_y,11, rouge);
    line  (page, mouse_x,mouse_y, mouse_x-10, mouse_y, rouge);
    line  (page, mouse_x,mouse_y, mouse_x+10, mouse_y, rouge);
    line  (page, mouse_x,mouse_y, mouse_x, mouse_y+10, rouge);
    line  (page, mouse_x,mouse_y, mouse_x, mouse_y-10, rouge);
    blit (page,screen, 0,0, 0, 0,SCREEN_W,SCREEN_H);
}
