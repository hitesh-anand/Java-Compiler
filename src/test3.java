// test for explicit constructor call
// demo for use of final  and super modifier
class Person {
    int id;
	Person(int a, int b)
	{
		id = a+1;
	}

	void help(int b)
	{
		b++;
	}
}

class Employee extends Person{
    String name;
	Employee(int d, int c)
	{
		super(d, 1);
		d = c+1;
		d++;
	}
}

class Vehicle {
    int maxSpeed = 120;
	final void display()
    {
        System.out.println("Maximum Speed of Vehicle: "+ maxSpeed);
    }
}


class animal{
	int legs=5;
	animal(int a){
		legs=a;
	}
	void display(){
		Person p = new Person(legs, legs+2);
		System.out.println("Number of legs: "+legs);
	}
}

class dog extends animal{
	int legs=4;
	dog(int a){
		super(a);
		legs=a;
	}
	void display(){
		System.out.println("Number of legs: "+legs);
		System.out.println("Number of legs of general animal: "+super.legs);
	}
}