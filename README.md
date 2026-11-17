# CPP Module 04

The fifth module of the 42 C++ series, focused on subtype polymorphism and abstract classes.

It covers virtual member functions, virtual destructors, deep copies, abstract classes with pure virtual functions and interfaces, all compiled with `-Wall -Wextra -Werror -std=c++98`.

> Note: This module is graded with the C++98 standard, and every class must follow the Orthodox Canonical Form. Nothing may leak, so deep copies and virtual destructors matter throughout the module.
---

<div align="center">
    <br>
    <a href="https://github.com/tdanielsousa/42_School/blob/main/Subjects/cpp04.pdf" target="_blank">
        <img src="https://img.shields.io/badge/View%20Subject-PDF-red?style=for-the-badge&logo=adobe-acrobat-reader&logoColor=white" alt="Subject PDF" height="40">
    </a>
    <p><i>Click on the button above to see the subject's pdf.</i></p>

</div>

---

##  Module Architecture & Concepts

Each exercise lives in its own folder with its own `Makefile`. The first exercises introduce polymorphism with animals, then add dynamic memory, abstract classes and finally interfaces.

### Technical Specifications
* **Language:** C++98.
* **Compiler:** `c++` with `-Wall -Wextra -Werror -std=c++98`.
* **Polymorphism:** Base class pointers and references calling the correct derived implementation through `virtual` functions.
* **Memory:** `new` / `delete`, deep copies for classes owning dynamic memory, and no leaks.
* **Abstract Classes and Interfaces:** Pure virtual functions (`= 0`) that cannot be instantiated.
* **Restrictions:** No `printf`, `malloc` or `free`, and no STL containers or algorithms.

---

##  Exercises

### ex00: Polymorphism
Creates a small animal hierarchy to show how `virtual` works.

* **`Animal` class:** Has a protected `type` and a `makeSound()` member function.
* **`Dog` and `Cat`:** Derive from `Animal`, set their type in the constructor and override `makeSound()`.
* **`WrongAnimal` and `WrongCat`:** The same structure **without** `virtual`, to show that the wrong sound is played when called through a base pointer.
* **Concepts:** Virtual member functions, subtype polymorphism, what happens without `virtual`.

### ex01: I don't want to set the world on fire
Adds a `Brain` to the animals, which brings dynamic memory into the picture.

* **`Brain` class:** Holds an array of `100` strings (ideas).
* **`Dog` and `Cat`:** Each has a private `Brain*`, created with `new` in the constructor and deleted in the destructor.
* **Main:** Creates an array of `Animal` objects (half dogs, half cats) and deletes them through `Animal` pointers, which requires a **virtual destructor**.
* **Deep copy:** Copying a `Dog` or `Cat` must copy the `Brain` too, so the copies are independent.
* **Concepts:** Virtual destructors, deep vs shallow copy, copy constructor and assignment operator with dynamic memory.

### ex02: Abstract class
Makes the base class impossible to instantiate.

* **`Animal`:** Turned into an abstract class, usually by making `makeSound()` pure virtual.
* **Result:** `Dog` and `Cat` can still be created, but `Animal` alone cannot.
* **Concepts:** Pure virtual functions, abstract classes.

### ex03: Interface & recap
Builds a small materia system, using interfaces.

* **`AMateria`:** Abstract class with a `type`, a `clone()` pure virtual function and a `use(ICharacter&)` function.
* **`Ice` and `Cure`:** Concrete materias. `clone()` returns a new instance of the same type, and `use()` prints `* shoots an ice bolt at <name> *` or `* heals <name>'s wounds *`.
* **`ICharacter` interface:** Has `getName()`, `equip(AMateria*)`, `unequip(int)` and `use(int, ICharacter&)`.
* **`Character`:** Implements `ICharacter` with an inventory of `4` slots. Equipping fills the first empty slot, unequipping must not delete the materia, and copying a character must be a deep copy.
* **`IMateriaSource` interface and `MateriaSource`:** Learns up to `4` materias with `learnMateria()` and creates new ones with `createMateria(type)`, which returns `0` for an unknown type.
* **Concepts:** Interfaces, pure virtual classes, the clone pattern, ownership and deep copy of an inventory.

---

## Installation & Run Steps

### 1. System Prerequisites
Make sure you have a C++ compiler and `make` installed. On Debian/Ubuntu:

    sudo apt-get install make clang

### 2. Compile an Exercise
Go into the folder of the exercise and run `make`:

    cd ex03
    make

### 3. Run It
Each exercise generates its own executable:

    ./animal
    ./animal
    ./animal
    ./materia

---

## Testing

Each exercise has a `main` based on the one from the subject, which is the first thing to check:

    ./animal

To check for leaks and invalid accesses, use `valgrind`:

    valgrind --leak-check=full ./animal

Also test by hand:

* **ex01:** Copy a `Dog` or `Cat`, change the original and confirm the copy keeps its own ideas.
* **ex03:** Equip more than 4 materias, use empty slots, unequip and copy a `Character`, then check that nothing leaks or is deleted twice.

---

## References

* **[C++ reference: virtual functions](https://en.cppreference.com/w/cpp/language/virtual)**
* **[C++ reference: abstract classes](https://en.cppreference.com/w/cpp/language/abstract_class)**
* **[Learn C++](https://www.learncpp.com/)**

---

## AI Usage Declaration

AI tools were used to assist with:

* **Documentation Support:** Structuring and writing this README file.

---
