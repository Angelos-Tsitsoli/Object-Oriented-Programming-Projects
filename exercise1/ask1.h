#include <iostream>
#include <cstring>
using namespace std;
#include <ctime>
#include <cstdlib>


/////////////////BOOK///////////////////////////////
class book{  
public:
   std::string name,writers_full_name;
   int ISBN;

 book( );
                       

};

///////////////////////SHELF//////////////////////
class shelf{
private :
 book** array;
 int Nmax=0;
 int book_counter_shelf=0;
public:
~shelf(){ 
  cout<<" shelf is being destroyed"<<endl;
  delete[] array;}


shelf(int n){
  cout<<" shelf is being constructed"<<endl;
  Nmax=n;
  array=new book*[n];


  for(int h=0;h<Nmax;h++){
    array[h]=NULL;

  }
  }
   

bool place_book_shelf(book* a );


bool take_book_shelf();

void print_shelf();
};

/////////////////////CUPBOARD/////////////////////
class cupboard{
private:
 shelf top_cupboard;
 shelf bot_cupboard;
public:

~cupboard(){
  cout<<" cupboard is being destroyed"<<endl;}


cupboard(int n):top_cupboard(n),bot_cupboard(n)
{ cout<<" cupboard is being constructed"<<endl;}
  

bool place_book_cupboard(book* a ,int l);

bool take_book_cupboard(int l);

void print_cupboard();

};




////////////////////BASE/////////////////////////////
class base{
public:


~base(){
   cout<<" base is being destroyed"<<endl;}


base(){
  cout<<" base is being constructed"<<endl;}

};


////////////////////LIBRARY/////////////////////
class library{
private:
 shelf top;
 shelf mid;
 shelf bot;
 cupboard locker;
 base library_base;
public:
int book_counter=0;
~library(){ 
   cout<< "This library is being destroyed"<<endl;}


library(int n):top(n),mid(n),bot(n),locker(n)
{ cout<< "This library is being constructed"<<endl;}


bool place_book_library(book* a ,int l);


bool take_book_library(int g);

void print_library();

};








