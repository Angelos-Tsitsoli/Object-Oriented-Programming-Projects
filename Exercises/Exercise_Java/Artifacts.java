
package javaask;
import java.util.Random;



enum Movement{naturalism,impressionism,expressionism,another};
enum Condition{good,bad,excellent,another,nothing};
enum Material {iron,stone,wood};
enum Technique{oil,aquarelle,tempera,};




 public abstract class Artifacts {


    static private int index=0;
    final private int year;
    final private String creator;
    int n=0; 
       
public Artifacts(){
    index=index+1;
    n=index;
    System.out.println("Creating an instance of Artifact"); 
    Random num=new Random();
    year=2002+num.nextInt(21);
    creator="Creator"+index; 
       
}    
    
  public void getInfo() {
     
     System.out.print("The year of the artifact is:");
     System.out.println(year); 
     System.out.print("The creator of the artifact is:");
     System.out.println(creator); 
  
     
 }
  
 
public  void getIndex(){
    System.out.print("The index of the artifact is:");
    System.out.println(index);
  
    
} 
 

public abstract boolean evaluate(Movement movement);

public abstract boolean evaluate(Movement movement,Condition condition);

}





