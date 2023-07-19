#include <iostream>
using namespace std;
#include <cstring>
#include <time.h>
#include <cstdlib>
#include "proj3.h"


//////////////CREATURE///////////////////
creature::creature(int L)
{
  creatures_life=L;
  cout<<"Creating a creature"<<endl;
}


 bool creature::is_a_zombie(){
  if(creatures_life==0){
  return true;}
else return false;  
}

void creature::gets_beaten(creature_society*a,int n){
if(is_a_zombie()==false)
 creatures_life=creatures_life-1;
 cout<<"The creature in position "<<place_of_creature<<" of the society array was beaten, this creature's life is "<<creatures_life<<endl;
 if(a->array[n]->is_a_good()==1&&a->array[n]->creatures_life==0){
 a->good_creature_counter--;
 a->zombie_counter++;
 }

}


void creature::link_with_society(creature_society* a)
{
int i=0;
int this_place=0;
while(this!=a->array[i]){
i++;
}
place_of_creature=i;
cout<<"This creatures place in the array is:"<<place_of_creature<<endl;
}



creature::~creature(){
  cout<<"Destroying a creature"<<endl;
}





////////GOOD CREATURE/////////

good_creature::good_creature(int L,int good_thrsh):creature(L),g_thrsh(good_thrsh),__L(L){
string names[10]={"Kayle","Malphite","Yasuo","Zed","Lucian","Teemo","Rumble","Yorik","Sett","Darius"};
good_creatures_name.assign(names[rand()%9]);
  cout<<"Creating a good creature"<<endl;
  cout<<"This creatures name is "<<good_creatures_name<<endl; 
  cout<<"This creatures life is "<<creatures_life<<endl; 
  
}



good_creature::good_creature(good_creature &a):creature(__L),g_thrsh(good_thrsh){
this->creatures_life=a.creatures_life;
this->good_creatures_name=a.good_creatures_name;

}



void good_creature::clone(creature_society*a,int n,int b){
  if(n==b-1){
    if(a->array[0]->is_a_good()==1){
      a->good_creature_counter--;
    }
    delete a->array[0];
     good_creature*ptr10=new good_creature(*this);
     cout<<"The creature in place "<<n<<" was cloned in the next place"<<endl;
     a->good_creature_counter++;
     a->array[0]=ptr10;
     a->array[0]->link_with_society(a);
     int p=0;
     cout<<"The new creature in place"<<p;
     cout<<" has the name "<<ptr10->good_creatures_name<<endl;
  }
else{
   if(a->array[n+1]->is_a_good()==1){
      a->good_creature_counter--;
    }
 delete a->array[n+1];
  good_creature*ptr10=new good_creature(*this);
  cout<<"The creature in place "<<n<<" was cloned in the next place"<<endl;
  a->good_creature_counter++;
  a->array[n+1]=ptr10;
  a->array[n+1]->link_with_society(a);
  cout<<"The new creature in place"<<n+1;
  cout<<" has the name "<<ptr10->good_creatures_name<<endl;
}
}


bool good_creature::is_a_good(){
  return true;
}

void good_creature::gets_blessed(creature_society*a,int n){
if(is_a_zombie()==false)
 creatures_life=creatures_life+1; 
cout<<"The creature in position "<<place_of_creature<<" of the society array was blessed, this creature's life is "<<creatures_life<<endl;

if(creatures_life>=g_thrsh){
 a->clone_next(n);}
}


good_creature::~good_creature(){
  cout<<"Destroying a good creature"<<endl;
}


///////////BAD CREATURE//////////////
bad_creature::bad_creature(int L,int bad_thrsh):creature(L),b_thrsh(bad_thrsh){
  string names[10]={"Jurgen","Pep","Carlo","Jose","Antonio","Luis","Mikel","Nuno","Marcelo","Thomas"};
  bad_creatures_name.assign(names[rand()%9]);
  cout<<"Creating a bad creature"<<endl;
  cout<<"This creatures name is "<<bad_creatures_name<<endl;
  cout<<"This creatures life is "<<creatures_life<<endl; 
}


