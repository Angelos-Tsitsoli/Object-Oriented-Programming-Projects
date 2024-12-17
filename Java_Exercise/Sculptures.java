package javaask;
import java.util.Random;
public class Sculptures extends Masterpiece{
    final private int volume;
    Material material;
    
    public Sculptures(Movement __movement,Condition __condition){
      super(__movement,__condition);
      System.out.println("Creating an instance of Sculptures"); 
      System.out.println(); 
      Random num3=new Random();
      volume=210000+num3.nextInt(350000);  
       Random num2=new Random();
      int number;
      number=1+num2.nextInt(3);
      if(number==1){
        material=Material.iron; 
      }
      if(number==2){
        material=Material.stone;  
      }
      if(number==3){
         material=Material.wood;
      }
       
    }
    
   public void getInfo(){
       super.getInfo();
       System.out.print("This sculpture's volume is:");
       System.out.print(volume);
       System.out.print(" ");
       System.out.println("(cm)^3");
       System.out.print("This sculpture's material is:");
       System.out.println(material);
        
   }
   
   public boolean evaluate(Movement __movement,Condition __condition){
          if(movement==__movement&&condition==__condition)
          return true; 
      
          if(movement==__movement&&condition==Condition.good&&__condition==Condition.excellent)
          return false; 


      else return false;
   }

   public boolean evaluate(Movement __movement){
    if(movement==__movement&&condition==Condition.excellent)
    return true;
  
    else return false;
  }



}




