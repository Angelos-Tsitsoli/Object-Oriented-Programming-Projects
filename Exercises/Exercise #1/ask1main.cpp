#include <iostream>
using namespace std;
#include "ask1.h"
#include <cstring>
#include <stdlib.h>
#include <time.h>


int main (int argc,char*argv[]){
int Nmax;
int K1;
int K2;
int L;
Nmax=atoi(argv[1]);
K1=atoi(argv[2]);
K2=atoi(argv[3]);    
L=atoi(argv[4]);

library bibliothiki(Nmax);
book* array=new book[L];

srand(time(NULL));   
for(int i=0;i<K1;i++){
int u=0;                                       
u= rand() %5 + 1 ;
bibliothiki.place_book_library(&array[i],u);}


for(int i=0;i<K2;i++){
int g=0;                                              
g= (rand() %5) + 1 ;
bibliothiki.take_book_library(g);}

bibliothiki.print_library();

delete [] array;
return 0;

}


