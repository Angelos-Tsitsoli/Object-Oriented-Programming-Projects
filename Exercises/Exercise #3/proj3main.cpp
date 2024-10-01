#include <iostream>
using namespace std;
#include <cstring>
#include <cstdlib>
#include "proj3.h"
#include <time.h>

int main(int args,char*argv[]){

int N=atoi(argv[1]);
int M=atoi(argv[2]);
int L=atoi(argv[3]);
int good_thrsh=atoi(argv[4]);
int bad_thrsh=atoi(argv[5]);
int n=0;
int p=0;
creature_society koinonia(N,L,good_thrsh,bad_thrsh);

srand(time(NULL));

for(int a=0;a<M;a++){
n=rand()%2;
p=rand()%N;
koinonia.do_something_with_a_random_creature(n,p);
} 


koinonia.society_of_goods_or_zombies();

return 0;
}

