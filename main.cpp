#ifndef HEADER
#include "header.h"
#define HEADER
#endif




void main()
{
   cout<<"VERSION :"<<VERSION<<endl;
   char Date_Aujourdhui[10];
   cout<<"Date d'ouverture de la caisse:"<<endl;
   cout<<"Format JJ.MM.AAAA"<<endl;
   cin>>Date_Aujourdhui;
   Caisse C(Date_Aujourdhui);
}



