#include<iostream>

class person {
    int age;
    int id;

    public:
        person(int age, int id)
        {
            this->id = id;
            this->age = age;
        }

        void calcId(int key)
        {
            id = key % (int)(1e7 + 9);
        }
};

int main()
{
    person p = person(2, 4);
    p.calcId(45);
}