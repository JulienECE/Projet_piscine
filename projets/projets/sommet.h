#ifndef SOMMET_H
#define SOMMET_H
#include <vector>
#include "cercle.h"
#include <random>

class Sommet
{
    public:
        ///constructeur qui reçoit en params les données du sommet
        Sommet(int,int,int); ///identifiant,x,y
        void ajouterVoisin(const Sommet*);
        void afficherData() const;
       /* ///méthode de parcours en largeur du graphe à partir du sommet
        ///renvoie les prédécesseurs sous forme d'une map (clé=id du sommet,valeur=id de son prédécesseur)
        std::unordered_map<std::string,std::string> parcoursBFS() const;
         ///méthode de parcours en profondeur du graphe à partir du sommet
        std::unordered_map<std::string,std::string> parcoursDFS() const;
        ///méthode qui recherche la composante connexe du sommet
        ///renvoie la liste des ids des sommets de la composante
        std::unordered_set<std::string> rechercherCC() const; */
        ~Sommet();
        void dessiner(BITMAP * page);
        void dessinerKu (BITMAP * page);
        int  getId() const;
        int  gety() const;
        int  getx() const;


    private:
        /// Voisinage : liste d'adjacence
        std::vector<const Sommet*> m_voisins;
        int m_id,m_x, m_y;
        /// Données spécifiques du sommet
 //num du sommet Position

};

#endif // SOMMET_H
