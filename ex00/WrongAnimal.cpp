#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
    std::cout << RED << "WrongAnimal default constructor called\n" << RESET;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type)
{
    std::cout << RED << "WrongAnimal copy constructor called\n" << RESET;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    if (this != &other)
        this->type = other.type;
    std::cout << RED << "WrongAnimal assignment operator called\n" << RESET;
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << RED << "WrongAnimal destructor called\n" << RESET;
}

void WrongAnimal::makeSound() const
{
    std::cout << RED << "* Generic wrong animal sound *\n" << RESET;
}

std::string WrongAnimal::getType() const
{
    return this->type;
}
