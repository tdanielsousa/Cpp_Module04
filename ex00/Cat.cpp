#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << BCYAN << type << " default constructor called\n" << RESET;
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << BCYAN << type << " copied\n" << RESET;
}

Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
        Animal::operator=(other);
    std::cout << BCYAN << "Cat assignment operator called\n" << RESET;
    return *this;
}

Cat::~Cat()
{
    std::cout << BCYAN << type << " destructor called\n" << RESET;
}

void Cat::makeSound() const
{
    std::cout << BCYAN << "Meow Meow~\n" << RESET;
}
