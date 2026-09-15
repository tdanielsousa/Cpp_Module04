#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << MAGENTA << "Animal default constructor called\n" << RESET;
}

Animal::Animal(const std::string& type) : type(type)
{
    std::cout << MAGENTA << "Animal parametrized constructor called (" << type << ")\n"
              << RESET;
}

Animal::Animal(const Animal& other) : type(other.type)
{
    std::cout << MAGENTA << "Animal copy constructor called\n" << RESET;
}

// overwrite this w other
Animal& Animal::operator=(const Animal& other)
{
    if (this != &other)
        this->type = other.type;
    std::cout << MAGENTA << "Animal assignment operator called\n" << RESET;
    return *this;
}

Animal::~Animal()
{
    std::cout << MAGENTA << "Animal destructor called\n" << RESET;
}

void Animal::makeSound() const
{
    std::cout << MAGENTA << "* Generic animal sound *\n" << RESET;
}

std::string Animal::getType() const
{
    return this->type;
}
