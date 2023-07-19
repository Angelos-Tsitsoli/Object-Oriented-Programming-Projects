#include <iostream>
using namespace std;

class cashier{
private:
 int open_flag;
 int serving_flag;
 int customers_served;
public:
 ~cashier(){}

 cashier(){
     open_flag=0;
     serving_flag=0;
 }

 void open(){
     open_flag=1;
     customers_served=0;
 }

 void close(){
     open_flag=0;
 }  

 void serve(){
     serving_flag=1;
 }

 void free(int L){
    serving_flag=0;
    customers_served++;
    if(customers_served==L){
        close();
        cout<<"Cashier overused and needs to be closed"<<endl;
    }

}



 int  is_open(){
  return open_flag;
 }

 int  is_free(){
   return serving_flag;
 }

};

class bank{
private:
 int last_customer;
 int curr_serving;
 int counter=0;
 cashier cash1;
 cashier cash2;
 cashier cash3;
 cashier cash4;
 cashier cash5;
 int serve_holder=0;
public:
int others_counter=0;

 ~bank(){}
 bank()
 {
 open(&cash1);
  last_customer=1;
  curr_serving=1;
 }

 void open(cashier* a){
    a->open();
     if(a==&cash1)
      cout<<"cash1 which is now open"<<endl;

     if(a==&cash2)
      cout<<"cash2 which is now open"<<endl;
  
     if(a==&cash3)
      cout<<"cash3 which is now open"<<endl;
      
     if(a==&cash4)
      cout<<"cash4 which is now open"<<endl;
      
     if(a==&cash5)
      cout<<"cash5 which is now open"<<endl;
 }


 bool check_to_open(int K){
  if(waiting_customers()>(open_cashiers()*K))
     return true;

  return false;
 }



 bool enter(int K){
     if(check_to_open(K)==false){  
      last_customer++;        
    }   
     else{
     if(cash1.is_open()==1&&cash2.is_open()==0){
      open(&cash2);
      last_customer++; 
      return true;}
      
     if(cash2.is_open()==1&&cash3.is_open()==0){
      open(&cash3);
      last_customer++; 
      return true;}

     if(cash3.is_open()==1&&cash4.is_open()==0){
      open(&cash4);
      last_customer++; 
      return true;}

     if(cash4.is_open()==1&&cash5.is_open()==0){
      open(&cash5);
      last_customer++; 
      return true;}

     if(cash5.is_open()==1&&cash1.is_open()==0){
      open(&cash1);
      last_customer++; 
      return true;}

    }
   if(cash1.is_open()==1&&cash2.is_open()==1&&cash3.is_open()==1&&cash4.is_open()==1&&cash5.is_open()==1){
 cout<<"Sorry you cannot enter untill some customers are served!"<<endl;
 others_counter++;}
return true;
 }


