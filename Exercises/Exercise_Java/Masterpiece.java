package javaask;


public abstract class Masterpiece extends Artifacts {
    Movement movement;
     Condition condition;
    
   public Masterpiece(Movement _movement,Condition _condition){              
        System.out.println("Creating an instance of Masterpiece");
        movement=_movement;
        condition=_condition;
        
   }    
    
    public void getInfo(){
      super.getInfo();  
      System.out.print("This masterpiece's movement is:");
      System.out.println(movement);
      System.out.print("This masterpiece's condition is:");
      System.out.println(condition);
      
      
    }
   
    public void change_condition(Condition __condition){
      condition=__condition;
        
    }
    
    public abstract boolean evaluate(Movement movement,Condition condition);
    
    public abstract boolean evaluate(Movement movement);

 }
