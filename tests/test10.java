

class Dog {
    void bark(int a) {
        System.out.println(a);
    }
}

class TestInheritance2 {
    public static void main(String args[]) {
        Dog d = new Dog();
        d.bark(1*2 + 3);
    }
}
