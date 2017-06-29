#include "electro.h"

/*Declarations des methodes*/

/*
Entree:Aucune
Sortie:Aucune
Descriptif:     Constructeur
*/
Electromenager::Electromenager():Article(0,"ELECTROMENAGER")
{
   _nombre_de_composant=0;
   _nombre_de_defectueux=0;
#if NDEBUG
   cout<<"Constructeur ELECTRO 1"<<endl;
#endif
}

/*
Entree:Aucune
Sortie:Aucune
Descriptif:     Constructeur
*/
Electromenager::Electromenager(int code,float prix_achat,float prix_ht,char *nom,int nombre_stck,int nbcomps)
:Article(code,prix_achat,prix_ht,TVA_ELECTROMENAGER,nom,"ELECTROMENAGER",nombre_stck)
{                               //TVA_ELECTROMENAGER
   _nombre_de_composant=nbcomps;
   _nombre_de_defectueux=0;
   code_composant=new unsigned int[nbcomps-1];
   for(int i=0;i<nbcomps;i++) code_composant[i]=code+i+1;

#if NDEBUG
   cout<<"Constructeur ELECTRO 2"<<endl;
#endif
}

/*
Entree:Aucune
Sortie:Aucune
Descriptif:     Constructeur
*/
Electromenager::Electromenager(const Article &A,int nbcomps)
:Article(A)
{
   _nombre_de_composant=nbcomps;
   _nombre_de_defectueux=0;
   code_composant=new unsigned int[nbcomps-1];
   for(int i=0;i<nbcomps;i++) code_composant[i]=A._code+i+1;

#if NDEBUG
   cout<<"Constructeur ELECTRO 3"<<endl;
#endif

}

/*
Entree:Aucune
Sortie:Aucune
Descriptif:     Constructeur
*/
Electromenager::Electromenager(const Electromenager &E)
:Article(E._code,E._prix_achat,E._prix_ht,TVA_ELECTROMENAGER,E._nom,"ELECTROMENAGER",E._nombre_en_stocke)
{                                       //
   _nombre_de_composant=E._nombre_de_composant;
   _nombre_de_defectueux=E._nombre_de_defectueux;
   code_composant=new unsigned int[E._nombre_de_composant-1];
   for(int i=0;i<E._nombre_de_composant;i++) code_composant[i]=E._code+i+1;

#if NDEBUG
   cout<<"Constructeur ELECTRO 4"<<endl;
#endif
}

/*
Entree:Aucune
Sortie:Aucune
Descriptif: Destructeur
*/
Electromenager::~Electromenager()
{
#if NDEBUG
   cout<<"DESTRUCTION D'ELECTRO"<<endl;
#endif

}



void Electromenager::Vendu()
{
   Article::Vendu();
}


void Electromenager::Affecte(int code,float prix_achat,float prix_ht,char *nom,int nombre_stck,int nbcomps,unsigned int vendu)
{
   Article::Affecte(code,prix_achat,prix_ht,TVA_ELECTROMENAGER,nom,"ELECTROMENAGER",nombre_stck,vendu);
   _nombre_de_composant=nbcomps;                //
   _nombre_de_defectueux=0;

}


void Electromenager::Retour_Defectueux(int nb)
{
   _nombre_de_defectueux=_nombre_de_defectueux+nb;
}



/*
char *Electromenager::Nom()
{
Article::Nom();
}
*/


/*
Entree: Aucune
Sortie: -
Descriptif: Redirection de flux
*/
ostream& operator <<(ostream &os,const Electromenager &E)
{
   os<<"--------------------"<<endl<<"ELECTRO :";
   os<<(Article)E;
   os<<"Nombre de composant :"<<E._nombre_de_composant<<endl;
   os<<"Nombre d'articles défectueux :"<<E._nombre_de_defectueux<<endl;
   os<<"----------------"<<endl;
   return os;
}
