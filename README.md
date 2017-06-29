# caisse
build :
gxx -c electro.cpp -o electro.o 

gxx -c nourri.cpp -o nourri.o 
 
gxx -c compos.cpp -o compos.o 
 
gxx -c caisse.cpp -o caisse.o 
 
gxx -c article.cpp -o article.o  
 
gxx -c date.cpp -o date.o 
 
gxx compos.o nourri.o electro.o caisse.o article.o date.o -o main main.cpp 
