package Learn.Basics;
class A implements Runnable{

	@Override
	public void run() {
		for(Integer i = 0; i < 10; ++i) {
			System.out.println("Running From A :" + (i + 1));
		}
	}

	
}

class B implements Runnable{

	@Override
	public void run() {
		for(Integer i = 0; i < 10; ++i) {
			System.out.println("Running From B :" + (i + 1));
		}
	}

	
}
public class ThreadingBasics {
	public static void main(String[] args) {
		Thread t1 = new Thread(new A());
		Thread t2 = new Thread(new B());
		t1.start();
		t2.start();
	}
}
