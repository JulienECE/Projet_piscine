#include "menu.h"


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


void Menu::dessinerBasique(BITMAP *page, graphe g)
{
    int noir = makecol(0,0,0);
    int rouge = makecol (255,0,0);
    m_fond.dessinerFill (page);
    m_titre.dessiner (page);
    m_grapheFinal.dessiner (page);
    m_choix_1.dessiner (page);
    m_choix_2.dessiner (page);
    g.dessiner(page);
    /// TEXT + SOURIS
    textprintf_ex(page,font,50, 45, noir,-1,"Voici le graphe original : ");
    textprintf_ex(page,font,450, 73, noir,-1,"Cliquez pour le graphe de Kruskal : ");
    textprintf_ex(page,font,452, 163, noir,-1,"Cliquez pour le graphe de Pareto : ");
    circle(page, mouse_x, mouse_y,10, rouge);
    circle(page, mouse_x, mouse_y,11, rouge);
    line  (page, 500,115, 585, 115, noir);
    line  (page, 500,145, 585, 145, noir);
    textprintf_ex(page,font,505, 105, noir,-1,"Selon P1 : ");
    textprintf_ex(page,font,505, 135, noir,-1,"Selon P2 : ");
    line  (page, mouse_x,mouse_y, mouse_x-10, mouse_y, rouge);
    line  (page, mouse_x,mouse_y, mouse_x+10, mouse_y, rouge);
    line  (page, mouse_x,mouse_y, mouse_x, mouse_y+10, rouge);
    line  (page, mouse_x,mouse_y, mouse_x, mouse_y-10, rouge);
    blit (page,screen, 0,0, 0, 0,SCREEN_W,SCREEN_H);
}







void Menu::dessinerKrusP1(BITMAP *page, graphe g)

{
    int s =g.tailleA(),i;
    int tableau[s];
    int d,b,c;
    int somme_p1=0,somme_p2=0;
    int noir = makecol(0,0,0);
    int rouge = makecol (255,0,0);
    for (i=0; i<s;i++)
    {
        tableau[i]=i;
    }
    graphe kru_p1;
    m_fond.dessinerFill (page);
    m_titre.dessiner (page);
    m_grapheFinal.dessiner (page);
    m_choix_1.dessiner (page);
    m_choix_2.dessiner (page);
    g.dessiner(page);
    g.triP1();
    int tailleso =kru_p1.tailleS();
    int tailleAr =kru_p1.tailleA();
    for (Sommet rs :g.getSom())
        {
            b = rs.getId();
            c = rs.getx();
            d = rs.gety();
            kru_p1.insererSommet( Sommet (b,c,d));
        }
    for (Aretes ro : g.getAre())
        {
            int s1=tableau[ro.getSa()];
            int s2=tableau[ro.getSd()];
            if (s1!=s2)
            {
                kru_p1.insererArete( Aretes (ro.getIda(),ro.getSd(),ro.getSa(),ro.getpoids1(),ro.getpoids2()));
                somme_p1+=ro.getpoids1();
                somme_p2+=ro.getpoids2();
                for (i=0; i<s;i++)
                {
                    if (s1==tableau[i])
                        {
                        tableau[i]=s2;
                        }
                }
            }

        }
    textprintf_ex(page,font,460, 265, noir,-1,"L'arbre de poids couvrant min selon");
    textprintf_ex(page,font,480, 285, noir,-1,"P1 est : (%d/%d) ",somme_p1,somme_p2);
    kru_p1.dessinerKu(page);
    /// TEXT + SOURIS
    textprintf_ex(page,font,50, 45, noir,-1,"Voici le graphe original : ");
    textprintf_ex(page,font,450, 73, noir,-1,"Cliquez pour le graphe de Kruskal : ");
    textprintf_ex(page,font,452, 163, noir,-1,"Cliquez pour le graphe de Pareto : ");
    textprintf_ex(page,font,550, 570, noir,-1,"Appuyer sur N : Back ");
    line  (page, 500,115, 585, 115, noir);
    line  (page, 500,145, 585, 145, noir);
    textprintf_ex(page,font,505, 105, noir,-1,"Selon P1 : ");
    textprintf_ex(page,font,505, 135, noir,-1,"Selon P2 : ");
    circle(page, mouse_x, mouse_y,10, rouge);
    circle(page, mouse_x, mouse_y,11, rouge);
    line  (page, mouse_x,mouse_y, mouse_x-10, mouse_y, rouge);
    line  (page, mouse_x,mouse_y, mouse_x+10, mouse_y, rouge);
    line  (page, mouse_x,mouse_y, mouse_x, mouse_y+10, rouge);
    line  (page, mouse_x,mouse_y, mouse_x, mouse_y-10, rouge);
    blit (page,screen, 0,0, 0, 0,SCREEN_W,SCREEN_H);
}


void Menu::dessinerPareto (BITMAP* page, graphe g)
{
    int noir = makecol(0,0,0);
    int rouge = makecol (255,0,0);
    int vert = makecol(0,255,0);
    m_fond.dessinerFill (page);
    m_titre.dessiner (page);
    m_grapheFinal.dessiner (page);
    m_choix_1.dessiner (page);
    m_choix_2.dessiner (page);
    Rectangle a(450,250,750,550,vert);
    a.dessinerFill(page);
    g.dessiner(page);
    /// TEXT + SOURIS
    textprintf_ex(page,font,50, 45, noir,-1,"Voici le graphe original : ");
    textprintf_ex(page,font,450, 73, noir,-1,"Cliquez pour le graphe de Kruskal : ");
    textprintf_ex(page,font,452, 163, noir,-1,"Cliquez pour le graphe de Pareto : ");
    textprintf_ex(page,font,550, 570, noir,-1,"Appuyer sur N : Back ");
    line  (page, 500,115, 585, 115, noir);
    line  (page, 500,145, 585, 145, noir);
    textprintf_ex(page,font,505, 105, noir,-1,"Selon P1 : ");
    textprintf_ex(page,font,505, 135, noir,-1,"Selon P2 : ");
    circle(page, mouse_x, mouse_y,10, rouge);
    circle(page, mouse_x, mouse_y,11, rouge);
    line  (page, mouse_x,mouse_y, mouse_x-10, mouse_y, rouge);
    line  (page, mouse_x,mouse_y, mouse_x+10, mouse_y, rouge);
    line  (page, mouse_x,mouse_y, mouse_x, mouse_y+10, rouge);
    line  (page, mouse_x,mouse_y, mouse_x, mouse_y-10, rouge);
    blit (page,screen, 0,0, 0, 0,SCREEN_W,SCREEN_H);
}
