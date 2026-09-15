#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << BGREEN << "Dog default constructor called\n" << RESET;
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << BGREEN << "Dog copy constructor called\n" << RESET;
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
        Animal::operator=(other);
    std::cout << BGREEN << "Dog assignment operator called\n" << RESET;
    return *this;
}

Dog::~Dog()
{
    std::cout << BGREEN << "Dog destructor called\n" << RESET;
}

void Dog::makeSound() const
{
    std::cout << BGREEN << "Woof Woof!\n" << RESET;
}
