package javaask;
import java.util.Random; 
 public class Paintings extends Masterpiece{

    final private int length;
    final private int width;
    Technique technique;

    int surface;
    
  public  Paintings(Movement _movement,Condition _condition){
      super(_movement,_condition);
      System.out.println("Creating an instance of Painting");
      System.out.println();
      Random num=new Random();
      width=30+num.nextInt(61);
      Random num1=new Random();
      length=70+num1.nextInt(111);
      surface=width*length;
      Random num2=new Random();
      int number;
      number=1+num2.nextInt(3);
      if(number==1){
        technique=Technique.oil; 
      }
      if(number==2){
        technique=Technique.aquarelle;  
      }
      if(number==3){
          technique=Technique.tempera;
      }
     
      
}
  public void getInfo(){
      super.getInfo();
      System.out.print("This paintings width is:");
      System.out.print(width);
      System.out.print(" ");
      System.out.println("cm");
      System.out.print("This paintings length is:");
      System.out.print(length);
      System.out.print(" ");
      System.out.println("cm");      
      System.out.print("This paintings surface is:");
      System.out.print(surface);
      System.out.println("(cm)^2");
      System.out.print("This paintings technique is:");
      System.out.println(technique);
      
     
      
  }
  
  public boolean evaluate(Movement _movement,Condition _condition){
      if(movement==_movement&&condition==_condition)
          return true; 

      if(condition==Condition.good&&_condition==Condition.excellent){
        if(movement==_movement)
          return true; }


       return false;
  }
  
  public boolean evaluate(Movement _movement){
    if(movement==_movement&&condition==Condition.good)
    return true;

    else return false;
  }



  
}