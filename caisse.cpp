#include"caisse.h"

Caisse::Caisse()
{
}

Caisse::Caisse(char *date)
{
   ic=0,ie=0,in=0;
   choix=0;
   D=new Date(date);
   Allocation_Article();
   Lire_Base();
   rafraichir_stock();
   Menu();

}



Caisse::~Caisse(void)
{
   delete []N;
   delete []C;
   delete []E;

}



void Caisse::Allocation_Article()
{

   ifstream fichier;
   int val=0;

   nb_e=0,nb_n=0,nb_c=0;
   char *lire=new char[NMAX];
#if NDEBUG
   cout<<"Premiere lecture..."<<endl;
#endif
   fichier.open("base.dat");
   fichier.getline(lire,NMAX,'\n');
#if NDEBUG
   cout<<"NOMBRE D'ARTICLE:"<<lire<<endl;
#endif
   val=atoi(lire);
   while((strcmp(lire,"X")!=0))
   {
      fichier.getline(lire,NMAX,'\n');
#if NDEBUG
      cout<<lire<<endl;
#endif

      if(strcmp(lire,"NOURRITURE")==0)
      {
	 nb_n++;
      }
      else
      {
	 if(strcmp(lire,"COMPOSANT")==0)
	    nb_c++;
	 else
	    if(strcmp(lire,"ELECTROMENAGER")==0)
	       nb_e++;
      }


   }
   fichier.close();
   N=new Nourriture[nb_n];
   E=new Electromenager[nb_e];
   C=new Composant[nb_c];


   delete []lire;

}


void Caisse::Lire_Base()
{
   ifstream fichier;

   int val=0,code=0,quantite=0,nombre_composant=0;
   char *nom=new char[NMAX];
   char *date=new char[NMAX];
   float prix_achat=0,prix_ht=0;
   char *lire=new char[NMAX];
#if NDEBUG
   cout<<"Deuxieme Lecture :"<<endl;
#endif
   fichier.open("base.dat");
   fichier.getline(lire,NMAX,'\n');
   val=atoi(lire);
#if NDEBUG
   cout<<"val :"<<val<<endl;
#endif
   while((strcmp(lire,"X")!=0))
   {
      fichier.getline(lire,NMAX,'\n');
      code=atoi(lire);
      fichier.getline(lire,NMAX,'\n');
      strcpy(nom,lire);
      fichier.getline(lire,NMAX,'\n');
      prix_achat=atof(lire);
      fichier.getline(lire,NMAX,'\n');
      prix_ht=atof(lire);
      fichier.getline(lire,NMAX,'\n');
      quantite=atoi(lire);
      fichier.getline(lire,NMAX,'\n');
      if(strcmp(lire,"NOURRITURE")==0)
      {
	 fichier.getline(lire,NMAX,'\n');
	 strcpy(date,lire);
	 N[in].Affecte(code,prix_achat,prix_ht,nom,quantite,date,0);
	 cout<<N[in]<<endl;
	 in++;
      }
      else
      {
	 if(strcmp(lire,"ELECTROMENAGER")==0)
	 {
	    fichier.getline(lire,NMAX,'\n');
	    nombre_composant=atoi(lire);
	    E[ie].Affecte(code,prix_achat,prix_ht,nom,quantite,nombre_composant,0);
	    ie++;

	 }
	 else
	 {
	    if(strcmp(lire,"COMPOSANT")==0)
	    {

	       C[ic].Affecte(code,prix_achat,prix_ht,nom,quantite,0);
	       ic++;

	    }
	    else
	    {lire="X";
	    }
	 }
      }
   }
   fichier.close();
}



void Caisse::Vendre(int &code,int nombre)
{
   int i;
   int pos=Retourne_Pos_Type(code);
   /*recherche la pos grace au code*/
   if(type==1)
   {

      if(N[pos]._nombre_en_stocke>=nombre)
      {
	 for(i=0;i<nombre;i++)
	 {
	    N[pos].Vendu();
	 }
	 cout<<N[pos];
      }

      else cout<<"Nombre insuffisant en stock"<<endl;

   }
   if(type==2)
   {
      if(C[pos]._nombre_en_stocke>=nombre)
      {
	 for(i=0;i<nombre;i++)
	 {
	    C[pos].Vendu();
	 }
	 cout<<C[pos];
      }

      else cout<<"Nombre insuffisant en stock"<<endl;
   }
   if(type==3)
   {
      int assez_composant=1;
      int pos_composant;
      int tempo_type=type;
      if(E[pos]._nombre_en_stocke>=nombre)
      {
	 for(i=1;i<=E[pos]._nombre_de_composant;i++)
	 {
	    pos_composant=Retourne_Pos_Type(code+i);
	    if(C[pos_composant]._nombre_en_stocke<nombre)
	    {
	       assez_composant=0;}

	 }
	 if(assez_composant)
	 {
	    for(i=0;i<nombre;i++)
	    {
	       E[pos].Vendu();

	    }
	    for(int j=1;j<=E[pos]._nombre_de_composant;j++)
	    {
	       pos_composant=Retourne_Pos_Type(code+j);
	       for(int k=0;k<nombre;k++)
	       {
		  C[pos_composant].Vendu();

	       }
	    }

	 }
	 else cout<<"Composant insuffisant"<<endl;
      }
      else cout<<"Nombre insuffisant en stock"<<endl;
   }
}



