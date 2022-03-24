
//public class TestMcq {
//
//}

public class TestMcq {  
    
static int a = 10;  
static int n;  
int b = 5;  
int c;  
public TestMcq(int m) {  
     System.out.println(a + ", " + b + ", " + c + ", " + n + ", " + m);  
 }  
// Instance Block  
{  
   b = 30;  
   n = 20;  
}   
// Static Block  
static   
{  
        a = 60;  
   }  
public static void main(String[] args) {  
	TestMcq obj = new TestMcq(n);  
}  
}  