#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        this->learned[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const& other)
{
    for (int i = 0; i < 4; i++)
    {
        if (other.learned[i])
            this->learned[i] = other.learned[i]->clone();
        else
            this->learned[i] = NULL;
    }
}

MateriaSource& MateriaSource::operator=(MateriaSource const& other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            if (this->learned[i])
            {
                delete this->learned[i];
                this->learned[i] = NULL;
            }
            if (other.learned[i])
                this->learned[i] = other.learned[i]->clone();
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (this->learned[i])
            delete this->learned[i];
    }
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (!m)
        return;
    for (int i = 0; i < 4; i++)
    {
        if (this->learned[i] == NULL)
        {
            this->learned[i] = m;
            return;
        }
    }
    // If memory slots are full, delete passed pointer to prevent memory leaks
    delete m;
}

AMateria* MateriaSource::createMateria(std::string const& type)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->learned[i] && this->learned[i]->getType() == type)
            return this->learned[i]->clone();
    }
    return NULL;
}