public class Person{
    // private String name;
    private int age;
    
    public Person(int age) {
        this.age = age;
        // this.age = age;
    }
    
    public void printDetails() {
        // System.out.println("Name: " + this.name);
        System.out.println(age);
    }
    
    public static void main(String[] args) {
        Person person = new Person(30);
        person.printDetails();
    
}
}