int Caisse::Retourne_Pos_Type(int code)
{
   int c=0;
   int i=0;
   for( i=0;i<in;i++)
   {
      c=N[i].Code();
      if(c==code)
      {
	 type=1;
	 return i;
      }
   }
   for(i=0;i<ic;i++)
   {
      c=C[i].Code();
      if(c==code){
	 type=2;
	 return i;
      }
   }
   for(i=0;i<ie;i++)
   {
      c=E[i].Code();
      if(c==code){

	 type=3;
	 return i;
      }
   }
   type=-1;
   cout<<"Code non trouvé..."<<endl;
   return -1;
}



void Caisse::rafraichir_stock()
{
   cout<<".....calcul de rafraichisssemnt........."<<endl;
   for(int i=0;i<in;i++)
   {
      if(strcmp(N[i]._date_de_peremption,"Aucune"))
      {
	 Date D_nourriture(N[i]._date_de_peremption);
	 if((D_nourriture.Compare_Date(D->annee,D->mois,D->jour))==0)
	 {
	    cout<<"Suppression du stock de l'article:"<<endl;
	    N[i]._nombre_en_stocke=0;
	    cout<<N[i];
	 }
      }
   }
}



void Caisse::Peremption_proche(Date *limite)
{
   cout<<"Limite choisit:"<<endl;
   cout<<*limite;
   cout<<"Articles périmés à cette date:"<<endl;
   for(int i=0;i<in;i++)
   {
      Date D_nourriture(N[i]._date_de_peremption); ;
      if((D_nourriture.Compare_Date(limite->annee,limite->mois,limite->jour))==0)
	 cout<<N[i];
   }
}


void Caisse::Retour(int code,int quantite)
{int pos;
   pos=Retourne_Pos_Type(code);


   if(type==3) E[pos]._nombre_de_defectueux=E[pos]._nombre_de_defectueux+quantite;
   else cout<<"Seul les électroménagers ont un service après vente.."<<endl;

}


void Caisse::statistique()
{       unsigned int max=0;int code_max=0,code_benef=0;
char type_max=NULL,type_benef=NULL;
float benefice=0,val=0;
	  
 int i=0;
float valeur_caisse=0;
   for(i=0;i<in;i++)
   {
      if(N[i].Nombre_Vendu()>=max)
      {
	 max=N[i].Nombre_Vendu();
	 code_max=i;
	 type_max='n';
      }
      val=((N[i]._prix_ht-N[i]._prix_achat)*N[i].Nombre_Vendu());
	if(val>benefice)
      {
	 benefice=val;
	 type_benef='n';
	 code_benef=i;
      }
      valeur_caisse=valeur_caisse+(N[i]._prix_tt)*N[i].Nombre_Vendu();
   }

   for(i=0;i<ie;i++)
   {
      if(E[i].Nombre_Vendu()>=max)
      {
	 max=E[i].Nombre_Vendu();
	 code_max=i;
	 type_max='e';
	 code_benef=i;
      }
      val=((E[i]._prix_ht-E[i]._prix_achat)*E[i].Nombre_Vendu());
	if(val>benefice)
      {
	 benefice=val;
	 type_benef='e'; 
	 code_benef=i;
	}

      valeur_caisse=valeur_caisse+(E[i]._prix_tt)*E[i].Nombre_Vendu();

   }

   for(i=0;i<ic;i++)
   {
      if(C[i].Nombre_Vendu()>max)     //strictement superieur sinon c'est
	 //un electromenager
      {
	 max=C[i].Nombre_Vendu();
	 code_max=i;
	 type_max='c';
      }
     val=((C[i]._prix_ht-C[i]._prix_achat)*C[i].Nombre_Vendu());

 	if(val>benefice)
      {
	 benefice=val;
	 type_benef='c';
	 code_benef=i;
      }

      valeur_caisse=valeur_caisse+(C[i]._prix_tt)*C[i].Nombre_Vendu();

   }

   int choix=0;
   do
   {cout<<"Votre choix:"<<endl;
      cout<<"Article le plus vendu : 1"<<endl;
      cout<<"Article apportant le plus de bénéfice : 2"<<endl;
      cout<<"Valeur de la caisse : 3"<<endl;
      cout<<"Quitter...0 "<<endl;
      cout<<"Votre choix:";
      cin>>choix;
      if(choix==1)
      {cout<<"Article le plus vendu: "<<max<<" fois avec l'article:"<<endl;
	 if(type_max=='c') cout<<C[code_max];
	 else if(type_max=='n') cout<<N[code_max];
	 else if(type_max=='e') cout<<E[code_max];

      }
      else if(choix==2)
	 {
	    cout<<"Le benéfice maximum est : "<<benefice<<" Frs avec :"<<endl;
	    if(type_benef=='c') cout<<C[code_benef];
	    else if(type_benef=='n') cout<<N[code_benef];
	    else if(type_benef=='e') cout<<E[code_benef];


	 }
      else if(choix==3) cout<<"valeur de la caisse : "<<valeur_caisse<<" Frs"<<endl;

   }while(choix!=0);
}




