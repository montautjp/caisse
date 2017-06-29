#include"nourri.h"

Nourriture::Nourriture()
{
   Article(0,"NOURRITURE");
   _date_de_peremption='\0';
#if NDEBUG
   cout<<"Constructeur NOURRITURE 1"<<endl;
#endif
}

Nourriture::Nourriture(int code,float prix_achat,float prix_ht,char *nom,int nombre_stk,char *date)
:Article(code,prix_achat,prix_ht,TVA_NOURRITURE,nom,"NOURRITURE",nombre_stk)
{                               //
   _date_de_peremption=new char[strlen(date)+1];
   strcpy(_date_de_peremption,date);
#if NDEBUG
   cout<<"Constructeur NOURRITURE 2"<<endl;
#endif
}

Nourriture::Nourriture(const Article &a,char *date):Article(a)
{
   _date_de_peremption=new char[strlen(date)+1];
   strcpy(_date_de_peremption,date);
#if NDEBUG
   cout<<"Constructeur NOURRITURE 3"<<endl;
#endif
}


Nourriture::Nourriture(const Nourriture &N)
:Article(N._code,N._prix_achat,N._prix_ht,TVA_NOURRITURE,N._nom,"NOURRITURE",N._nombre_en_stocke)
{                                       //
   _date_de_peremption=new char[strlen(N._date_de_peremption)+1];
   strcpy(_date_de_peremption,N._date_de_peremption);
#if NDEBUG
   cout<<"Constructeur NOURRITURE 4"<<endl;
#endif
}

Nourriture::~Nourriture()
{
#if NDEBUG
   cout<<"DELETE NOURRITURE"<<endl;
#endif
   delete []_date_de_peremption;
}

void Nourriture::Vendu()
{
   Article::Vendu();

}


void Nourriture::Affecte(int code,float prix_achat,float prix_ht,char *nom,int nombre_stk,char *date,unsigned int vendu)
{                                               //
   Article::Affecte(code,prix_achat,prix_ht,TVA_NOURRITURE,nom,"NOURRITURE",nombre_stk,vendu);
   _date_de_peremption=new char[strlen(date)+1];
   strcpy(_date_de_peremption,date);
}

unsigned int Nourriture::Code()
{
   return(Article::Code());

}


ostream& operator<<(ostream &os,const Nourriture &N)
{ os<<"----------------"<<endl<<"NOURRITURE"<<endl;
   os<<(Article)N;
   os<<"Date de peremption :"<<N._date_de_peremption<<endl;
   os<<"------------"<<endl;
   return os;
}
