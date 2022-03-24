class Walmart{
	public void print() {
		System.out.println("Walmart");
	}
}
class Flipkart extends Walmart{
	public void print() {
		super.print();
		System.out.println("Flipkart");
	}
}
class Myntra extends Flipkart{
	public void print() {
		//super.super.print(); this is error
		super.print();
		System.out.println("Myntra");
	}
}
public class Example {
	public static void main(String[] args) {
		Myntra myntra = new Myntra();
		myntra.print();
	}
}
