#include "WrongCat.hpp"

// default constructor
WrongCat::WrongCat()
{
    this->type = "WrongCat";
    std::cout << BLUE << "WrongCat default constructor called\n" << RESET;
}

// copy constructor
WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
    *this = other;
    std::cout << BLUE << type << " copied\n" << RESET;
}

// assignment operator
WrongCat& WrongCat::operator=(const WrongCat& other)
{
    if (this != &other)
    {
        WrongAnimal::operator=(other);
    }
    std::cout << BLUE << "WrongCat assignment operator called\n" << RESET;
    return *this;
}

// destructor
WrongCat::~WrongCat()
{
    std::cout << BLUE << type << " destructor called\n" << RESET;
}

// funcs
void WrongCat::makeSound() const
{
    std::cout << BLUE << "Wrong Meow!\n" << RESET;
}