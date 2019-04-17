#include <iostream>
#include <queue>
#include <stack>
#include<unordered_map>
#include<unordered_set>
#include "sommet.h"

Sommet::Sommet(int id,int x,int y):m_id{id},m_x{x},m_y{y}
{
}
void Sommet::ajouterVoisin(const Sommet* voisin){
    m_voisins.push_back(voisin);
}
 void Sommet::afficherData() const{
     std::cout<<"    "<<m_id<<" : "<<"(x,y)=("<<m_x<<","<<m_y<<")"<<std::endl;
 }

/*
std::unordered_map<std::string,std::string> Sommet::parcoursBFS() const{
    std::unordered_map<std::string,std::string> l_pred;
    std::cout<<"BFS a completer"<<std::endl;
    return l_pred;
}
std::unordered_map<std::string,std::string> Sommet::parcoursDFS() const{
    std::unordered_map<std::string,std::string> l_pred;
    std::cout<<"DFS a completer"<<std::endl;
    return l_pred;
}
std::unordered_set<std::string> Sommet::rechercherCC() const{
    std::unordered_set<std::string> cc;
    std::cout<<"rechercherCC a coder"<<std::endl;
    return cc;
}*/
Sommet::~Sommet()
{
    //dtor
}

int  Sommet::getx() const
{
    return m_x;
}
int  Sommet::gety() const
{
    return m_y;
}
int  Sommet::getId() const
{
    return m_id;
}

void Sommet::dessiner(BITMAP * page)
{
    int a = getId();
    int b = getx();
    int c= gety();
    int noir = makecol(0,0,0);
    int couleur_fond = makecol(254, 254, 226);
    circle (page, b,c+50,15,noir);
    circlefill (page, b,c+50,14,couleur_fond);
    textprintf_ex(page,font,b-2, c-2+50, noir,-1,"%d",a);
}


void Sommet::dessinerKu(BITMAP * page)
{
    int a = getId();
    int b = getx();
    int c= gety();
    int noir = makecol(0,0,0);
    int couleur_fond = makecol(254, 254, 226);
    circle (page, ((b/2)+450),((c+50)/2+250),15,noir);
    circlefill (page, ((b/2)+450),((c+50)/2+250),14,couleur_fond);
    textprintf_ex(page,font,(((b-2)/2)+450), (((c-2+50)/2)+250), noir,-1,"%d",a);
}
