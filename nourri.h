/*
Ecrit par Mr MONTAUT Jean-Pierre
*/
#include <iostream.h>
#include <fstream.h>     //flux des fichiers
#include <string.h>
#include <stdio.h>       //Fichier .H
#include <stdlib.h>     //ITOA
#include <string.h>
#include <math.h>
#include <ctype.h>

#define TVA_NOURRITURE 5


#ifndef ARTICLE
#include "article.h"
#define ARTICLE
#endif

#ifndef DATE
#include "date.h"
#define DATE
#endif


class Nourriture: public Article
{
   public:
   char *_date_de_peremption;
   Nourriture();
   Nourriture(int,float,float,char*,int,char*);
   Nourriture(const Article &,char*);
   Nourriture(const Nourriture &);
   ~Nourriture();
   virtual void Vendu();
   virtual void Affecte(int,float,float,char*,int,char*,unsigned int);
   virtual unsigned int Code();
   friend ostream& operator<<(ostream &os,const Nourriture &N);
};

