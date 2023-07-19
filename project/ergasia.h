
#include <iostream>
using namespace std;
#include <cstring>
#include <time.h>
#include <cstdlib>

class Highway_part; 

class Highway{ 
private:
int capacity_of_vehicles_in_part;

int _N=0;
double Percentage;
double Percentage_holder;
Highway_part**array1;
int number_of_tolls;
int number_of_tolls2;
int vehicle_counter=0;
int vehicle_counter2=0;
public:

Highway(int ,double,int);

~Highway();

void operate();

void link_parts(Highway_part*,Highway_part*);



};


class vehicle{ 
private:      
int ready=0;  
int vehicle_place; 
int destination;
public: 
vehicle(int,int);
~vehicle();

int ready_or_not(){
return ready;
}
void ready_vehicle(){
ready=1;}
void set_destination(int x){
destination=x;

}
int get_destination()const{
return destination;
}


};


class tolls{
public:
tolls();
virtual vehicle* entering()=0;
virtual ~tolls();
};


class tolls_collector:public tolls{
private:
int capacity_of_vehicles_in_toll1;
int _Nsegs=0;
int _place=0;  
vehicle**array3;
vehicle * ptr;
int count;
public:
vehicle* entering();
tolls_collector(int,int,int);
~tolls_collector();
};


class tolls_etolls:public tolls{ 
private:
int capacity_of_vehicles_in_toll2;
int _Nsegs2=0;
int _place2=0; 
vehicle**array4;
vehicle * ptr2;
int count;
public:
vehicle* entering();
tolls_etolls(int,int,int);
~tolls_etolls();
};

class tolls_etolls;
class tolls_collector;

class entrance{   

int name_of_entrance;
int t=0;
int t2=0;
int _number_of_tolls; 
int _number_of_tolls2;
tolls** tolls1;
tolls** tolls2;
vehicle * pointer1;
vehicle * pointer2;
public:
entrance(int,int,int,int,int);
vehicle* enter1();
vehicle* enter2();
~entrance();
};


class Highway_part{
private:
int _capacity_of_vehicles_in_part;
int _Percentage;
int _Nsegs;
int _K;
int vehicles;
int random;
int p=0;
int pas=0; 
int j=0;
int n=0;
int q=0;
int count1=0;
int count3=0;
int count4=0;
entrance * entr; 
vehicle* transporter;
int count5;
int count6;
int number_of_vehicles;
int place_of_part_in_highway;
vehicle**array2;
int ready_counter;
int kenes_theseis;
Highway_part* pointernext;
public:



              


void increase_number_of_vehicles(){
number_of_vehicles++;
}








int get_place_of_part_in_highway() const{
return place_of_part_in_highway;
}




Highway_part * _pointernext(Highway_part * b){
                          
 return this->pointernext=b;        
}


int get_kenes_theseis()  {
for(int i=0; i<_capacity_of_vehicles_in_part;i++){
if(array2[i]==NULL){
kenes_theseis++;}

}
return kenes_theseis;
}



Highway_part(int,int,int,int,int,int,int);
~Highway_part();
void exit(int);
int pass(int p);
int get_no_of_vehicles() const ;
void operate(int);
void enter_highway();
};