bad_creature::bad_creature(bad_creature &a):creature(___L),b_thrsh(bad_thrsh){
this->creatures_life=a.creatures_life;
this->bad_creatures_name=a.bad_creatures_name;
}


void bad_creature::clone(creature_society*a,int n,int b ){
  if(a->array[n+1]->is_a_good()==1){
    if(a->good_creature_counter!=0){
   a->good_creature_counter--;}
  }
 delete a->array[n+1];
  bad_creature*ptr10=new bad_creature(*this);
  cout<<"The creature in place "<<n<<" was cloned in the next place"<<endl;
  a->array[n+1]=ptr10;
  a->array[n+1]->link_with_society(a);
  cout<<"The new creature in place"<<n+1;
   cout<<" has the name "<<ptr10->bad_creatures_name<<endl;

}


bool bad_creature::is_a_good(){
  return false;
}




void bad_creature::gets_blessed(creature_society*a,int n ){
if(is_a_zombie()==false)
 creatures_life=creatures_life+1; 
 cout<<"The creature in position "<<place_of_creature<<" of the society array was blessed, this creature's life is "<<creatures_life<<endl;

if(creatures_life>=b_thrsh)
a->clone_zombies(n);
}


bad_creature::~bad_creature() {
  cout<<"Destroying a bad creature"<<endl;
}





/////////////CREATURE SOCIETY////////

 creature_society::creature_society(int N,int L,int good_thrsh,int bad_thrsh):Nsize(N),life(L),_good_thrsh(good_thrsh),_bad_thrsh(bad_thrsh) {

  
    cout<<"Creating a society"<<endl;


     array=new creature*[N];
   

      for(int h=0;h<N;h++){
         array[h]=NULL; }



  srand(time(NULL));

  for(int i=0;i<N;i++){

    random_is_good_or_bad=rand()%2;

    if(random_is_good_or_bad==1){    
     good_creature*p=new good_creature(L,good_thrsh); 
     array[i]= p; 
     array[i]->link_with_society(this);
     good_creature_counter++;
    }


    if(random_is_good_or_bad==0){
    bad_creature*g=new bad_creature(L,bad_thrsh);
     array[i]=g;
     array[i]->link_with_society(this);
    }
    
  }
 
}


void creature_society::beat_society(int n){
array[n]->gets_beaten(this,n);
}


void creature_society::bless_society(int n){
array[n]->gets_blessed(this,n);
}


const int creature_society::no_of_goods(){
    return good_creature_counter;
  }

const int creature_society::no_of_zombies(){
    return zombie_counter;
  }


int creature_society::do_something_with_a_random_creature(int a,int b){
   if(a==1){
   beat_society(b);
   }
   if(a==0){
   bless_society(b);
   }
   return 0;
 }


 void creature_society::clone_next(int n){
 array[n]->clone(this,n,Nsize);
}


void creature_society::clone_zombies(int n){
for(int i=n+1;i<Nsize;i++,n++){
if(array[i]->is_a_zombie()==true){
zombie_counter--;
array[n]->clone(this,n,Nsize);
}
continue;
}


}


void creature_society::society_of_goods_or_zombies(){
   if(no_of_goods()==Nsize){
   cout<<"Good Dominates in the World!"<<endl;
   cout<<"There are "<<good_creature_counter<<endl;}
   else
   if(no_of_zombies()==Nsize){
   cout<<"This is a dead society"<<endl;
cout<<"There are "<<zombie_counter<<endl;
   }


  else cout<<"Try again to improve the world"<<endl;

   }



creature_society::~creature_society(){
    cout<<"Destroying a society"<<endl;
    int i=0;
    for(int i=0;i<Nsize;i++){
     delete array[i];
     }
 

   delete [] array;
  }
