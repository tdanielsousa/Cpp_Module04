#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    this->_brain = new Brain();
    std::cout << BGREEN << "Dog default constructor called\n" << RESET;
}

Dog::Dog(const Dog& other) : Animal(other)
{
    this->_brain = new Brain(*other._brain);
    std::cout << BGREEN << "Dog copy constructor called\n" << RESET;
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
    {
        Animal::operator=(other);
        delete this->_brain;
        this->_brain = new Brain(*other._brain);
    }
    std::cout << BGREEN << "Dog assignment operator called\n" << RESET;
    return *this;
}

Dog::~Dog()
{
    delete this->_brain;
    std::cout << BGREEN << "Dog destructor called\n" << RESET;
}

void Dog::makeSound() const
{
    std::cout << BGREEN << "Woof Woof!\n" << RESET;
}

Brain* Dog::getBrain() const
{
    return this->_brain;
}

//save index and array, add in main
void Dog::setIdea(size_t index, const std::string& Idea)
{
    this->_brain->setIdea(index, Idea);
}

std::string Dog::getIdea(size_t index) const
{
    return this->_brain->getIdea(index);
}
