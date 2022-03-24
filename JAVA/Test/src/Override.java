
public class Override {
	public void method(Object obj) {
		System.out.println("I am an Object");
	}
	public void method(String obj) {
		System.out.println("I am an String");
	}
	public static void main(String[] args) {
		Override override = new Override();
		override.method(null);
	}
}
