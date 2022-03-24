
  public class ProcessOfExecution {  
    public void myMethod()   
  {  
  System.out.println("Method");  
  }  
    
  {  
  System.out.println(" Instance Block");  
  }  
        
  public void First_C()  
  {  
  System.out.println("Constructor ");  
  }  
  static {  
      System.out.println("static block");  
  }  
  public static void main(String[] args) {  
	  ProcessOfExecution c = new ProcessOfExecution();  
  c.First_C();  
  c.myMethod();  
}  
}   
