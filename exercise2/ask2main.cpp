#include<iostream>
using namespace std;
#include "ask2.h"

int main(int argc,char*argv[]){
int K;
int M;
int N;
int L;
K=atoi(argv[1]);
M=atoi(argv[2]);
N=atoi(argv[3]);    
L=atoi(argv[4]);
bank trapeza;
int n=0;
for (int i=0;i<M;i++){
    for(int j=1;j<=N;j++){
        trapeza.enter(K);
        n=trapeza.waiting_customers();
  
        }
    for(int g=0;g<=n;g++){
    trapeza.serve(K,L);}
   

  
}

for(int u=0;u<trapeza.others_counter;u++){
    trapeza.serve(K,L);
}



return 0;

}