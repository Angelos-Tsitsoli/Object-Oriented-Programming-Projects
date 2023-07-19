#include <iostream>
using namespace std;
#include <cstring>
#include <time.h>
#include <cstdlib>


class creature_society;

////////CREATURE////////
class creature{
protected:
int place_of_creature;
int creatures_life=0;
public:
creature(int);

bool is_a_zombie();

virtual bool is_a_good()=0;

void gets_beaten(creature_society*a,int n);

virtual void gets_blessed(creature_society*a,int n)=0;

void link_with_society(creature_society*);

virtual void clone(creature_society*a,int n,int)=0; 

virtual ~creature();

};

////////GOOD CREATURE/////////
class good_creature : public creature{
private:
int good_thrsh;
int g_thrsh;
int __L;
string good_creatures_name;
public:

good_creature(int ,int );

good_creature(good_creature &);

~good_creature();

bool is_a_good();

void clone( creature_society*,int,int );

void gets_blessed(creature_society*,int );

};


///////////BAD CREATURE//////////////
class bad_creature : public creature{
private:
int bad_thrsh;
int b_thrsh;
int ___L;
string bad_creatures_name;
public:

bad_creature(int ,int );

bad_creature(bad_creature &);

~bad_creature();

bool is_a_good();

void clone(creature_society*,int ,int);

void gets_blessed(creature_society*a,int n);

};

/////////////CREATURE SOCIETY////////
class creature_society{
  private:
  int random_is_good_or_bad=0;
  int Nsize=0;
  int life=0;
  int _good_thrsh=0;
  int _bad_thrsh=0;
  public:
 int  good_creature_counter=0;
 int zombie_counter=0;
 creature** array;
  
  creature_society(int ,int ,int ,int );
 
  void beat_society(int);

  void bless_society(int);

 const  int no_of_goods();

  const int no_of_zombies();
 
  int do_something_with_a_random_creature(int ,int );
 
  void clone_next(int);

  void clone_zombies(int);

   void society_of_goods_or_zombies();
 
   ~creature_society();
    
};
