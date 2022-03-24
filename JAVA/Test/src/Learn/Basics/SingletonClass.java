package Learn.Basics;
// step 1 Define a static instance of itself inside the class, initialize it as null
// step 2 Make the constructor private
// step 3 Define a getInstance method, call the constructor if the inner instance is null
public class SingletonClass {
	//private static SingletonClass innerInstance = null;
	private String x = String.valueOf(System.currentTimeMillis());
	private static volatile SingletonClass innerInstance = null;
	private SingletonClass() {}
	
	//Method 1 - it runs fine in non threaded environment but fails in threaded
/*	public static SingletonClass getInstance() {
		if(innerInstance == null) {
			innerInstance = new SingletonClass();
		}
		return innerInstance;
	}*/
	
	
	//Method 2
	
	/*public static synchronized SingletonClass getInstance() {
		if(innerInstance == null) {
			innerInstance = new SingletonClass();
		}
		return innerInstance;
	}*/
	

	// Problem here is getInstance method is not synchronized so there is no
	// prevention of different threads to enter the method and create instances at 
	// the same time. The above method has a drawback it slows down the performance of above function by 100 times
	
	// Method 3 double checked locking
	public static SingletonClass getInstance() {
		if(innerInstance == null) {
			synchronized(SingletonClass.class) {
				if(innerInstance == null) {
					innerInstance = new SingletonClass();
					System.out.println("Instance Created");
				}
			}
		}
		return innerInstance;
	}
	
	public static void main(String [] args) {
		SingletonClass obj1 = SingletonClass.getInstance();
		System.out.println(obj1.x);
		System.out.println("Singleton object created in Main Class");
		String start = String.valueOf(System.currentTimeMillis());
		System.out.println(start);
		int c = 1;
		for(int i = 0; i < 1000000000; ++i) {
			c = (c + i) % 1000;
		}
		String end = String.valueOf(System.currentTimeMillis());
		SingletonClass obj2 = SingletonClass.getInstance();
		System.out.println(obj2.x);
		System.out.println(end);
		
	}
}
