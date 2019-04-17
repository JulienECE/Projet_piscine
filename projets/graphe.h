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

        void triP1 ();
        void triP2 ();
        int tailleA() const;
      //  std::vector<Aretes> m_aretes;
        std::vector<Aretes>  getAre() const;
        std::vector<Sommet>  getSom() const;
    protected:

    private:
        /// Le réseau est constitué d'une collection de sommets
        std::vector<Sommet> m_sommets; ///stock dans un vecteur
        std::vector<Aretes> m_aretes;


};

#endif // GRAPHE_H
