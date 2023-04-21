// test for explicit constructor call
// demo for use of final  and super modifier
class Person {
    int id;
	int age;
	Person(int id, int age)
	{
		this.id = id;
		this.age = age;
	}
	void show()
	{
		System.out.println(id);
		System.out.println(age);
	}
	public static void main()
	{
		Person p = new Person(27, 20);
		p.show();
	}
}

// class Employee extends Person{
//     String name;
// 	Employee(int d, int c)
// 	{
// 		super(d);
// 		d = c+1;
// 		d++;
// 	}
// }

