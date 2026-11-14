# CPP Modules

My solutions to the 42 School C++ Modules (00–09), written in C++98.
Each module lives on its own branch.

## Modules

| Module | Branch | Topics | Exercises |
|--------|--------|--------|-----------|
| Module 00 | [module00](../../tree/module00) | Namespaces, classes, member functions, stdio streams, initialization lists, static, const | ex00 Megaphone · ex01 PhoneBook |
| Module 01 | [module01](../../tree/module01) | Memory allocation, pointers to members, references, switch statement | ex00–ex05 (Zombie, HI THIS IS BRAIN, Weapon/HumanA/HumanB, file replace, Harl) |
| Module 02 | [module02](../../tree/module02) | Ad-hoc polymorphism, operator overloading, Orthodox Canonical Form | ex00–ex02 (Fixed-point number class) |
| Module 03 | [module03](../../tree/module03) | Inheritance | ex00–ex02 (ClapTrap, ScavTrap, FragTrap) |
| Module 04 | [module04](../../tree/module04) | Subtype polymorphism, abstract classes, interfaces | ex00–ex02 (Animal, Dog, Cat, Brain) |
| Module 05 | [module05](../../tree/module05) | Repetition and exceptions | ex00–ex03 (Bureaucrat, Form, AForm, Intern) |
| Module 06 | [module06](../../tree/module06) | C++ casts (`static_cast`, `reinterpret_cast`, `dynamic_cast`) | ex00 ScalarConverter · ex01 Serialize · ex02 Identify real type |
| Module 07 | [module07](../../tree/module07) | Function templates, class templates | ex00 swap/min/max · ex01 iter · ex02 Array |
| Module 08 | [module08](../../tree/module08) | Templated containers, iterators, algorithms (STL) | ex00 easyfind · ex01 Span · ex02 MutantStack |
| Module 09 | [module09](../../tree/module09) | Using STL containers (`std::map`, `std::stack`, `std::vector`, `std::list`) | ex00 Bitcoin Exchange · ex01 RPN · ex02 PmergeMe (Ford-Johnson sort) |

## Usage

```bash
git clone git@github.com:thaqer/CPP.git
cd CPP
git checkout module05      # pick any moduleXX
cd ex00 && make && ./<program>
```

Every exercise has its own `Makefile` and compiles with `c++ -Wall -Wextra -Werror -std=c++98`.
