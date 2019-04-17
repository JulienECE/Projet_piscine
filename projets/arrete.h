#ifndef ARETES_H_INCLUDED
#define ARETES_H_INCLUDED
#include <vector>
#include "sommet.h"
#include "ligne.h"
class Aretes
{
    public:
        ///constructeur qui reçoit en params les données du sommet
        Aretes(int ida,int sD,int sA,float poids1,float poids2); ///identifiant,x,y
        ~Aretes();
        void dessiner (BITMAP *page);
        float  getpoids1 () const;
        float  getpoids2 () const;
        int  getSd() const;
        int  getSa() const;     ///num de l'arete, sommet départ, sommet d'arrivée
        int  getIda() const;

    protected:

    private:

        std::vector<const Aretes*> m_aretes;    /// Voisinage : liste d'adjacence
        float m_p1,m_p2;                        ///num de l'arete, sommet départ, sommet d'arrivée
        int m_sD, m_sA;                                        /// Données spécifiques de l'arete
        int m_ida;

       // float m_p1,m_p2; //num de l'arete, sommet départ, sommet d'arrivée
};
#endif // ARETES_H_INCLUDED
