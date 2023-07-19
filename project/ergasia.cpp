#include "ergasia.h"
#include <iostream>
using namespace std;
#include <cstring>
#include <time.h>
#include <cstdlib>          

////////////////HIGHWAY///////////////
Highway::Highway(int Nsegs,double Percent,int K):_N(Nsegs),Percentage(Percent){
  srand(time(NULL));  
Percentage_holder=Percentage;
array1=new Highway_part*[Nsegs];    
cout<<"Highway is active"<<endl;
for(int i=0;i<Nsegs;i++){
number_of_tolls=rand()%5+1;
number_of_tolls2=rand()%5+1;  
cout<<endl;
cout<<"Pick a number for the capacity of this particular part:"<<endl;
cin>>capacity_of_vehicles_in_part;
Percentage=(Percentage_holder/100)*capacity_of_vehicles_in_part;
array1[i]=new Highway_part(capacity_of_vehicles_in_part,Nsegs,Percentage,i,K,number_of_tolls,number_of_tolls2);
vehicle_counter=vehicle_counter+array1[i]->get_no_of_vehicles();
}
for(int i=0;i<Nsegs-1;i++){
    link_parts(array1[i],array1[i+1]);
}

cout<<"There are "<<vehicle_counter<<" vehicles in the Highway"<<endl;

}


void Highway::link_parts(Highway_part*a,Highway_part* b){
   a->_pointernext(b);


}




void Highway::operate(){
for(int i=_N-1;i>=0;i--){
array1[i]->operate(Percentage);

}

vehicle_counter2=0;
for(int i=_N-2;i>=0;i--){
array1[i]->enter_highway();
vehicle_counter2=vehicle_counter2+array1[i]->get_no_of_vehicles();
}
vehicle_counter2=vehicle_counter2+array1[_N-1]->get_no_of_vehicles();
cout<<endl;
cout<<"After the Highway operations and entries there are "<<vehicle_counter2<<" vehicles in Highway"<<endl;
}



Highway::~Highway(){

for(int i=0;i<_N;i++){    
    cout<<endl;
    cout<<"We are in part "<<i<<endl;
 delete array1[i];
}
 delete [] array1;

cout<<"Highway is destructed"<<endl;

}                                   


/////////////HIGHWAY_PART//////////////            
                                                                                                                                                                                                                                                                                                           
Highway_part::Highway_part(int capacity_of_vehicles_in_part,int Nsegs,int Percentage,int highway_place,int K,int num_of_tolls,int num_of_tolls2):_capacity_of_vehicles_in_part(capacity_of_vehicles_in_part),_K(K),_Percentage(Percentage){
     place_of_part_in_highway=highway_place;   
    _Nsegs=Nsegs; 
    cout<<endl;
    cout<<"A part is  about to be constructed"<<endl;
    cout<<endl;
    cout<<"@@@@@@@@The part's name is "<<place_of_part_in_highway<<endl;
    cout<<endl;
    cout<<"This part has "<<num_of_tolls;
    cout<<" collectors toll(s)"<<endl;
    cout<<"This part has "<<num_of_tolls2;
    cout<<" etolls toll(s)"<<endl;
    vehicles=rand()%capacity_of_vehicles_in_part+1; 
    number_of_vehicles=vehicles;
    cout<<"This part has "<<get_no_of_vehicles()<<" vehicles when it's constructed"<<endl;
    cout<<endl;
    if(place_of_part_in_highway!=Nsegs-1){ 
    entr=new entrance(capacity_of_vehicles_in_part,Nsegs,highway_place,num_of_tolls,num_of_tolls2);
    }
    array2=new vehicle*[capacity_of_vehicles_in_part];
    for(int i=0;i<capacity_of_vehicles_in_part;i++){
    array2[i]=NULL;
    }
   
     cout<<endl;
    for(int i=0;i<vehicles;i++){
    array2[i]=new vehicle(Nsegs,place_of_part_in_highway);
    if(place_of_part_in_highway==Nsegs-1){
     array2[i]->set_destination(Nsegs-1); 
     cout<<"This vehicles  is in place  Nseg-1 of the highway and it should have same destination"<<endl;
     
    }
   
    cout<<"The vehicle number "<< i <<" of the array2 has destination "<<array2[i]->get_destination()<<" and its this : ";
    
    cout<<&(*array2[i])<<endl;
    cout<<endl;
    } 

 

}



int Highway_part::get_no_of_vehicles() const { 
return number_of_vehicles;
}




