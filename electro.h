#include <iostream.h>
#include <fstream.h>     //flux des fichiers
#include <string.h>
#include <stdio.h>       //Fichier .H
#include <stdlib.h>     //ITOA
#include <string.h>
#include <math.h>
#include <ctype.h>

#define TVA_ELECTROMENAGER 20.6

#ifndef ARTICLE
#include "article.h"
#define ARTICLE
#endif

/*----------------------CLASSE ELECTRO-------------*/
class Electromenager:public Article
{
   public:
   int _nombre_de_composant;
   int _nombre_de_defectueux;
   Electromenager();
   Electromenager(int,float,float,char*,int,int);
   unsigned int *code_composant;
   Electromenager(const Article &,int);
   Electromenager(const Electromenager &);
   ~Electromenager();
   virtual void Vendu();
   virtual void Affecte(int,float,float,char*,int,int,unsigned int);
   void Retour_Defectueux(int);
   friend ostream& operator<<(ostream &os,const Electromenager &);
};