 bool serve(int K,int L){

  if(cash1.is_open()==0&&cash2.is_open()==0&&cash3.is_open()==0&&cash4.is_open()==0&&cash5.is_open()==0){
    open(&cash1);
    cash1.serve();
    serve_holder=1;
    cout<<"Customer no:";
    cout<<curr_serving<<endl;
    cout<<" by :  "<<endl;
    cout<<serve_holder<<endl;
    cash1.free(L);
      exit(K);
    return true;
    }

    if(serve_holder==0){
      cash1.serve();
      serve_holder=1;
      cout<<"Customer no:";
      cout<<curr_serving<<endl;
      cout<<" by :  "<<endl;
      cout<<serve_holder<<endl;
      cash1.free(L);
       exit(K);
     return true;
    }


  else{

        if(serve_holder==1){           
          if(cash2.is_open()==1&&cash2.is_free()==0){
            serve_holder=2;
           cout<<"Customer no:";
           cout<<curr_serving<<endl;
           cout<<" by :  ";
           cout<<serve_holder<<endl;
           cash2.serve();          
           cash2.free(L);
           exit(K);
           return true;
           }

          if(cash3.is_open()==1&&cash3.is_free()==0){
           serve_holder=3; 
           cout<<"Customer no:";
           cout<<curr_serving<<endl;
           cout<<" by :  ";
           cout<<serve_holder<<endl;
           cash3.serve();          
           cash3.free(L);
           exit(K);
           return true;}
           
          if(cash4.is_open()==1&&cash4.is_free()==0){
           serve_holder=4;
           cout<<"Customer no:";
           cout<<curr_serving<<endl;
           cout<<" by :  ";
           cout<<serve_holder<<endl;
           cash4.serve();          
           cash4.free(L);
           exit(K);
           return true;}

          if(cash5.is_open()==1&&cash5.is_free()==0){
           serve_holder=5;
           cout<<"Customer no:";
           cout<<curr_serving<<endl;
           cout<<" by :  ";
           cout<<serve_holder<<endl;
           cash5.serve();          
           cash5.free(L);
           exit(K);
           return true;} 

           if(cash1.is_open()==1&&cash1.is_free()==0){
           serve_holder=1;
           cout<<"Customer no:";
           cout<<curr_serving<<endl;
           cout<<" by :  ";
           cout<<serve_holder<<endl;
           cash1.serve();          
           cash1.free(L);
           exit(K);
           return true;} 


           return true;
        }                                      

         if(serve_holder==2){
          
          if(cash3.is_open()==1&&cash3.is_free()==0){  
            serve_holder=3;      
           cout<<"Customer no: ";
           cout<<curr_serving<<endl;
           cout<<" by : "; 
           cout<<serve_holder<<endl;
           cash3.serve();         
           cash3.free(L);
           exit( K);
           return true;
           }

          if(cash4.is_open()==1&&cash4.is_free()==0){
           serve_holder=4;
           cout<<"Customer no:";
           cout<<curr_serving<<endl;
           cout<<" by :  ";
           cout<<serve_holder<<endl;
           cash4.serve();          
           cash4.free(L);
           exit(K);
           return true;}
          if(cash5.is_open()==1&&cash5.is_free()==0){
           serve_holder=5; 
          cout<<"Customer no:";
           cout<<curr_serving<<endl;
           cout<<" by :  ";
           cout<<serve_holder<<endl;
           cash5.serve();          
           cash5.free(L);
           exit(K);
           return true;}
          if(cash1.is_open()==1&&cash1.is_free()==0){
           serve_holder=1; 
           cout<<"Customer no:";
           cout<<curr_serving<<endl;
           cout<<" by :  ";
           cout<<serve_holder<<endl;
           cash1.serve();          
           cash1.free(L);
           exit(K);
           return true;} 

           if(cash2.is_open()==1&&cash2.is_free()==0){
           serve_holder=2;
           cout<<"Customer no:";
           cout<<curr_serving<<endl;
           cout<<" by :  ";
           cout<<serve_holder<<endl;
           cash2.serve();          
           cash2.free(L);
           exit(K);
           return true;} 

           return true;
        }                 

          if(serve_holder==3){        
          if(cash4.is_open()==1&&cash4.is_free()==0){
           serve_holder=4;
           cout<<"Customer no: ";
           cout<<curr_serving<<endl;
           cout<<" by : ";
           cout<<serve_holder<<endl;
           cash4.serve();
           cash4.free(L);
           exit( K);
           return true;
           }

          if(cash5.is_open()==1&&cash5.is_free()==0){
           serve_holder=5; 
            cout<<"Customer no:";
           cout<<curr_serving<<endl;
           cout<<" by :  ";
           cout<<serve_holder<<endl;
           cash5.serve();          
           cash5.free(L);
           exit(K);
           return true;}

          if(cash1.is_open()==1&&cash1.is_free()==0){
           serve_holder=1; 
            cout<<"Customer no:";
           cout<<curr_serving<<endl;
           cout<<" by :  ";
           cout<<serve_holder<<endl;
           cash1.serve();          
           cash1.free(L);
           exit(K);
           return true;}

          if(cash2.is_open()==1&&cash2.is_free()==0){
           serve_holder=2;
           cout<<"Customer no:";
           cout<<curr_serving<<endl;
           cout<<" by :  ";
           cout<<serve_holder<<endl;
           cash2.serve();          
           cash2.free(L);
           exit(K);
           return true;} 

          if(cash3.is_open()==1&&cash3.is_free()==0){
           serve_holder=3;
           cout<<"Customer no:";
           cout<<curr_serving<<endl;
           cout<<" by :  ";
           cout<<serve_holder<<endl;
           cash3.serve();          
           cash3.free(L);
           exit(K);
           return true;} 

           return true;
        }    

          if(serve_holder==4){
         
          if(cash5.is_open()==1&&cash5.is_free()==0){
            serve_holder=5;
           cout<<"Customer no: ";
           cout<<curr_serving<<endl;
           cout<<" by :";
           cout<<serve_holder<<endl;
           cash5.serve();
           cash5.free(L);
           exit(K);
           return true;
           }

          if(cash1.is_open()==1&&cash1.is_free()==0){
           serve_holder=1; 
          cout<<"Customer no:";
           cout<<curr_serving<<endl;
           cout<<" by :  ";
           cout<<serve_holder<<endl;
           cash1.serve();          
           cash1.free(L);
           exit(K);
           return true;}

          if(cash2.is_open()==1&&cash2.is_free()==0){
           serve_holder=2;
           cout<<"Customer no:";
           cout<<curr_serving<<endl;
           cout<<" by :  ";
           cout<<serve_holder<<endl;
           cash2.serve();          
           cash2.free(L);
           exit(K);
           return true;}
          if(cash3.is_open()==1&&cash3.is_free()==0){
           serve_holder=3;
           cout<<"Customer no:";
           cout<<curr_serving<<endl;
           cout<<" by :  ";
           cout<<serve_holder<<endl;
           cash3.serve();          
           cash3.free(L);
           exit(K);
           return true;}

          if(cash4.is_open()==1&&cash4.is_free()==0){
           serve_holder=4;
           cout<<"Customer no:";
           cout<<curr_serving<<endl;
           cout<<" by :  ";
           cout<<serve_holder<<endl;
           cash4.serve();          
           cash4.free(L);
           exit(K);
           return true;} 

           return true;
        }                                                                    
      
           
         if(serve_holder==5){
          
          if(cash1.is_open()==1&&cash1.is_free()==0){
             serve_holder=1;
           cout<<"Customer no: ";
           cout<<curr_serving<<endl;
           cout<<" by :";
           cout<<serve_holder<<endl;
           cash1.serve();          
           cash1.free(L);
           exit(K);
           return true;
           }
          
          if(cash2.is_open()==1&&cash2.is_free()==0){
           serve_holder=2; 
           cout<<"Customer no:";
           cout<<curr_serving<<endl;
           cout<<" by :  ";
           cout<<serve_holder<<endl;
           cash2.serve();          
           cash2.free(L);
           exit(K);
           return true;}
          if(cash3.is_open()==1&&cash3.is_free()==0){
           serve_holder=3;
           cout<<"Customer no:";
           cout<<curr_serving<<endl;
           cout<<" by :  ";
           cout<<serve_holder<<endl;
           cash3.serve();          
           cash3.free(L);
           exit(K);
           return true;}
          if(cash4.is_open()==1&&cash4.is_free()==0){
           serve_holder=4;
             cout<<"Customer no:";
           cout<<curr_serving<<endl;
           cout<<" by :  ";
           cout<<serve_holder<<endl;
           cash4.serve();          
           cash4.free(L);
           exit(K);
           return true;}
  
          if(cash5.is_open()==1&&cash5.is_free()==0){
           serve_holder=5;
           cout<<"Customer no:";
           cout<<curr_serving<<endl;
           cout<<" by :  ";
           cout<<serve_holder<<endl;
           cash5.serve();          
           cash5.free(L);
           exit(K);
           return true;} 

           return true;
        }                                                             
                                                                                
    }


    
    return true;
 }