void Highway_part::operate(int percent){

cout<<"operate time "<<endl;
cout<<"we are in "<<place_of_part_in_highway<<endl;

 for(int i=0;i<_Percentage;i++){
        if(get_no_of_vehicles()<=_Percentage&&array2[i]!=NULL){ 
        if(array2[i]->ready_or_not()==1){
            continue;
        } 
        if(array2[i]->ready_or_not()!=1){                                                         
        array2[i]->ready_vehicle(); 
        ready_counter++;                            
        cout<<endl;  
          cout<<"This vehicle : "<<array2[i]<<" is ready "<<endl;                  
        
       count6++; }
        }

        if(get_no_of_vehicles()>_Percentage){
        random=rand()%_capacity_of_vehicles_in_part;
        if(array2[random]!=NULL&&array2[random]->ready_or_not()!=1){            
        array2[random]->ready_vehicle();    
         ready_counter++;    
        cout<<endl;                   
        cout<<"This vehicle : "<<&(*array2[random])<<" is ready "<<endl;
        count6++;    
    }
                                                                                                                            
    else if (array2[random]!=NULL&&array2[random]->ready_or_not()==1&&vehicles>_Percentage&&ready_counter<number_of_vehicles/*_capacity_of_vehicles_in_part*/){
     while(array2[random]!=NULL&&array2[random]->ready_or_not()==1){
         random=rand()%_capacity_of_vehicles_in_part;
     }
      if(array2[random]!=NULL){
    array2[random]->ready_vehicle(); 
     ready_counter++;       
    cout<<endl;     
     cout<<"This vehicle : "<<&(*array2[random])<<" is ready "<<endl;              
    
    count6++; }
    }

 

    }


    }

        

      if(place_of_part_in_highway!=_Nsegs-1&&ready_counter>pointernext->get_kenes_theseis()){
       random=rand()%_capacity_of_vehicles_in_part;
       if(array2[random]!=NULL&&array2[random]->ready_or_not()==1&&array2[random]->get_destination()>place_of_part_in_highway){
       pass(random);}
        
        else{
         while(array2[random]==NULL||array2[random]->ready_or_not()!=1||array2[random]->get_destination()==place_of_part_in_highway){
          random=rand()%_capacity_of_vehicles_in_part;}

          pass(random);
        }

     
      }
else{
 
while(array2[p]!=NULL){ 
    if(array2[p]==NULL||p==_capacity_of_vehicles_in_part){
        break;
        }  

    if((array2[p]!=NULL&&array2[p]->ready_or_not()!=1)){  
        p++;
        if(array2[p]==NULL||p==_capacity_of_vehicles_in_part) 
        break;       
    }
                                   
if((array2[p]!=NULL)&&array2[p]->get_destination()==place_of_part_in_highway){ 
 
    cout<<"The vehicle "<<array2[p]<< " has exited"<<endl;
    exit(p);                                                       
}
  else{
    if(array2[p]==NULL){break;}   
  
   
    pas=pass(p);
    if(pas==1){
     break;
    }
   
  }                            
 
  p++;


}

p=0;


}
cout<<endl;
cout<<"Specifically this part has the following vehicles: ";
for(int i=0;i<_capacity_of_vehicles_in_part+1;i++){
    cout<<"   "<< &(*array2[i]);
}




for(int u=0;u<percent;u++){ 
while(array2[j]!=NULL){ 
j++;
}   
for(int i=0; i<j;i++){
if(array2[j-1]==NULL){
array2[j-1]=array2[j];
array2[j]=NULL;}
else if (array2[j-1]!=NULL){
break;
}
}
}


                                    




cout<<endl;

if(place_of_part_in_highway!=_Nsegs-1){
cout<<"Part "<<place_of_part_in_highway+1<<" has the following vehicles: ";


for(int i=0;i<pointernext->_capacity_of_vehicles_in_part+1;i++){
    cout<<"   "<< &(*pointernext->array2[i]);
}
}



cout<<endl;





}


int  Highway_part::pass(int p){

 transporter=array2[p];                                                  
    
   
 while(this->pointernext->array2[n]!=NULL){
         n++;
  
     }
 if(this->pointernext->array2[n]==this->pointernext->array2[_capacity_of_vehicles_in_part]&&this->pointernext->array2[_capacity_of_vehicles_in_part]!=NULL){
         cout<<"Its full sorry";
         return 1;        
     }

 if(n<_capacity_of_vehicles_in_part){
array2[p]=NULL; 
number_of_vehicles--;  
ready_counter--;
cout<<"This vehicle : "<<transporter<<" has been transported"<<endl;
cout<<"The part "<<place_of_part_in_highway<<" has now "<<get_no_of_vehicles()<<" vehicles"<<endl; 
cout<<endl;
this->pointernext->ready_counter++;
this->pointernext->array2[n]=transporter;
this->pointernext->increase_number_of_vehicles(); 
count5++; 
cout<<"The part "<<this->pointernext->get_place_of_part_in_highway()<<" now has "<<this->pointernext->get_no_of_vehicles()<< " vehicles"<<endl;



}




return 0;
}


