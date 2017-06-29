/*
Ecrit Par Mr Montaut Jean-Pierre
*/

#include <iostream.h>
#include <fstream.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

//--------------CLASSE ARTICLE---------- //
class Article
{
   public:
   unsigned int _code;
   unsigned int _nombre_vendu;
   float _prix_achat;
   float _prix_ht;
   float _tva;
   float _prix_tt;
   char *_nom;
   char *_type;
   int _nombre_en_stocke;

   Article();
   Article(int ,char*);
   Article(int,float,float,float,char*,char*,int);
   Article(const Article &);
   ~Article();

   void Supprimer();
   virtual void Vendu();
   unsigned int Nombre_Vendu();
   virtual unsigned int Code();
   char * Type();
   virtual  void Affecte(int,float,float,float,char*,char*,int,unsigned int);
   friend ostream& operator<<(ostream &os,const Article &A);
};

