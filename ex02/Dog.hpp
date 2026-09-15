#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
  private:
    Brain* _brain;

  public:
    Dog();
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);
    virtual ~Dog();

    virtual void makeSound() const;

    //verify deep copy
    Brain* getBrain() const;
    void setIdea(size_t index, const std::string& Idea);
    std::string getIdea(size_t index) const;
};

#endif