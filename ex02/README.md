# Exercise 02: No, you need form 28B, not 28C...

## Table of Contents
- [Project Overview](#project-overview)
- [Learning Objectives](#learning-objectives)
- [Key Concepts](#key-concepts)
- [Class Hierarchy](#class-hierarchy)
- [Implementation Details](#implementation-details)
- [Grade System](#grade-system)
- [Execution Flow](#execution-flow)
- [Testing Strategy](#testing-strategy)
- [Compilation and Usage](#compilation-and-usage)

---

## Project Overview

This exercise extends Exercise 01 by transforming the concrete `Form` class into an **abstract base class** called `AForm`. You must implement three concrete form types, each with unique behavior when executed:

1. **ShrubberyCreationForm** - Creates ASCII tree files
2. **RobotomyRequestForm** - Attempts robotomy with random success
3. **PresidentialPardonForm** - Announces presidential pardon

### Requirements
- Make `Form` abstract by renaming it to `AForm` and adding a pure virtual function
- Implement three concrete form classes that inherit from `AForm`
- Add an `executeForm()` method to the `Bureaucrat` class
- Each form must have specific sign/execute grade requirements
- Each form performs a unique action when executed
- Proper exception handling for all operations

---

## Learning Objectives

### C++98 Concepts Covered:

1. **Abstract Classes**
   - Pure virtual functions (`virtual void action() const = 0;`)
   - Cannot instantiate abstract classes directly
   - Forces derived classes to implement specific methods

2. **Inheritance & Polymorphism**
   - Base class pointers to derived objects
   - Virtual function overriding
   - Runtime polymorphism

3. **Template Method Pattern**
   - Base class defines algorithm structure
   - Derived classes fill in specific steps
   - `AForm::execute()` defines the template, `action()` is the hook

4. **Exception Safety**
   - Exception handling in constructors
   - Exception propagation through call stack
   - Custom exception classes

5. **File I/O Operations**
   - Output file streams (`std::ofstream`)
   - File creation and writing
   - Error handling for file operations

6. **Random Number Generation**
   - C-style random with `std::rand()` and `std::srand()`
   - Seeding with `std::time()`

---

## Key Concepts

### Abstract Base Class (AForm)

```cpp
class AForm {
    virtual void action() const = 0;  // Pure virtual = abstract
    void execute(const Bureaucrat& executor) const;  // Template method
};
```

**Why Abstract?**
- **Code Reuse**: Common validation logic (`execute()`) lives in base class
- **Polymorphism**: Handle different form types uniformly
- **Extensibility**: Easy to add new form types
- **Enforcement**: Guarantees all forms implement required behavior

### Pure Virtual Functions

```cpp
virtual void action() const = 0;
```

- The `= 0` makes it pure virtual
- Class becomes abstract (cannot instantiate)
- Derived classes **must** implement this function
- Provides interface contract

### Template Method Pattern

```cpp
void AForm::execute(const Bureaucrat& executor) const {
    if (!isSigned)
        throw NotSignedException();
    if (executor.getGrade() > executeGrade)
        throw GradeTooLowException();
    action();  // Polymorphic call to derived class
}
```

**Pattern Structure**:
1. Base class defines the algorithm skeleton
2. Derived classes fill in specific steps
3. Ensures consistent validation across all forms
4. Allows unique behavior per form type

---

## Class Hierarchy

```
                    ┌─────────┐
                    │  AForm  │ (Abstract)
                    └────┬────┘
                         │
          ┌──────────────┼──────────────┐
          │              │              │
┌─────────▼─────────┐   │   ┌──────────▼───────────┐
│ ShrubberyCreation │   │   │ PresidentialPardon   │
│      Form         │   │   │       Form           │
└───────────────────┘   │   └──────────────────────┘
                        │
              ┌─────────▼──────────┐
              │  RobotomyRequest   │
              │       Form         │
              └────────────────────┘
```

### Class Relationships

**AForm (Abstract Base Class)**
- Common attributes: `name`, `isSigned`, `signGrade`, `executeGrade`
- Common methods: `beSigned()`, `execute()`, getters
- Pure virtual: `action()`
- Exception classes: `GradeTooHighException`, `GradeTooLowException`, `NotSignedException`

**Bureaucrat**
- Has methods: `signForm(AForm&)`, `executeForm(const AForm&)`
- Uses polymorphism to work with any form type

---

## Implementation Details

### 1. ShrubberyCreationForm

**Purpose**: Creates a file with ASCII trees

**Specifications**:
- Sign grade: 145
- Execute grade: 137
- Creates file: `<target>_shrubbery`

**Implementation**:
```cpp
void ShrubberyCreationForm::action() const {
    std::ofstream file((target + "_shrubbery").c_str());
    if (!file.is_open())
        throw std::runtime_error("Failed to create file");
    
    file << "        *        " << std::endl;
    // ... more tree lines ...
    file.close();
    std::cout << "Shrubbery has been created at " << target << "_shrubbery" << std::endl;
}
```

**Key Points**:
- Uses C++98 `std::ofstream` for file operations
- `.c_str()` needed for C++98 string concatenation
- File created in current directory
- Must handle file creation failures

---

### 2. RobotomyRequestForm

**Purpose**: Robotomizes target with 50% success rate

**Specifications**:
- Sign grade: 72
- Execute grade: 45
- Random success/failure

**Implementation**:
```cpp
void RobotomyRequestForm::action() const {
    std::cout << "          Drilling noises" << std::endl;
    
    std::srand(std::time(0));  // Seed RNG with current time
    if (std::rand() % 2)       // 0 or 1 (50/50)
        std::cout << target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy failed on " << target << "!" << std::endl;
}
```

**Random Number Generation**:
- `std::srand(time(0))` - Seeds random generator (call once)
- `std::rand()` - Returns pseudo-random integer
- `% 2` - Modulo operation gives 0 or 1 (even/odd)
- Results in 50% success rate

**Note**: Seeding in `action()` means each call gets different time, potentially same seed if called quickly. Better to seed once in `main()`.

---

### 3. PresidentialPardonForm

**Purpose**: Announces presidential pardon (hardest form)

**Specifications**:
- Sign grade: 25
- Execute grade: 5 (most restrictive)
- Simple message output

**Implementation**:
```cpp
void PresidentialPardonForm::action() const {
    std::cout << target << " has been pardoned by Zaphod Beeblebrox."
              << std::endl;
}
```

**Cultural Reference**:
- Zaphod Beeblebrox from "The Hitchhiker's Guide to the Galaxy"
- President of the Galaxy (humorous reference)

---

## Grade System

### Grade Scale
- **Range**: 1 (highest) to 150 (lowest)
- **Lower number = Higher authority**
- Grade 1 can sign/execute anything
- Grade 150 has minimal authority

### Form Requirements

| Form Type                | Sign Grade | Execute Grade | Difficulty |
|--------------------------|------------|---------------|------------|
| ShrubberyCreationForm    | 145        | 137          | Easy       |
| RobotomyRequestForm      | 72         | 45           | Medium     |
| PresidentialPardonForm   | 25         | 5            | Hard       |

### Grade Logic

```cpp
// To sign/execute, bureaucrat's grade must be EQUAL or LOWER
if (bureaucrat.getGrade() > form.getSignGrade())
    throw GradeTooLowException();

// Example:
// Form requires grade 50
// Bureaucrat with grade 30 ✓ (can do it - higher authority)
// Bureaucrat with grade 70 ✗ (cannot - lower authority)
```

**Remember**: Lower grade number = Higher authority = Can do more

---

## Execution Flow

### Complete Form Lifecycle

```
1. CREATION
   ┌─────────────────────────────────┐
   │ Form form("target")             │
   │ - Name set (const)              │
   │ - Grades set (const)            │
   │ - isSigned = false              │
   └─────────────────────────────────┘
                  ↓
2. SIGNING
   ┌─────────────────────────────────┐
   │ bureaucrat.signForm(form)       │
   │   → form.beSigned(bureaucrat)   │
   │   → Check grade requirements    │
   │   → Set isSigned = true         │
   └─────────────────────────────────┘
                  ↓
3. EXECUTION
   ┌─────────────────────────────────┐
   │ bureaucrat.executeForm(form)    │
   │   → form.execute(bureaucrat)    │
   │   → Check if signed             │
   │   → Check execute grade         │
   │   → Call action()               │
   └─────────────────────────────────┘
                  ↓
4. ACTION (Polymorphic)
   ┌─────────────────────────────────┐
   │ Virtual function dispatch       │
   │ - Shrubbery → Create file       │
   │ - Robotomy  → Random result     │
   │ - Pardon    → Print message     │
   └─────────────────────────────────┘
```

### Exception Handling

```cpp
try {
    form.execute(bureaucrat);
}
catch (const AForm::NotSignedException& e) {
    // Form wasn't signed first
}
catch (const AForm::GradeTooLowException& e) {
    // Bureaucrat doesn't have authority
}
catch (const std::exception& e) {
    // Catch-all for other errors (e.g., file I/O)
}
```

---

## Testing Strategy

### Test Categories

#### 1. **Basic Functionality Tests**
```cpp
// Each form type can be created
// Each form can be signed by appropriate grade
// Each form can be executed after signing
```

#### 2. **Grade Validation Tests**
```cpp
// Sign with insufficient grade → Exception
// Execute with insufficient grade → Exception
// Execute unsigned form → Exception
```

#### 3. **Polymorphism Tests**
```cpp
// Treat different forms through AForm pointer
// Virtual function dispatch works correctly
AForm* form = new RobotomyRequestForm("target");
form->execute(bureaucrat);  // Calls correct action()
```

#### 4. **Edge Cases**
```cpp
// Boundary grades (exactly at threshold)
// Grade 1 bureaucrat (can do everything)
// Grade 150 bureaucrat (can do almost nothing)
```

#### 5. **Memory Management**
```cpp
// Copy constructors work
// Assignment operators work
// No memory leaks (destructor chain)
```

#### 6. **Specific Behavior Tests**
```cpp
// Shrubbery: File is created with correct name
// Robotomy: Different results on multiple runs
// Pardon: Correct message output
```

### Actual Output of `./bureaucrat`

Constructor/destructor messages omitted. The robotomy result is random.

```
thaqer signed ShrubberyCreationForm
Shrubbery has been created at tree_shrubbery
thaqer executed ShrubberyCreationForm
thaqer signed RobotomyRequestForm
          Drilling noises
Robotomy failed on ttt!
thaqer executed RobotomyRequestForm
thaqer signed PresidentialPardonForm
boss has been pardoned by Zaphod Beeblebrox.
thaqer executed PresidentialPardonForm
```

---

## Compilation and Usage

### Building the Project

```bash
# Compile
make

# Run tests
./bureaucrat

# Clean up
make fclean
```

### Makefile Targets

- `make` / `make all` - Compile the project
- `make clean` - Remove object files
- `make fclean` - Remove objects, executable, and shrubbery files
- `make re` - Rebuild everything

### Expected Files After Execution

```
bureaucrat          # Executable
tree_shrubbery      # Created by ShrubberyCreationForm("tree") in main.cpp
```

### View the Created Tree

```bash
cat tree_shrubbery
```

---

## Design Patterns Used

### 1. Template Method Pattern
- **Where**: `AForm::execute()` + derived `action()`
- **Why**: Ensures consistent validation while allowing varied behavior
- **Benefit**: Changes to validation logic only need one update

### 2. Exception as Control Flow
- **Where**: Grade validation, signature checking
- **Why**: Clear error handling, impossible to ignore failures
- **Benefit**: Type-safe error propagation

### 3. Inheritance Hierarchy
- **Where**: AForm base, three concrete forms
- **Why**: Code reuse, polymorphism
- **Benefit**: Extensible design (easy to add Form types)

---

## Common Pitfalls & Solutions

### ❌ Pitfall 1: Forgetting to Make AForm Abstract
```cpp
// Wrong - concrete Form class
class Form { };

// Correct - abstract AForm
class AForm {
    virtual void action() const = 0;  // Pure virtual
};
```

### ❌ Pitfall 2: Wrong Grade Comparison
```cpp
// Wrong
if (bureaucrat.getGrade() < signGrade)  // ❌

// Correct (lower number = higher authority)
if (bureaucrat.getGrade() > signGrade)  // ✓
```

### ❌ Pitfall 3: Executing Before Signing
```cpp
// Wrong
form.execute(bureaucrat);  // NotSignedException!

// Correct
form.beSigned(bureaucrat);
form.execute(bureaucrat);
```

### ❌ Pitfall 4: Forgetting to Override action()
```cpp
// Compiler error - abstract class can't be instantiated
class MyForm : public AForm {
    // Missing: void action() const;   ('override' does not exist in C++98)
};
```

### ❌ Pitfall 5: File Not Created (Too Low Grade)
```cpp
// Bob grade 140 cannot execute (needs 137)
Bureaucrat bob("Bob", 140);
ShrubberyCreationForm form("home");
bob.signForm(form);
bob.executeForm(form);  // GradeTooLowException!
```

---

## Extension Ideas

### 1. Form Factory
```cpp
class FormFactory {
public:
    static AForm* createForm(std::string type, std::string target);
};
```

### 2. Form Collections
```cpp
std::vector<AForm*> forms;
forms.push_back(new ShrubberyCreationForm("garden"));
forms.push_back(new RobotomyRequestForm("Bender"));
```

### 3. Chain of Responsibility
```cpp
// Multiple bureaucrats try to sign until one succeeds
```

---

## Key Takeaways

1. **Abstract classes** enforce contracts and enable polymorphism
2. **Pure virtual functions** make classes abstract
3. **Template Method Pattern** separates algorithm from implementation
4. **Inheritance** enables code reuse and extensibility
5. **Virtual functions** enable runtime polymorphism
6. **Exception handling** provides type-safe error management
7. **Grade system** models real-world permission hierarchies

---

## Resources

- **C++ Concepts**: Abstract classes, pure virtual functions, polymorphism
- **Design Patterns**: Template Method Pattern
- **File I/O**: std::ofstream, file handling
- **Random Generation**: std::rand(), std::srand(), std::time()
- **Exception Handling**: try-catch blocks, exception propagation

---

**Project Completion Checklist:**
- [x] AForm is abstract with pure virtual `action()`
- [x] All three form types implemented
- [x] Correct grade requirements for each form
- [x] ShrubberyCreationForm creates files
- [x] RobotomyRequestForm has random success
- [x] PresidentialPardonForm prints message
- [x] Bureaucrat has `executeForm()` method
- [x] All exceptions handled properly
- [x] Orthodox Canonical Form for all classes
- [x] Tests in main()
- [x] No memory leaks
- [x] Makefile with fclean removes shrubbery files
- [x] Code compiles with -Wall -Wextra -Werror -std=c++98

---

**Good luck with your evaluation! 🚀**
