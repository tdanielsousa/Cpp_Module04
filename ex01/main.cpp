#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
    /*
    "How do I safely duplicate child class instances that allocate memory on the heap?"

    cpp uses last in first out order
    construction: base class > member attributes (Brain) > derived class (Cat)
    destruction: member attributes (Brain) > derived class (Cat) >  base class

    like in ex00, would leak if not virtual since this time allocates brain
    */

    std::cout << BYELLOW << "---- ARRAY OF ANIMALS TEST ----\n" << RESET;
    const int count = 4;
    Animal* animals[count];

    for (int i = 0; i < count; i++)
    {
        if (i < count / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
        std::cout << "----------------------------------------\n";
    }

    std::cout << BYELLOW << "\n----- CLEANING UP ARRAY -----\n" << RESET;
    for (int i = 0; i < count; i++)
    {
        // has to trigger dog and cat destruc
        delete animals[i];
        std::cout << "----------------------------------------\n";
    }

    /////////////////////////////////////////////////////
    // deep copy  this->_brain = new Brain(*other._brain);
    ////////////////////////////////////////////////////

    std::cout << BYELLOW << "\n---- DEEP COPY TEST (COPY CONSTRUCTOR) ----\n" << RESET;
    {
        Dog originalDog;
        originalDog.setIdea(0, "wooof wooooooff");
        originalDog.setIdea(1, "meoooooooooow");

        std::cout << YELLOW << "\n-- Creating copyDog via Copy Constructor --\n" << RESET;
        Dog copyDog = originalDog;

        std::cout << YELLOW << "\n-- Verification --\n" << RESET;
        std::cout << YELLOW << "Original Dog Brain Address: " << BLUE << originalDog.getBrain()
                  << "\n";
        std::cout << YELLOW << "Copy Dog Brain Address:     " << BLUE << copyDog.getBrain()
                  << "\n";

        std::cout << YELLOW << "Original Idea 0: " << BLUE << originalDog.getIdea(0) << "\n";
        std::cout << YELLOW << "Copy Idea 0:     " << BLUE << copyDog.getIdea(0) << "\n";

        // modify phare to show its not using same pointer
        copyDog.setIdea(0, "grrrrrrrrrrrrr");
        std::cout << YELLOW << "Modified Copy Idea 0: " << BLUE << copyDog.getIdea(0) << "\n";
        std::cout << YELLOW << "Original Idea 0 after copy mod: " << BLUE
                  << originalDog.getIdea(0) << "\n"
                  << RESET;
        std::cout << "----------------------------------------\n";

        std::cout << YELLOW << "\n-- Scope Exit (Destroying copyDog & originalDog) --\n"
                  << RESET;
    }

    std::cout << "----------------------------------------\n";
    std::cout << BYELLOW << "\n---- DEEP COPY TEST (ASSIGNMENT OPERATOR) ----\n" << RESET;
    {
        Cat originalCat;
        originalCat.setIdea(0, "meow");

        Cat assignedCat;
        std::cout << YELLOW << "\n-- Assigning originalCat to assignedCat --\n" << RESET;
        assignedCat = originalCat;

        std::cout << YELLOW << "\n-- Verification --\n" << RESET;
        std::cout << YELLOW << "Original Cat Brain Address: " << BLUE << originalCat.getBrain()
                  << "\n";
        std::cout << YELLOW << "Assigned Cat Brain Address: " << BLUE << assignedCat.getBrain()
                  << "\n";

        std::cout << YELLOW << "Original Idea 0: " << BLUE << originalCat.getIdea(0) << "\n";
        std::cout << YELLOW << "Assigned Idea 0: " << BLUE << assignedCat.getIdea(0) << "\n"
                  << RESET;

        std::cout << "----------------------------------------\n";

        std::cout << YELLOW << "\n-- Scope Exit --\n" << RESET;
    }
    std::cout << "----------------------------------------\n";
    return 0;
}