 bool exit(int K){
 curr_serving++;
 if(check_to_close(K)==true){
  if(cash1.is_open()==1){
   close(&cash1);
   return true;}
  if(cash2.is_open()==1){
   close(&cash2);
   return true;}
  if(cash3.is_open()==1){
   close(&cash3);
   return true;}
  if(cash4.is_open()==1){
   close(&cash4);
   return true;}
  if(cash5.is_open()==1){
  close(&cash5) ;
   return true; }
 }
return 0;
 }



 bool close(cashier* a){
     a->close();
     if(a==&cash1)
      cout<<"cash1 cashier is now closed"<<endl;
     if(a==&cash2)
      cout<<"cash2 cashier is now closed"<<endl;
     if(a==&cash3)
      cout<<"cash3 cashier is now closed"<<endl;
     if(a==&cash4)
      cout<<"cash4 cashier is now closed"<<endl;
     if(a==&cash5)
      cout<<"cash5 cashier is now closed"<<endl;

 return true;
 }

 int waiting_customers(){  
     return last_customer -curr_serving; 
 }
 int open_cashiers(){
   counter=0;
   if(cash1.is_open()==1)
    counter++;
   if(cash2.is_open()==1)
    counter++;
   if(cash3.is_open()==1)
    counter++;
   if(cash4.is_open()==1)
    counter++;
   if(cash5.is_open()==1)
    counter++;
 cout<<"There are :";   
 cout<<counter;
 cout<<" open cashiers"<<endl;

return counter;
 }



 bool check_to_close(int K){
  if(waiting_customers()<=(open_cashiers()-1)*K)
   return true;
  else return false;
 }


};