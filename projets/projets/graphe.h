#ifndef GRAPHE_H
#define GRAPHE_H
#include <string>
#include <fstream>
#include <iostream>
#include <unordered_map>
#include "sommet.h"
#include "arrete.h"
#include <vector>
#include <algorithm>
#include <math.h>
#include <bitset>

class graphe
{
    public:
        ///constructeur qui charge le graphe en mémoire
        //format du fichier ordre/liste des sommets/taille/liste des arêtes
        graphe(std::string,std::string);
        graphe();
        ~graphe();
        void afficher() const;
        void dessiner(BITMAP* page);
        void dessinerKu(BITMAP* page);
        void brutForce() const;
        void triP1 ();
        void triP2 ();
        int tailleA() const;
        int tailleS() const;
        void insererArete (Aretes a);
        void insererSommet (Sommet a);
        int getTaille() const;
        int getOrdre() const;
      //  std::vector<Aretes> m_aretes;
        std::vector<Aretes>  getAre() const;
        std::vector<Sommet>  getSom() const;
    protected:

    private:
        /// Le réseau est constitué d'une collection de sommets
        std::vector<Sommet> m_sommets; ///stock dans un vecteur
        std::vector<Aretes> m_aretes;
        int m_taille;
        int m_ordre;


};

#endif // GRAPHE_H
