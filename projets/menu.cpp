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
/*

    graphe Menu::Graphe_P1_K (BITMAP* page, graphe g)
    {
            g.triP1();
    for (Sommet rs :g.getSom())
        {
        b = rs.getId();
        c = rs.getx();
        d = rs.gety();
        kru_p1.getSom().push_back( Sommet (b,c,d));
        std::cout<<rs.getId();
        std::cout<<rs.getx();
        std::cout<<rs.gety()<<std::endl;    // //Pour vérifier que le tableau est bien centré
        }for (Aretes ro : g.getAre())
        {
            b = ro.getIda();
            c = ro.getSa();
            d = ro.getSd();
            std::cout <<ro.getSa()<<std::endl;
            kru_p1.getAre().push_back( Aretes (ro.getIda(),ro.getSd(),ro.getSa(),ro.getpoids1(),ro.getpoids2()));
        }


        return grapheP1;
    }*/

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
    line  (page, mouse_x,mouse_y, mouse_x-10, mouse_y, rouge);
    line  (page, mouse_x,mouse_y, mouse_x+10, mouse_y, rouge);
    line  (page, mouse_x,mouse_y, mouse_x, mouse_y+10, rouge);
    line  (page, mouse_x,mouse_y, mouse_x, mouse_y-10, rouge);
    blit (page,screen, 0,0, 0, 0,SCREEN_W,SCREEN_H);
}

void Menu::dessinerKrus(BITMAP *page, graphe g)

{
    int s =g.tailleA(),i;
    int tableau[s][2];
    int d,b,c,e,f;
    int noir = makecol(0,0,0);
    int rouge = makecol (255,0,0);
    for (i=0; i<s;i++)
    {
        tableau[i][1]=i;
        tableau[i][2]=i;
    }
    graphe kru_p1;
    graphe kru_p2;
    m_fond.dessinerFill (page);
    m_titre.dessiner (page);
    m_grapheFinal.dessiner (page);
    m_choix_1.dessiner (page);
    m_choix_2.dessiner (page);
    Rectangle a(450,250,750,550,rouge);
    a.dessinerFill(page);
   // g.dessiner(page);
    g.triP1();
    for (Sommet rs :g.getSom())
        {
        b = rs.getId();
        c = rs.getx();
        d = rs.gety();
        kru_p1.getSom().push_back( Sommet (b,c,d));
        std::cout<<rs.getId();
        std::cout<<rs.getx();
        std::cout<<rs.gety()<<std::endl;    //*/ //Pour vérifier que le tableau est bien centré
        }for (Aretes ro : g.getAre())
        {
            b = ro.getIda();
            c = ro.getSa();
            d = ro.getSd();
            std::cout <<ro.getSa()<<std::endl;
            kru_p1.getAre().push_back( Aretes (ro.getIda(),ro.getSd(),ro.getSa(),ro.getpoids1(),ro.getpoids2()));
        }



    kru_p1.dessiner(page);
    /// TEXT + SOURIS
    textprintf_ex(page,font,50, 45, noir,-1,"Voici le graphe original : ");
    textprintf_ex(page,font,450, 73, noir,-1,"Cliquez pour le graphe de Kruskal : ");
    textprintf_ex(page,font,452, 163, noir,-1,"Cliquez pour le graphe de Pareto : ");
    textprintf_ex(page,font,550, 570, noir,-1,"Appuyer sur N : Back ");
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
    circle(page, mouse_x, mouse_y,10, rouge);
    circle(page, mouse_x, mouse_y,11, rouge);
    line  (page, mouse_x,mouse_y, mouse_x-10, mouse_y, rouge);
    line  (page, mouse_x,mouse_y, mouse_x+10, mouse_y, rouge);
    line  (page, mouse_x,mouse_y, mouse_x, mouse_y+10, rouge);
    line  (page, mouse_x,mouse_y, mouse_x, mouse_y-10, rouge);
    blit (page,screen, 0,0, 0, 0,SCREEN_W,SCREEN_H);
}
