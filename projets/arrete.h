#ifndef ARETES_H_INCLUDED
#define ARETES_H_INCLUDED
#include <vector>
#include "sommet.h"
#include "ligne.h"
class Aretes
{
    public:
        ///constructeur qui re�oit en params les donn�es du sommet
        Aretes(int ida,int sD,int sA,float poids1,float poids2); ///identifiant,x,y
        ~Aretes();
        void dessiner (BITMAP *page);
        float  getpoids1 () const;
        float  getpoids2 () const;
        int  getSd() const;
        int  getSa() const;     ///num de l'arete, sommet d�part, sommet d'arriv�e
        int  getIda() const;

    protected:

    private:

        std::vector<const Aretes*> m_aretes;    /// Voisinage : liste d'adjacence
        float m_p1,m_p2;                        ///num de l'arete, sommet d�part, sommet d'arriv�e
        int m_sD, m_sA;                                        /// Donn�es sp�cifiques de l'arete
        int m_ida;

       // float m_p1,m_p2; //num de l'arete, sommet d�part, sommet d'arriv�e
};
#endif // ARETES_H_INCLUDED
