package javaask;
import java.util.Random; 




class Main{
    

    public static Movement functin_mov(int n){
    Movement movement=Movement.naturalism;     
    if(n==1){
    movement=Movement.impressionism;
    return movement;}
    if(n==2) {
    movement=Movement.expressionism;
    return movement;}
    return movement;  
    }
     
 
    public  static Condition function_con(int n){
     Condition condition=Condition.good;
     if(n==1){
       condition=Condition.bad;
     return condition;}
     if(n==2) {
     condition=Condition.excellent;
     return condition;}

     return condition;
    }
 
 
    public static Movement String_to_movement(String a){
    Movement movement=Movement.another;
    

     if(a.equals("naturalism")){
        movement=Movement.naturalism;
         return movement;
     }
     
     if(a.equals("expressionism")){
        movement=Movement.expressionism;
         return movement;
     }
    
     if(a.equals("impressionism")){
        movement=Movement.impressionism;
       return movement;}
     
       
   return movement;
    }


    public static Condition String_to_condition(String b){
    
       Condition condition=Condition.another;
        if(b.equals("good")){
           condition=Condition.good;
            return condition;
        }
        
        if(b.equals("bad")){
           condition=Condition.bad;
            return condition;
        }
       
           
        if(b.equals("excellent")){
           condition=Condition.excellent;
           return condition;}


      return condition;    
    }
  


   public static Condition String_to_condition2(){
      Condition condition=Condition.nothing;
      return condition;
   }


 
     public static int auction(Artifacts[]a,Movement b, Condition c){        
         boolean h;
         
      

       if(b==Movement.another||c==Condition.another){
         System.out.println("Something wrong with Movement or Condition");
        return 1;}

       for(Artifacts artifact:a){
            System.out.print("The Artifact in place: ");
            System.out.print(artifact.n); 
            System.out.println(" has the following information"); 
            artifact.getIndex();
            artifact.getInfo();
            if(c==Condition.nothing){
              h=artifact.evaluate(b);
              if(h==true){
              System.out.println("This artifact is acceptable ");
              System.out.println();
             }
              else if(h==false)
              System.out.println("This artifact is unacceptable "); 
              System.out.println();
              continue;
            }
             
            h=artifact.evaluate(b,c);
            if(h==true){
            System.out.println("This artifact is acceptable ");
            System.out.println();}
            else if(h==false)
            System.out.println("This artifact is unacceptable ");  
            System.out.println();
        }
            
     return 0;   
     }
    
   
    
    public static void main(final String args[]){
      Random num=new Random();
      Random num1=new Random();
      Random num2=new Random();
      int number;
      int number1;
      int number2;
      int N=Integer.parseInt(args[0]);      
      Artifacts [] array=new Masterpiece[N];    
      for(int i=0;i<N;i++){                                           
        number=1+num.nextInt(2);
        number1=num1.nextInt(2);
        number2=num2.nextInt(2);
       if(number==1){         
          array[i]=new Paintings(Main.functin_mov(number1),Main.function_con(number2));
          
        }
       if(number==2){
        array[i]=new Sculptures(Main.functin_mov(number1),Main.function_con(number2));
       }      
       } 
      



     
      
      if(args.length==2){    
      auction(array,String_to_movement(args[1]),String_to_condition2());
      }
             
      if(args.length==3){
      auction(array,String_to_movement(args[1]),String_to_condition(args[2])); }    
    }
               
      
    
 
 }
 
 

