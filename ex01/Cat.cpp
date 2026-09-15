#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    this->_brain = new Brain();
    std::cout << BCYAN << type << " default constructor called\n" << RESET;
}

Cat::Cat(const Cat& other) : Animal(other)
{
    this->_brain = new Brain(*other._brain);
    std::cout << BCYAN << type << " copied\n" << RESET;
}

Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
    {
        Animal::operator=(other);
        delete this->_brain;
        this->_brain = new Brain(*other._brain);
    }
    std::cout << BCYAN << "Cat assignment operator called\n" << RESET;
    return *this;
}

// leak fix, added delete
Cat::~Cat()
{
    delete this->_brain;
    std::cout << BCYAN << type << " destructor called\n" << RESET;
}

void Cat::makeSound() const
{
    std::cout << BCYAN << "Meow Meow~\n" << RESET;
}

Brain* Cat::getBrain() const
{
    return this->_brain;
}

//save index and array, add in main
void Cat::setIdea(size_t index, const std::string& Idea)
{
    this->_brain->setIdea(index, Idea);
}

std::string Cat::getIdea(size_t index) const
{
    return this->_brain->getIdea(index);
}
