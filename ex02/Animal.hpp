#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#define RESET "\033[0m"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

#define BRED "\033[1;31m"
#define BGREEN "\033[1;32m"
#define BYELLOW "\033[1;33m"
#define BBLUE "\033[1;34m"
#define BMAGENTA "\033[1;35m"
#define BCYAN "\033[1;36m"

#include <iostream>
#include <string>

class Animal
{
  protected:
    std::string type;

  public:
    Animal();
    Animal(const std::string& type);
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);
    virtual ~Animal();

    /*
    ex converts Animal into an abstract class
    virtual void makeSound() const;

    prevents generic animals, animals are always specific like dog, cat, mouse...
    this forces every animal to have its own sound(or error on compile)

    could bypass this down the chain by creating a "sub class" like mammals inside it

    would be useful for a  class with a bank account
     which must have for example the user nif
    */

    virtual void makeSound() const = 0;
    std::string getType() const;
};

#endif