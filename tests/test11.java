public class Person{
    // private String name;
    private int age;
    private int id;
    public Person(int age, int id) {
        this.age = age;
        this.id = id;
        // this.age = age;
    }
    
    public void printDetails() {
        // System.out.println("Name: " + this.name);
        System.out.println(age);
        System.out.println(id);
    }
    
    public static void main(String[] args) {
        Person person = new Person(30, 123);
        person.printDetails();
    
}
}

