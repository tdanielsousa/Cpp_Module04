#include "Brain.hpp"

Brain::Brain()
{
    std::cout << BRED << "Brain default constructor called\n" << RESET;
}

Brain::Brain(const Brain& other)
{
    *this = other;
    std::cout << BRED << "Brain copy constructor called\n" << RESET;
}

Brain& Brain::operator=(const Brain& other)
{
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
        {
            this->_Idea[i] = other._Idea[i];
        }
    }
    std::cout << BRED << "Brain assignment operator called\n" << RESET;
    return *this;
}

Brain::~Brain()
{
    std::cout << BRED << "Brain destructor called\n" << RESET;
}

void Brain::setIdea(size_t index, const std::string& Idea)
{
    if (index < 100)
        this->_Idea[index] = Idea;
}

std::string Brain::getIdea(size_t index) const
{
    if (index < 100)
        return this->_Idea[index];
    return "";
}