#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() : type("default")
{
}

AMateria::AMateria(std::string const& type) : type(type)
{
}

AMateria::AMateria(AMateria const& other) : type(other.type)
{
}

// Subject: "While assigning a Materia to another, copying the type doesn't make sense."
AMateria& AMateria::operator=(AMateria const& other)
{
    (void)other;
    return *this;
}

AMateria::~AMateria()
{
}

std::string const& AMateria::getType() const
{
    return this->type;
}

void AMateria::use(ICharacter& target)
{
    (void)target;
}
