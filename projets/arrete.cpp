#include "arrete.h"

Aretes::Aretes(int ida,int sD,int sA,float poids1,float poids2):m_ida{ida},m_sD{sD},m_sA{sA},m_p1{poids1},m_p2{poids2}
{
}

Aretes::~Aretes()
{
    //dtor
}

float  Aretes::getpoids1() const
{
    return m_p1;
}

float  Aretes::getpoids2() const
{
    return m_p2;
}


int  Aretes::getSd() const
{
    return m_sD;
}

int  Aretes::getIda() const
{
    return m_ida;
}


int  Aretes::getSa() const
{
    return m_sA;
}