void Highway_part::exit(int p){                                   
array2[p]=NULL;
number_of_vehicles--;
ready_counter--;
cout<<"The part "<<place_of_part_in_highway<<" has now "<<get_no_of_vehicles()<<" vehicles"<<endl;                                      
}


void Highway_part::enter_highway(){
         
cout<<endl;
cout<<"$$$$$$$$$$$ in part"<<place_of_part_in_highway<<endl;
cout<<endl;



while(q<_capacity_of_vehicles_in_part){

if(array2[q]!=NULL)
q++;

if(count3==_K&&count4<2*_K){
count1=1;
}

if(count4==2*_K){
cout<<"Max vehicles went through"<<endl;
break;
}


if(count1==0&&count3<_K){
if(q<_capacity_of_vehicles_in_part&&array2[q]==NULL){
cout<<endl;
array2[q]=entr->enter1();  
number_of_vehicles++;
count3++;
count1++;

q++;
}}

if(count1==1&&count4<2*_K){
if(q<_capacity_of_vehicles_in_part&&array2[q]==NULL){
cout<<endl;
array2[q]=entr->enter2();

number_of_vehicles++;
count4++;
q++;
   
if(count3<_K){              
count1=0;}
}}

}
q=0;

if(count3==_K&&count4==2*_K){
_K=_K+1;
}


if(q==_capacity_of_vehicles_in_part){
if(count3<_K&&count4<2*_K){
_K=_K-1;                                                  
cout<<"There are delays in the entrance of the Node "<<place_of_part_in_highway+1<<endl;
}


if(count5<count6){                
cout<<"There are delays after the Node"<<place_of_part_in_highway+1<<endl;
}
else{                                                          
 cout<< "Kepp safety distance after the node "<< place_of_part_in_highway+1<<endl; 
}

}


cout<<endl;
cout<<"After all the entries this part has the following vehicles : ";
for(int i=0;i<_capacity_of_vehicles_in_part;i++){
cout<<&(*array2[i])<<"  ";
}
cout<<endl;

}


Highway_part::~Highway_part(){

if(place_of_part_in_highway!=_Nsegs){
delete entr;}

cout<<"This part has the following vehicles: ";
for(int i=0;i<_capacity_of_vehicles_in_part;i++){
    cout<<"  "<<&(*array2[i]);
}
cout<<endl;
for(int i=0;i<_capacity_of_vehicles_in_part;i++){
    if(array2[i]!=NULL){
        cout<<endl;
    cout<<"The vehicle "<<&(*array2[i])<<" is about to be destroyed "<<endl;
    
 delete array2[i];}

}
 delete [] array2;
 
 cout<<endl;
cout<<"Highway_part is destructed"<<endl;
}

/////////////////TOLLS//////////////////////////
tolls::tolls(){
    cout<<endl;
    cout<<"Constructing tolls"<<endl;
    
}


tolls::~tolls(){
cout<<"Destroying toll"<<endl;
}


//////////////////TOLLS_COLLECTORS//////////////
tolls_collector::tolls_collector(int capacity_of_vehicles_in_part,int Nsegs,int parts_place):tolls(),capacity_of_vehicles_in_toll1(capacity_of_vehicles_in_part),_Nsegs(Nsegs),_place(parts_place){
   cout<<"Constructing a collectors tolls toll for the part "<<parts_place<<endl;
    array3=new vehicle*[capacity_of_vehicles_in_toll1];
    for(int i=0;i<capacity_of_vehicles_in_toll1;i++){
    array3[i]=new vehicle(Nsegs,parts_place);
    cout<<"The vehicle "<<array3[i]<<" is constructed "<<endl;
    } 
    cout<<endl;
}


vehicle*tolls_collector::entering(){ 
cout<<"Collectors"<<endl;
for(int i=0;i<capacity_of_vehicles_in_toll1;i++){
cout<<&(*array3[i])<<"  ";
}

cout<<endl;
ptr =array3[0];
array3[0]=NULL;

for(int i=1;i<capacity_of_vehicles_in_toll1;i++){   
    for(count=0;count<1;count++){
        array3[i-1]=array3[i];     
        array3[i]=NULL;
    }
}

for(int i=0;i<capacity_of_vehicles_in_toll1;i++){
cout<<&(*array3[i])<<"  ";
}

cout<<endl;

array3[capacity_of_vehicles_in_toll1-1]=new vehicle(_Nsegs,_place);

cout<<"This collectors tolls toll has the following vehicles : ";
for(int i=0;i<capacity_of_vehicles_in_toll1;i++){
cout<<&(*array3[i])<<"  ";
}

cout<<endl;

return ptr;

}


