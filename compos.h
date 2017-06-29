
#include <iostream.h>
#include <fstream.h>     //flux des fichiers
#include <string.h>
#include <stdio.h>       //Fichier .H
#include <stdlib.h>     //ITOA
#include <string.h>
#include <math.h>
#include <ctype.h>

#define TVA_ELECTROMENAGER 20.6


#ifndef ELECTRO
#include "electro.h"
#define ELECTRO
#endif

class Composant:public Article
{
   int _nb_compo;
   public:
   Composant();
   Composant(int,float,float,char*,int);
   Composant(const Article &);
   Composant(const Composant &);
   ~Composant();
   virtual void Affecte(int,float,float,char*,int,unsigned int);
   virtual void Vendu();
   friend ostream& operator<<(ostream &os,const Composant &);

};

