#include <iostream>
#include <string>

typedef union
{
    char name[10];
    int age;
} Person;

int main()
{
    Person person1 = {.name = "xiaoming"};
    Person person2 = {.age = 18};

    std::cout << person1.name << std::endl;
    std::cout << person2.age << std::endl;

    return 0;
}