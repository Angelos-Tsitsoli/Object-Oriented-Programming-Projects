#include "ergasia.h"
#include <iostream>
using namespace std;
#include <cstring>
#include <time.h>
#include <cstdlib>

int main(int argc,char*argv[]){
int N;
int Nsegs;
int K;
int Percent;
N=atoi(argv[1]);
Nsegs=atoi(argv[2]);
K=atoi(argv[3]);    
Percent=atoi(argv[4]);
                        
Highway attiki(Nsegs,Percent,K);
for(int i=0; i<N;i++){  
attiki.operate();
}

return 0;

}