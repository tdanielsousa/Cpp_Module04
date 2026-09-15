#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
    std::cout << BYELLOW << "----  SUBJECT TEST ----\n" << RESET;
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());

        ICharacter* me = new Character("me");

        AMateria* tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);

        ICharacter* bob = new Character("bob");

        me->use(0, *bob);
        me->use(1, *bob);

        delete bob;
        delete me;
        delete src;
    }

    std::cout << BYELLOW << "\n----  DEEP COPY & INVENTORY OVERFLOW TEST ----\n" << RESET;
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());

        Character* hero = new Character("Hero");
        hero->equip(src->createMateria("ice"));
        hero->equip(src->createMateria("cure"));
        hero->equip(src->createMateria("ice"));
        hero->equip(src->createMateria("cure"));

        // Overflow attempt (full inventory, createMateria won't leak if properly handled)
        AMateria* extra = src->createMateria("ice");
        hero->equip(extra);
        delete extra; // Manually delete because hero inventory was full!

        // Deep copy verification
        Character* cloneHero = new Character(*hero);
        ICharacter* target = new Character("Target");

        std::cout << BLUE << "Original Hero uses slot 0:\n" << RESET;
        hero->use(0, *target);

        std::cout << BLUE << "Cloned Hero uses slot 0:\n" << RESET;
        cloneHero->use(0, *target);

        delete target;
        delete cloneHero;
        delete hero;
        delete src;
    }

    std::cout << BYELLOW << "\n----  UNEQUIP & FLOOR MEMORY LEAK TEST ----\n" << RESET;
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());

        Character* warrior = new Character("Warrior");
        AMateria* m1 = src->createMateria("ice");

        warrior->equip(m1);

        // Save address before unequip to prevent memory leaks on floor
        AMateria* floorAddress = m1;
        warrior->unequip(0);

        ICharacter* dummy = new Character("Dummy");

        // Verification check: unequip should leave floorAddress valid and empty slot 0
        if (floorAddress != NULL && floorAddress->getType() == "ice")
        {
            std::cout << GREEN << "[SUCCESS] Unequipped item preserved on floor ("
                      << floorAddress->getType() << " at " << floorAddress << ")\n"
                      << RESET;
        }
        else
        {
            std::cout << RED << "[ERROR] Floor item address lost or corrupted!\n" << RESET;
        }

        std::cout << BLUE << "Testing use() on unequipped slot 0 (should produce no action):\n"
                  << RESET;
        warrior->use(0, *dummy);
        std::cout << GREEN << "[SUCCESS] Empty slot handled safely without crashing.\n"
                  << RESET;

        // Cleanup floor memory manually
        delete floorAddress;
        delete dummy;
        delete warrior;
        delete src;
    }

    return 0;
}