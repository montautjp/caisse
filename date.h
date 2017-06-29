#include <iostream.h>
#include <fstream.h>     //flux des fichiers
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

class Date
{
   char *_dac;
   public:
   long jour,mois,annee;
   Date();
   Date(char *);
   ~Date();
   long Retourne_Valeur(char *,int,int);
   int Compare_Date(long ,long ,long );	//Modifier par Ben
   friend ostream& operator<<(ostream &os,const Date &D);

};