tolls_collector::~tolls_collector(){

for(int i=0;i<capacity_of_vehicles_in_toll1;i++){
 if(array3[i]!=NULL)
 cout<<"Destroying the vehicle "<<array3[i]<<endl; 
 delete array3[i];
}
 delete [] array3;

cout<<"Tolls_collector toll of part "<<_place<<" is destructed"<<endl;

}

//////////////TOLLS_ETOLLS///////////////////

tolls_etolls::tolls_etolls(int capacity_of_vehicles_in_part,int Nsegs,int parts_place ):tolls(),capacity_of_vehicles_in_toll2(capacity_of_vehicles_in_part),_Nsegs2(Nsegs),_place2(parts_place){
    cout<<"Constructing an etolls toll for the part "<<parts_place<<endl;
    array4=new vehicle*[capacity_of_vehicles_in_toll2];
    for(int i=0;i<capacity_of_vehicles_in_toll2;i++){
    array4[i]=new vehicle(Nsegs,parts_place);
    cout<<"The vehicle "<<array4[i]<<" is constructed "<<endl;
    } 

}




vehicle*tolls_etolls::entering(){
cout<<"Etolls"<<endl;
for(int i=0;i<capacity_of_vehicles_in_toll2;i++){
cout<<&(*array4[i])<<"  ";
}
cout<<endl;

ptr2 =array4[0];
array4[0]=NULL;

for(int i=1;i<capacity_of_vehicles_in_toll2;i++){   
    for(count=0;count<1;count++){
        array4[i-1]=array4[i];           
        array4[i]=NULL;
    }
}

for(int i=0;i<capacity_of_vehicles_in_toll2;i++){
cout<<&(*array4[i])<<"  ";
}
cout<<endl;

array4[capacity_of_vehicles_in_toll2-1]=new vehicle(_Nsegs2,_place2);

cout<<"This etolls toll has the following vehicles : ";
for(int i=0;i<capacity_of_vehicles_in_toll2;i++){
cout<<&(*array4[i])<<"  ";
}
cout<<endl;

return ptr2;

}



tolls_etolls::~tolls_etolls(){

for(int i=0;i<capacity_of_vehicles_in_toll2;i++){
  if(array4[i]!=NULL) 
  cout<<"Destroying the vehicle "<<array4[i]<<endl; 
 delete array4[i];
}
 delete [] array4;
cout<<"Tolls etolls toll of part "<<_place2<<" is destructed"<<endl;
}

///////////////VEHICLE///////////////

vehicle::vehicle(int Nsegs,int place):vehicle_place(place){

if(Nsegs!=place){
set_destination((rand()%((Nsegs-1) - vehicle_place +1 ))+ vehicle_place );   

} 
if(Nsegs==place){
    set_destination(place);
}

cout<<"A vehicle is constructed"<<endl;
}



vehicle::~vehicle(){

    cout<<"Destroying a vehicle"<<endl;
}


///////Entrance//////
entrance::entrance(int capacity_of_vehicles_in_part,int Nsegs,int place,int num_of_tolls,int num_of_tolls2 ):_number_of_tolls(num_of_tolls),_number_of_tolls2(num_of_tolls2){
    cout<<"Constructing an entrance"<<endl;
    cout<<"The entrance of part "<<place<<" is constructed"<<endl;
    name_of_entrance=place;
    tolls1=new tolls*[num_of_tolls];    
    for(int i=0;i<num_of_tolls;i++){
    tolls1[i]=new tolls_collector(capacity_of_vehicles_in_part,Nsegs,place);}


    tolls2=new tolls*[num_of_tolls2];    
    for(int i=0;i<num_of_tolls2;i++){
    tolls2[i]=new tolls_etolls(capacity_of_vehicles_in_part,Nsegs,place);}



}

entrance::~entrance(){
    cout<<"Destroying the entrance"<<" of part "<<name_of_entrance<<endl;
  for(int i=0;i<_number_of_tolls;i++){
  if(tolls1[i]!=NULL)  
 delete tolls1[i];
}
 delete [] tolls1;


for(int i=0;i<_number_of_tolls2;i++){
  if(tolls2[i]!=NULL)  
 delete tolls2[i];
}
 delete [] tolls2;
 


}




vehicle * entrance::enter1(){  
if(t<_number_of_tolls){
pointer1=tolls1[t]->entering();
t++;
return pointer1;}

if(t==_number_of_tolls){
t=0;
pointer1=tolls1[t]->entering();   
}

return pointer1;
}

vehicle* entrance::enter2(){
if(t2<_number_of_tolls2){
pointer2=tolls2[t2]->entering();
t2++;
return pointer2;}

if(t2==_number_of_tolls2){
t2=0;
pointer2=tolls2[t2]->entering();   
}


return pointer2;

}














                                       