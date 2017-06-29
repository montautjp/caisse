

#include <iostream.h>
#include <fstream.h>     //flux des fichiers
#include <string.h>
#include <stdio.h>       //Fichier .H
#include <stdlib.h>     //ITOA
#include <string.h>
#include <math.h>
#include <ctype.h>

#define TVA_NOURRITURE 5
#define TVA_ELECTROMENAGER 20.6
#define NDEBUG 0//Mettre a 1 pour le DEBUGGAGE sinon 0
//#define VERSION 61
#define NMAX    80

#ifndef ELECTRO
#include "electro.h"
#define ELECTRO
#endif

#ifndef NOURRI
#include "nourri.h"
#define NOURRI
#endif

#ifndef COMPOS
#include "compos.h"
#define COMPOS
#endif

#ifndef DATE
#include "date.h"
#define DATE
#endif


class Caisse
{
   Nourriture *N;
   Electromenager *E;
   Composant *C;
   int type;
   int ic,ie,in;
   int nb_c,nb_e,nb_n;
   long _date;
   unsigned int choix;
   public:
   Caisse();
   Caisse(char *);
   ~Caisse(void);

   void Lire_Base();
   void Allocation_Article();
   void Vendre(int &,int);
   int Retourne_Pos_Type(int);
   void Retour(int,int);
   void rafraichir_stock();
   void Peremption_proche(Date *);
   void Menu();
   void statistique();
   friend ostream& operator<<(ostream &os,const Caisse &C);
   Date *D;
};

