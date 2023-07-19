#include <iostream>
#include "ask1.h"
#include <cstring>
using namespace std;
#include <time.h>
#include <cstdlib>

////////////////////BOOK//////////////////////
book::book(){  
  name="...";
  ISBN=0;
  writers_full_name="...";                                   
 std::string names [5]={"snow","sun","red","flower","purple"}; 
 std:: string writers_full_names[5]={"John","James","Will","Anna","Mary"};                                               
 int number,number2,number3;
 number=0;
 number2=0;
 number3=0;                                                                                
 number= rand() %5 +1 ;
 number2= rand() %4 ; 
 number3= rand() %4 ;                                       
 ISBN=number;
 name.assign(names[number2]);
 writers_full_name.assign(writers_full_names[number3]);
                                                                             
}

///////////////////SHELF////////////////////////
bool shelf::place_book_shelf(book* a){
if(array[Nmax-1]!=NULL){
    cout<<"Array is full"<<endl;
    return false;}

 for(int v=0;v<Nmax;v++){
  
  if(array[v]==NULL){
    array[v]=a;
    book_counter_shelf=book_counter_shelf +1;
    
 cout<<"The book that was placed is:"<<endl;
 
 cout<<a->ISBN<<",";
 cout<<a->name<<",";
 cout<<a->writers_full_name<<endl;
 
  break;
  }
  else{
    continue;
  }
 }   

 return true;                                                 
}

bool shelf::take_book_shelf(){
int number;
number= rand() %(Nmax-1);
if(array[number]!=NULL){
array[number]=NULL;
book_counter_shelf=book_counter_shelf -1;
cout<<"There are ";
cout<<book_counter_shelf;
cout<<" books in this particular shelf"<<endl;
print_shelf();}
else {
  cout<<"This place in array is NULL"<<endl;
  return false;
}

return true;
}

void shelf::print_shelf(){
for(int v=0;v<Nmax;v++)  {
  
  if(array[v]!=NULL){
    
    cout<<array[v]->ISBN<<",";
    cout<<array[v]->name<<",";
    cout<<array[v]->writers_full_name<<endl;
    
  }

 else{
   continue;
 }

}                                                     
}


/////////////////CUPBOARD////////////////////
bool cupboard::place_book_cupboard(book* a,int l){
 bool c;
if(l==4){
  cout<<"placing book in top cupboard shelf"<<endl;
 c=top_cupboard.place_book_shelf(a);
 if(c==true)
 return true;
}

if(l==5){
  cout<<"placing book in bottom cupboard shelf"<<endl;
 c=bot_cupboard.place_book_shelf(a);
 if(c==true)
 return true;

}

return false;

}


bool cupboard::take_book_cupboard(int l){
  bool o;
if(l==4){
  cout<<"taking book from top cupboard shelf"<<endl;
 o=top_cupboard.take_book_shelf();
 if(o==true)
 return true;

}

if(l==5){
  cout<<"taking book from bottom cupboard shelf"<<endl;
 o=bot_cupboard.take_book_shelf();
 if(o==true)
 return true;
}


return false;

}


void cupboard::print_cupboard(){
  top_cupboard.print_shelf();
  bot_cupboard.print_shelf();

}


//////////////LIBRARY///////////////////////
bool library::place_book_library(book* a ,int l){
bool p;
if(l==1){ 
  cout<<"placing book in top shelf"<<endl;
 p=top.place_book_shelf(a);
 if(p==true)
 book_counter=book_counter +1;
 }

if(l==2){
  cout<<"placing book in middle shelf"<<endl;
  p=mid.place_book_shelf(a);
  if(p==true)
  book_counter=book_counter +1;
  }

if(l==3){
  cout<<"placing book in bottom shelf"<<endl;
  p=bot.place_book_shelf(a);
  if(p==true)
  book_counter=book_counter +1;
  }

if(l==4||l==5){
 p=locker.place_book_cupboard(a,l);
 if(p==true)
 book_counter=book_counter +1;
 }

return true;
}

bool library::take_book_library(int g){
bool n;
if(g==1){
  cout<<"taking book from top shelf"<<endl;
  n=top.take_book_shelf();
  if(n==true){
    book_counter=book_counter -1;}
cout<<"There are ";
cout<<book_counter;
cout<<" books in the library"<<endl;
  }

if(g==2){
  cout<<"taking book from middle shelf"<<endl;
  n=mid.take_book_shelf();
   if(n==true){
    book_counter=book_counter -1;}
cout<<"There are ";
cout<<book_counter;
cout<<" books in the library"<<endl;  
  }

if(g==3){
  cout<<"taking book from bottom shelf"<<endl;
  n=bot.take_book_shelf();
   if(n==true){
    book_counter=book_counter -1;}
cout<<"There are ";
cout<<book_counter;
cout<<" books in the library"<<endl;    
  }

if(g==4||g==5){
  n=locker.take_book_cupboard(g);
   if(n==true){
    book_counter=book_counter -1;}
cout<<"There are ";
cout<<book_counter;
cout<<" books in the library"<<endl;
  }

return true;
}


void library::print_library(){
  top.print_shelf();
  mid.print_shelf();
  bot.print_shelf();
  locker.print_cupboard();

}












