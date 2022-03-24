package Learn.Basics;
// make class final
// make variables as private
// make variables as final
// No setter Method
// Perform deep copy for creating association for external classes
class Engine{
	public int speed;
	public String name;
	public Engine(int speed, String name) {
		this.speed = speed;
		this.name = name;
	}
	public int getSpeed() {
		return speed;
	}
	public String getName() {
		return name;
	}	
}
public final class Immutable {
	private final int id;
	private final String name;
	private final Engine engine;
	public Immutable(int id, String name, Engine engine) {
		this.id = id;
		this.name = name;
		// Always do a deep copy of Associated classes value
		Engine newEngine = new Engine(engine.speed, engine.name);
		this.engine = newEngine;
	}
	public int getId() {return id;}
	public String getName() {return name;}
	public int getSpeed() {
		return engine.speed;
	}
	public static void main(String[] args) {
		Engine engine = new Engine(40,"Tata Motors");
		Immutable obj = new Immutable(1,"Test",engine);
		engine.speed = 60;
		System.out.println("value of External Object Speed = " + engine.speed);
		System.out.println("Value of Immutable Object Speed = " + obj.getSpeed());
	}
}
