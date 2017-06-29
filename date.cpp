#include"date.h"

Date::Date()
{
#if NDEBUG
   cout<<"Construction de DATE 1"<<endl;
#endif
   _dac=NULL;
   jour=0;
   mois=0;
   annee=0;
}

Date::Date(char *f)
{
   _dac=new char[strlen(f)+1];
   strcpy(_dac,f);

   /*Calcul de la Date*/

   jour=Retourne_Valeur(_dac,0,2);
   mois=Retourne_Valeur(_dac,3,5);
   annee=Retourne_Valeur(_dac,6,10);
}


Date::~Date()
{
#if NDEBUG
   cout<<"Destruction de DATE "<<endl;
#endif
   delete []_dac;
}

long Date::Retourne_Valeur(char *f,int pos_deb,int pos_fin)
{
   int pos=pos_fin-pos_deb;
   pos--;
   char *j=new char[pos];
#if NDEBUG
   cout<<"Construction de J"<<" Pos :"<<pos<<endl;
#endif
   int i1=0;
   long l=0;
#if NDEBUG
   cout<<"LANCE:"<<endl;
#endif
   for(int i=pos_deb;i<pos_fin;i++)
   {
      j[i1]=f[i];
#if NDEBUG
      cout<<i<<" :"<<j[i1]<<"/"<<f[i]<<endl;
#endif
      i1++;
   }
   l=atol(j);
#if NDEBUG
   cout<<"Destruction de J"<<endl;
   cout<<"J :"<<j<<endl;
   delete []j;
#endif
#if NDEBUG
   cout<<"L :"<<l<<" I1 :"<<i1<<endl;
#endif
   return (l);
}


int Date::Compare_Date(long a,long m,long j) //date de la caisse
{
   if(a>annee) return 0;
   if(a<annee) return 1;
   if(m>mois) return 0;
   if(m<mois) return 1;
   if(j>jour) return 0;
   if(j<jour) return 1;

}

ostream& operator <<(ostream &os,const Date &D)
{
   os<<"------------"<<endl<<"DATE :"<<endl;
   os<<"Annee :"<<D.annee<<endl;
   os<<"Mois :"<<D.mois<<endl;
   os<<"Jour :"<<D.jour<<endl;
   os<<"-------------"<<endl;
   return os;
}


