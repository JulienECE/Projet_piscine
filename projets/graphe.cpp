#include "graphe.h"
#include "arrete.h"
#include "sommet.h"



struct orderP1
{
    inline bool operator() (const Aretes p1, const Aretes p2)
    {
        return ( p1.getpoids1() < p2.getpoids1());
    }
};

struct orderP2
{
    inline bool operator() (const Aretes sp1, const Aretes sp2)
    {
    return ( sp1.getpoids2() < sp2.getpoids2());;
    }
};


graphe::graphe(){
}



///Code du TP2 de théorie des graphes pour la lecture des fichiers
graphe::graphe(std::string nomFichier, std::string nomFichier2){
    std::ifstream ifs{nomFichier};
    if (!ifs)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + nomFichier );
    int ordre;
    ifs >> ordre;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture ordre du graphe");
    int id;
    int x,y;
    //lecture des sommets
    for (int i=0; i<ordre; ++i){
        ifs>>id; if(ifs.fail()) throw std::runtime_error("Probleme lecture données sommet");
        ifs>>x; if(ifs.fail()) throw std::runtime_error("Probleme lecture données sommet");
        ifs>>y; if(ifs.fail()) throw std::runtime_error("Probleme lecture données sommet");
        m_sommets.push_back( Sommet (id,x,y));
        /*std::cout<<m_sommets[i].m_id;
        std::cout<<m_sommets[i].m_x;
        std::cout<<m_sommets[i].m_y<<std::endl;*/ //POur vérifier que le tableau est bien centré
    }
    int taille;
    ifs >> taille;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture taille du graphe");

    std::ifstream pfs{nomFichier2};
    if (!pfs)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + nomFichier2 );
    int taille2;
    int pond;
    pfs >>  taille2;
    if ( pfs.fail() )
        throw std::runtime_error("Probleme lecture ordre du graphe");
    pfs>>pond;
    int ida;
    int sD,sA;
    float poids1,poids2;
    //lecture des aretes
    for (int i=0; i<taille; ++i){
        //lecture des ids des deux extrémités
        ifs>>id; if(ifs.fail()) throw std::runtime_error("Probleme lecture arete sommet 1");
        ifs>>sD>>sA;
        if(pfs.fail())
            throw std::runtime_error("Probleme lecture données arete");
        pfs>> ida;
        if(pfs.fail())
            throw std::runtime_error("Probleme lecture données arete");
        pfs >> poids1;
        if(pfs.fail())
            throw std::runtime_error("Probleme lecture données arete");
        pfs >> poids2;
        if(pfs.fail())
            throw std::runtime_error("Probleme lecture données arete1");
        m_aretes.push_back( Aretes (id,sD,sA,poids1,poids2));
    }

}


void graphe::triP1()
{
std::sort(m_aretes.begin(), m_aretes.end(), orderP1 () );
}

void graphe::triP2()
{
std::sort(m_aretes.begin(), m_aretes.end(), orderP2 () );
}

void graphe::afficher() const{
    std::cout<<"graphe : "<<std::endl;
    std::cout<<"  coder l'affichage ! "<<std::endl;
}


graphe::~graphe()
{
    //dtor
}



std::vector<Aretes>  graphe::getAre() const
{
    return m_aretes;
}

std::vector<Sommet>  graphe::getSom() const
{
    return m_sommets;
}


int graphe::tailleA() const
{
     return m_aretes.size();
}

void graphe::dessiner(BITMAP* page)
{
        int noir = makecol (0,0,0);
        int rouge = makecol (200,0,0);
        for (size_t j=0; j<m_aretes.size(); j++)
        {
            int a = m_aretes[j].getSd();
            int b = m_aretes[j].getSa();
            float c = m_aretes[j].getpoids1();
            float d = m_aretes[j].getpoids2();
            line(page, m_sommets[a].getx(),m_sommets[a].gety()+50, m_sommets[b].getx(),m_sommets[b].gety()+50, noir);
            textprintf_ex(page,font,(m_sommets[a].getx()+m_sommets[b].getx())/2+2, (m_sommets[a].gety()+m_sommets[b].gety())/2+50+2, rouge,-1,"%.0f/%.0f", c,d);
        }
        for (size_t i=0; i<m_sommets.size(); i++)
            {m_sommets[i].dessiner(page);}
}
