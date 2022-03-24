
public class ExceptionExample {
	public static void main(String [] args) {
		int[] arr = {1,2,3,4};
		int i = 0;
		try {
			double x = 8.0 / 0.0;
			i++;
			System.out.println("here" +x);
			int y = 2;
			i++;
			System.out.println("here x" + y/0.0);
		}
		catch(ArithmeticException e) {
			System.out.println("Catch");
			i++;
		}
		finally{
			i++;
		}
		System.out.println(arr[i]);
	}
}
