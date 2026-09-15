#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
  private:
    Brain* _brain;

  public:
    Cat();
    Cat(const Cat& other);
    Cat& operator=(const Cat& other);
    virtual ~Cat();

    virtual void makeSound() const;

    //verify deep copy
    Brain* getBrain() const;
    void setIdea(size_t index, const std::string& Idea);
    std::string getIdea(size_t index) const;
};

#endif