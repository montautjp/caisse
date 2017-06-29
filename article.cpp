#include"article.h"

Article::Article()
{
   _code=0;
   _nombre_vendu=0;
   _prix_achat=0;
   _prix_ht=0;
   _tva=0;
   _prix_tt=(_prix_ht*_tva)/100+_prix_ht;
   _nom='\0';
   _type='\0';
   _nombre_en_stocke=0;
#if NDEBUG
   cout<<"Constructeur ARTICLE 1"<<endl;
#endif
}

Article::Article(int code,char *type)
{
   _code=code;
   _nombre_vendu=0;
   _prix_ht=0;
   _prix_achat=0;
   _tva=0;
   _prix_tt=0;
   _type=new char[strlen(type)+1];
   strcpy(_type,type);
   _nom='\0';
   _nombre_en_stocke=0;

#if NDEBUG
   cout<<"Constructeur ARTICLE 2"<<endl;
#endif
}

Article::Article(int code,float prix_achat,float prixht,float tva,char *nom,char *type,int nbsck)
{
   _code=code;
   _nombre_vendu=0;
   _prix_achat=prix_achat;
   _prix_ht=prixht;
   _tva=tva;
   _prix_tt=(_prix_ht*_tva)/100+_prix_ht;     //Calcule du prix tt
   _nom=new char[strlen(nom)+1];        //+1 pour la fin de ligne
   strcpy(_nom,nom);
   _type=new char[strlen(type)+1];
   strcpy(_type,type);
   _nombre_en_stocke=nbsck;
#if NDEBUG
   cout<<"Constructeur ARTICLE 3"<<endl;
#endif
}


Article::Article(const Article &A)
{
   _code=A._code;
   _nombre_vendu=A._nombre_vendu;
   _prix_achat=A._prix_achat;
   _prix_ht=A._prix_ht;
   _tva=A._tva;
   _prix_tt=(_prix_ht*_tva)/100+_prix_ht;     //Calcule du prix tt
   _nom=new char[strlen(A._nom)+1];     //+1 pour la fin de ligne
   strcpy(_nom,A._nom);
   _type=new char[strlen(A._type)+1];
   strcpy(_type,A._type);
   _nombre_en_stocke=A._nombre_en_stocke;
#if NDEBUG
   cout<<"Constructeur ARTICLE 4"<<endl;
#endif
}

Article::~Article()
{
#if NDEBUG
   cout<<"DELETE ARTICLE"<<endl;
#endif
   delete []_nom;
   delete []_type;
}


void Article::Supprimer()
{
   _nombre_en_stocke=0;
}

void Article::Vendu()
{
   _nombre_en_stocke--;
   _nombre_vendu++;

}


unsigned int Article::Nombre_Vendu()
{
   return(_nombre_vendu);
}


void Article::Affecte(int code,float prix_achat,float prixht,float tva,char *nom,char *type,int nbsck,unsigned int vendu)
{
   _code=code;
   _nombre_vendu=vendu;
   _prix_achat=prix_achat;
   _prix_ht=prixht;
   _tva=tva;
   _prix_tt=(_prix_ht*_tva)/100+_prix_ht;     //Calcule du prix tt
   _nom=new char[strlen(nom)+1];        //+1 pour la fin de ligne
   strcpy(_nom,nom);
   _type=new char[strlen(type)+1];
   strcpy(_type,type);
   _nombre_en_stocke=nbsck;
}




unsigned int Article::Code()
{
   return _code;

}

ostream& operator<<(ostream &os,const Article &A)
{
   os<<endl<<"_code: "<<A._code<<endl<<"_prix_achat: ";
   os<<A._prix_achat<<endl<<"_prix_tt:"<<A._prix_tt<<endl;
   os<<"_prix_ht :"<<A._prix_ht;
   os<<endl<<"_nom: "<< A._nom<<endl<<"_type: "<<A._type<<endl;
   os<<"_nombre_en_stocke: "<<A._nombre_en_stocke<<endl;
   os<<"_nombre_vendu: "<<A._nombre_vendu<<endl;
   return os;
}
