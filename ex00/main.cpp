#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

/*
"How do I call a method on a parent pointer and have it run the child's version instead?"

order> base then new type, parent builds first then child
*/
int main()
{
    std::cout << BYELLOW << "-------------------------------\n";
    std::cout << "-------- SUBJECT TESTS --------\n";
    std::cout << "-------------------------------\n" << RESET;
    {
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();

        std::cout << YELLOW << "> J Type: " << j->getType() << "\n";
        std::cout << "> I Type: " << i->getType() << "\n" << RESET;

        i->makeSound();    // outputs Cat sound
        j->makeSound();    // outputs Dog sound
        meta->makeSound(); // outputs Animal sound

        delete meta;
        delete j;
        delete i;
    }

    /*
    delete cat without virtual it calls the parent directly if wrongcat allocated
     it would leak
    also outputs wrong sound because compiler hardcodes without virtual(nopoly)
    compiler creates vtables at runtime w poly
    */

    std::cout << BYELLOW << "-------------------------------\n";
    std::cout << "----- WRONG ANIMAL TESTS -----\n";
    std::cout << "-------------------------------\n" << RESET;
    {
        const WrongAnimal* meta = new WrongAnimal();
        const WrongAnimal* cat = new WrongCat();
        const WrongCat* directCat = new WrongCat();

        std::cout << YELLOW << "> WrongCat, Type: " << cat->getType() << "\n" << RESET;

        cat->makeSound(); // outputs WrongAnimal sound due to non virtual
        meta->makeSound();
        directCat->makeSound(); // outputs WrongCat sound because is called directly

        // std::cout << "\n";
        delete meta;
        // std::cout << "\n";
        delete cat;
        // std::cout << "\n";
        delete directCat;
    }

    return 0;
}
