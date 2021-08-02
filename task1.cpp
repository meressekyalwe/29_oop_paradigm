/*29.4 Домашняя работа
 * Что нужно сделать
 * Решите задачу «Встреча животных».
 * Встречаясь, животные реагируют друг на друга. Реализуйте базовый класс Animal, классы-
 * наследники Dog и Cat, и напишите функцию meeting, принимающую два указателя на базовый
 * класс, по которому лежат элементы классов-наследников, которая выводит в консоль разные
 * фразы в зависимости от того, какие конкретные классы встретились.
 *
 * Dog + Dog → “Woof-Woof”
 * Dog + Cat → “Bark Meow”
 * Cat + Dog → “Meow Bark”
 * Cat + Cat → “Purr Purr”
 *
 * Пример:
 * Animal* a = new Dog();
 * Animal* b = new Cat();
 * meeting(a,b);
 * Вывод:
 * Bark Meow
 */

#include <iostream>

class Animal{
    std::string name = "Unknown";
public:
    virtual std::string get_name() const = 0;
    virtual std::string meet(Animal *pAnimal) const = 0;
    virtual ~Animal(){};
};

class Dog : public Animal{
    std::string name = "Dog";
public:
    std::string get_name() const{
        return name;
    }
    std::string meet(Animal *pAnimal) const{
        return (pAnimal->get_name() == "Dog" ? "Woof" : "Bark");
    }
    ~Dog(){};
};

class Cat : public Animal{
    std::string name = "Cat";
public:
    std::string get_name() const {
        return name;
    }
    std::string meet(Animal *pAnimal) const {
        return (pAnimal->get_name() == "Cat" ? "Purr" : "Meow");
    }
    ~Cat(){};
};

void meeting(Animal* a, Animal* b){
    std::cout << a->meet(b) << " " << b->meet(a) << std::endl;
}

int main() {
    Animal* dog = new Dog;
    Animal* cat = new Cat;
    meeting(dog,dog);
    meeting(dog,cat);
    meeting(cat,dog);
    meeting(cat,cat);
    delete dog;
    delete cat;
    dog = nullptr;
    cat = nullptr;
}
