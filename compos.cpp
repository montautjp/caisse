#include"compos.h"

Composant::Composant():Article(0,"COMPOSANT")
{
#if NDEBUG
   cout<<"Constructeur 1 de Composant"<<endl;
#endif

}

Composant::Composant(int code,float prix_achat,float prix_ht,char *nom,int nombre_stck)
:Article(code,prix_achat,prix_ht,TVA_ELECTROMENAGER,nom,"COMPOSANT",nombre_stck)
{
#if NDEBUG
   cout<<"Constructeur 2 de Composant"<<endl;
#endif
}

Composant::Composant(const Article &A):Article(A)
{
#if NDEBUG
   cout<<"Constructeur 3 de Composant"<<endl;
#endif
}

Composant::Composant(const Composant &C)
:Article(C._code,C._prix_achat,C._prix_ht,TVA_ELECTROMENAGER,C._nom,"COMPOSANT",C._nombre_en_stocke)
{
#if NDEBUG
   cout<<"Constructeur 4 de Composant"<<endl;
#endif
}

Composant::~Composant()
{
#if NDEBUG
   cout<<"Destructeur de Composant"<<endl;
#endif
}

void Composant::Vendu()
{
   Article::Vendu();
}


void Composant::Affecte(int code,float prix_achat,float prix_ht,char *nom,int nombre_stck,unsigned int vendu)
{
   Article::Affecte(code,prix_achat,prix_ht,TVA_ELECTROMENAGER,nom,"COMPOSANT",nombre_stck,vendu);
}



ostream& operator<<(ostream &os,const Composant &C)
{
   os<<"------------------"<<endl<<"COMPOSANT:";
   os<<(Article)C;
   os<<"-----------"<<endl;
   return os;
}