void Caisse::Menu()
{
   int code=0;
   int continu=0;
   int i=0;
   continu=1;
   cout<<*D<<endl;

   do
   {
      cout<<endl<<"ENTRER VOTRE CHOIX "<<endl;
      cout<<"Vendre un Article : 1"<<endl;
      cout<<"Etat du stock : 2 "<<endl;
      cout<<"Statistique : 3 "<<endl;
      cout<<"Retourner un article défectueux : 4"<<endl;
      cout<<"Détail d'un electromenager : 5 "<<endl;
      cout<<"Etat d'un article : 6"<<endl;
      cout<<"Date de péremption de l'article nouriture le plus proche : 7"<<endl;
      cout<<"Quitter : 0"<<endl;
      cout<<"..."<<endl;
      cout<<"Choix :";
      cin>>choix;
      if(choix==1)
      {
	 cout<<"Entrer sa quantite"<<endl;
	 cin>>choix;
	 cout<<"Entrer son code"<<endl;
	 cin>>code;
	 Vendre(code,choix);
      }
      else if(choix==2)
	 {
	    for(i=0;i<in;i++) cout<<N[i];
	    for(i=0;i<ie;i++) cout<<E[i];
	    for(i=0;i<ic;i++) cout<<C[i];
	 }
      else if(choix==3)
	 {
	    statistique();
	 }
      else if(choix==4)
	 {
	    int quantite;
	    cout<<"Quantité:"<<endl;
	    cin>>quantite;
	    cout<<"code :"<<endl;
	    cin>>code;
	    Retour(code,quantite);
	 }
      else if(choix==5)
	 {
	    int pos;
	    cout<<"code :"<<endl;
	    cin>>code;
	    pos=Retourne_Pos_Type(code);
	    if(type==3)
	    {
	       int pos_composant;
	       cout<<"Détail des composants de l'ectromenager:"<<endl;
	       cout<<E[pos];
	       for(i=1;i<=E[pos]._nombre_de_composant;i++)
	       {
		  pos_composant=Retourne_Pos_Type(code+i);

		  cout<<C[pos_composant];
	       }
	    }
	    else cout<<"code electromenager incorrect.."<<endl;
	 }
      else if(choix==6)
	 {
	    int pos;
	    cout<<"code :"<<endl;
	    cin>>code;
	    pos=Retourne_Pos_Type(code);
	    if(type==1) cout<<N[pos];
	    else if(type==2) cout<<C[pos];
	    else if(type==3) cout<<E[pos];

	 }
      else if(choix==7)
	 {
	    Date *limite_peremption;
	    char l_p[10];
	    cout<<"Entrez la date de votre limite:"<<endl;
	    cin>>l_p;
	    limite_peremption=new Date(l_p);
	    Peremption_proche(limite_peremption);
	 }
   }while(choix!=0);
}


ostream& operator <<(ostream &os,const Caisse &C)
{
   os<<"--------------------"<<endl<<"Caisse :";
   os<<C._date<<endl;
   os<<"----------------"<<endl;
   return os;
}

