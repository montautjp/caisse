#include <iostream.h>
#include <fstream.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>



//#define TVA_NOURRITURE 5
//#define TVA_ELECTROMENAGER 20.6
#define NDEBUG 0//Mettre a 1 pour le DEBUGGAGE sinon 0
#define VERSION 2.02
#define NMAX    80
/* VIVE LES RALLONGES*/

#ifndef ARTICLE
#include "article.h"
#define ARTICLE
#endif

#ifndef NOURRI
#include "nourri.h"
#define NOURRI
#endif

#ifndef COMPOS
#include "compos.h"
#define COMPOS
#endif

#ifndef ELECTRO
#include "electro.h"
#define ELECTRO
#endif

#ifndef DATE
#include "date.h"
#define DATE
#endif

#ifndef CAISSE
#include "caisse.h"
#define CAISSE
#endif


