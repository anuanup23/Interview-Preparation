package Learn.Basics;
class C extends Thread{

	@Override
	public void run() {
		for(Integer i = 0; i < 10; ++i) {
			System.out.println("Running From C :" + (i + 1));
		}
	}

	
}

class D extends Thread{

	@Override
	public void run() {
		for(Integer i = 0; i < 10; ++i) {
			System.out.println("Running From D :" + (i + 1));
		}
	}

	
}
public class ThreadingByThreadClass {
	public static void main(String[] args) {
		C t1 = new C();
		D t2 = new D();
		t1.start();
		t2.start();
	}
}


/* thread states new -> runnable <-> not runnable -> Dead State */


/* A thread become not runnable when the following 4 events occur:
1. when sleep() method is called it sleeps for the specified amount of time
2.when suspend() is invoked
3.wait() method is invoked and the thread waits for a free resource or waits for the completion of another thread 
or wait to acquire a lock of an object
4.the thread is blocking on i/o and waits for its completion */


/* From not runnable to runnable
1. after the time elapses in wait() function
2.a suspend() thread is resume()
3.if a thread is waiting on conditional variable , whatever object owns the variable must relinquish it by calling notify
or notifyAll()
4. after completion of i/o operation*/


/* Dead State
1. completion of run() function 
2. stop() called 
3. Exception*/