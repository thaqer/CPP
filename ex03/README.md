# Exercise 03: At least this beats coffee-making

## Table of Contents
- [Project Overview](#project-overview)
- [Learning Objectives](#learning-objectives)
- [Key Concepts](#key-concepts)
- [Class Hierarchy](#class-hierarchy)
- [Implementation Details](#implementation-details)
- [Design Pattern Analysis](#design-pattern-analysis)
- [Execution Flow](#execution-flow)
- [Testing Strategy](#testing-strategy)
- [Compilation and Usage](#compilation-and-usage)

---

## Project Overview

This exercise builds upon Exercise 02 by introducing the **Intern** class - a factory pattern implementation that creates forms dynamically based on string input. The Intern doesn't need to know or understand what forms do; it just knows how to create them on demand.

### Requirements
- Create an `Intern` class that can instantiate forms by name
- Implement a `makeForm()` method that takes form name and target
- Avoid long if/else chains: this implementation maps form names to creation functions with an array of function pointers
- Print an explicit error message when the form name is unknown
- Return NULL when the form name is unknown
- Properly manage memory for dynamically created forms

### Output Messages
- On success the subject requires: `Intern creates <form>`
- On an unknown name the subject requires an explicit error message. This implementation prints:
  `Intern cannot create form: <name> (unknown form type)`

---

## Learning Objectives

### C++98 Concepts Covered:

1. **Factory Pattern**
   - Encapsulates object creation logic
   - Creates objects without specifying exact class
   - Returns base class pointers to derived objects

2. **Function Pointers**
   - Pointers to functions (C-style function pointers)
   - Array of function pointers for dispatch tables
   - Static member functions as targets

3. **Static Member Functions**
   - No `this` pointer (class-level, not instance-level)
   - Can be called without object instance
   - Perfect for factory methods

4. **String Comparison & Lookup**
   - Parallel arrays for name-to-function mapping
   - Linear search through form names
   - Case-sensitive string matching

5. **Memory Management**
   - Dynamic allocation with `new`
   - Caller responsibility to `delete`
   - NULL return for error handling (C++98 style)

6. **Loose Coupling**
   - Intern doesn't know about form implementations
   - Client code doesn't know which concrete class is created
   - Reduces dependencies between components

---

## Key Concepts

### Factory Pattern

The Factory Pattern is a creational design pattern that provides an interface for creating objects without specifying their exact class.

```cpp
// Without Factory (tight coupling)
ShrubberyCreationForm* form = new ShrubberyCreationForm("target");

// With Factory (loose coupling)
Intern intern;
AForm* form = intern.makeForm("shrubbery creation", "target");
```

**Benefits**:
- **Decoupling**: Client doesn't need to know concrete class names
- **Flexibility**: Easy to add new form types
- **Single Responsibility**: Creation logic centralized in one place
- **User-Friendly**: Uses human-readable strings instead of class names

### Function Pointers in C++98

```cpp
// Function pointer type
AForm* (*functionPtr)(const std::string&);

// Array of function pointers
AForm* (*formCreators[3])(const std::string&) = {
    &Intern::createShrubbery,
    &Intern::createRobotomy,
    &Intern::createPresidential
};

// Calling through pointer
AForm* form = formCreators[0]("target");  // Creates ShrubberyCreationForm
```

**Why Static Members?**
- Function pointers need consistent signature
- Static functions don't have implicit `this` parameter
- Can be addressed like regular functions

### Parallel Array Dispatch Table

```cpp
std::string formNames[3] = {
    "shrubbery creation",
    "robotomy request",
    "presidential pardon"
};

AForm* (*formCreators[3])(const std::string&) = {
    &Intern::createShrubbery,
    &Intern::createRobotomy,
    &Intern::createPresidential
};

// Lookup: find index in names, call corresponding creator
for (int i = 0; i < 3; i++) {
    if (formNames[i] == name)
        return formCreators[i](target);
}
```

---

## Class Hierarchy

```
┌───────────┐  makeForm() returns AForm*  ┌─────────┐
│  Intern   │ ──────────────────────────▶ │  AForm  │ (Abstract)
│ (Factory) │                             └────┬────┘
└───────────┘                                  │
                          ┌────────────────────┼────────────────────┐
                          │                    │                    │
               ┌──────────▼────────┐ ┌─────────▼────────┐ ┌─────────▼──────────┐
               │ ShrubberyCreation │ │ RobotomyRequest  │ │ PresidentialPardon │
               │       Form        │ │      Form        │ │        Form        │
               └───────────────────┘ └──────────────────┘ └────────────────────┘
```

### Class Relationships

**Intern (Factory)**
- Creates forms dynamically
- Returns `AForm*` (base class pointer)
- Uses function pointers for dispatch
- No knowledge of form implementations

**AForm & Derived Classes**
- Same as Exercise 02
- Intern creates them but doesn't manipulate them

**Bureaucrat**
- Uses forms created by Intern
- Signs and executes them

---

## Implementation Details

### Intern Class Structure

```cpp
class Intern {
private:
    // Static factory methods (no 'this' pointer)
    static AForm* createShrubbery(const std::string& target);
    static AForm* createRobotomy(const std::string& target);
    static AForm* createPresidential(const std::string& target);

public:
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();

    // The factory method
    AForm* makeForm(const std::string& name, const std::string& target);
};
```

### Static Factory Methods

```cpp
AForm* Intern::createShrubbery(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(const std::string& target) {
    return new PresidentialPardonForm(target);
}
```

**Key Points**:
- `static` = no access to instance members
- Simple: just instantiate and return
- Each function has same signature
- Compatible with function pointer array

### makeForm() Implementation

```cpp
AForm* Intern::makeForm(const std::string& name, const std::string& target) {
    // Dispatch table: names
    std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    
    // Dispatch table: function pointers
    AForm* (*formCreators[3])(const std::string&) = {
        &Intern::createShrubbery,
        &Intern::createRobotomy,
        &Intern::createPresidential
    };
    
    // Linear search through names
    for (int i = 0; i < 3; i++) {
        if (formNames[i] == name) {
            std::cout << "Intern creates " << name << std::endl;
            return formCreators[i](target);  // Call through pointer
        }
    }
    
    // Not found
    std::cout << "Intern cannot create form: " << name 
              << " (unknown form type)" << std::endl;
    return NULL;
}
```

**Algorithm**:
1. Define parallel arrays (names and creators)
2. Iterate through form names
3. On match: announce creation and call creator
4. On no match: announce failure and return NULL

### Memory Management

```cpp
// Intern creates form
Intern intern;
AForm* form = intern.makeForm("shrubbery creation", "home");

// Check if creation succeeded
if (form) {
    // Use the form
    bureaucrat.signForm(*form);
    bureaucrat.executeForm(*form);
    
    // Caller is responsible for deletion!
    delete form;
}
```

**Important**: 
- Intern creates with `new`
- Caller must `delete`
- Always check for NULL before use

---

## Design Pattern Analysis

### Factory Method Pattern

**Intent**: Define an interface for creating objects, but let subclasses/factory decide which class to instantiate.

**Participants**:
- **Product** (AForm): Abstract interface
- **Concrete Products** (ShrubberyCreationForm, etc.): Implementations
- **Creator** (Intern): Factory class with creation method
- **Client** (main): Uses factory to get products

**Sequence Diagram**:
```
Client          Intern              AForm
  |               |                   |
  |--makeForm()-->|                   |
  |               |--new Concrete---->|
  |               |                   |
  |<--AForm*------|                   |
  |               |                   |
  |----------use form--------------->|
  |               |                   |
  |----------delete form------------>|
```

### Alternatives & Trade-offs

#### 1. Function Pointers (Our Implementation)
```cpp
AForm* (*creators[3])(const std::string&) = {...};
```
**Pros**: Fast, low overhead, C++98 compatible
**Cons**: Fixed size, must know all types at compile time

#### 2. Map with Strings (C++11+)
```cpp
std::map<std::string, std::function<AForm*(const std::string&)>> creators;
```
**Pros**: Dynamic, easy to extend
**Cons**: Not C++98 (`std::function` is C++11)

#### 3. Switch Statement
```cpp
switch (formType) {
    case SHRUBBERY: return new ShrubberyCreationForm(target);
    ...
}
```
**Pros**: Simple, readable
**Cons**: Doesn't work with strings, needs enum

#### 4. If-Else Chain
```cpp
if (name == "shrubbery creation")
    return new ShrubberyCreationForm(target);
else if (name == "robotomy request")
    return new RobotomyRequestForm(target);
...
```
**Pros**: Simple, no arrays needed
**Cons**: Verbose, repetitive

**Our choice (function pointers) is optimal for C++98**.

---

## Execution Flow

### Complete Factory Creation Flow

```
1. CLIENT REQUEST
   ┌─────────────────────────────────────────┐
   │ Intern intern;                          │
   │ AForm* form = intern.makeForm(          │
   │     "robotomy request", "Bender"        │
   │ );                                      │
   └─────────────────────────────────────────┘
                      ↓
2. DISPATCH TABLE LOOKUP
   ┌─────────────────────────────────────────┐
   │ Search formNames[] for match            │
   │ - "shrubbery creation" ❌               │
   │ - "robotomy request"   ✓ (index 1)      │
   │ Found at index 1                        │
   └─────────────────────────────────────────┘
                      ↓
3. CREATOR FUNCTION CALL
   ┌─────────────────────────────────────────┐
   │ formCreators[1]("Bender")               │
   │   → Intern::createRobotomy("Bender")    │
   │   → new RobotomyRequestForm("Bender")   │
   └─────────────────────────────────────────┘
                      ↓
4. RETURN PRODUCT
   ┌─────────────────────────────────────────┐
   │ AForm* form = <address>                 │
   │ Type: RobotomyRequestForm               │
   │ Target: "Bender"                        │
   └─────────────────────────────────────────┘
                      ↓
5. USE & CLEANUP
   ┌─────────────────────────────────────────┐
   │ if (form) {                             │
   │     bureaucrat.signForm(*form);         │
   │     bureaucrat.executeForm(*form);      │
   │     delete form;  // Caller's duty!     │
   │ }                                       │
   └─────────────────────────────────────────┘
```

### Error Handling Flow

```
Client: makeForm("invalid form", "target")
                      ↓
        Search formNames[] (no match)
                      ↓
        Print error message
                      ↓
        return NULL
                      ↓
Client: Check if (form) → false → handle gracefully
```

**No exception for unknown names**: this implementation prints a message and returns NULL, so the caller must check the pointer before using it.

---

## Testing Strategy

### Test Categories

#### 1. **Basic Factory Tests**
```cpp
// Create each form type
form = intern.makeForm("shrubbery creation", "home");
form = intern.makeForm("robotomy request", "target");
form = intern.makeForm("presidential pardon", "criminal");

// Verify non-NULL returns
// Verify correct form type created
```

#### 2. **Unknown Form Tests**
```cpp
// Invalid form name
form = intern.makeForm("unknown form", "target");
// Should return NULL
// Should print error message

// Case sensitivity
form = intern.makeForm("Shrubbery Creation", "target");  // NULL
form = intern.makeForm("ROBOTOMY REQUEST", "target");     // NULL
```

#### 3. **Integration Tests**
```cpp
// Create form via Intern
Intern intern;
AForm* form = intern.makeForm("presidential pardon", "Arthur");

// Use with Bureaucrat
Bureaucrat boss("Boss", 1);
boss.signForm(*form);
boss.executeForm(*form);

// Cleanup
delete form;
```

#### 4. **Memory Management Tests**
```cpp
// Multiple forms from same intern
Intern intern;
AForm* form1 = intern.makeForm("shrubbery creation", "home");
AForm* form2 = intern.makeForm("robotomy request", "target");

// Both valid, independent forms
delete form1;
delete form2;

// Multiple interns
Intern intern1, intern2;
AForm* f1 = intern1.makeForm("shrubbery creation", "garden");
AForm* f2 = intern2.makeForm("shrubbery creation", "park");
// Different forms, same type
```

#### 5. **Orthodox Canonical Form Tests**
```cpp
// Copy constructor
Intern intern1;
Intern intern2(intern1);  // Should work (no state to copy)

// Assignment operator
Intern intern3;
intern3 = intern1;  // Should work

// Forms still created correctly
```

#### 6. **String Matching Tests**
```cpp
// Exact matches (should work)
"shrubbery creation"
"robotomy request"
"presidential pardon"

// Near misses (should fail)
"shrubbery"           // Incomplete
"shrubberycreation"   // No space
"robotomy"            // Incomplete
"presidential"        // Incomplete
```

### Expected Output Patterns

```
# Actual output of ./bureaucrat (constructor/destructor messages omitted;
# the robotomy result is random)
Intern creates presidential pardon
Intern creates robotomy request
Intern creates shrubbery creation
thaqer signed PresidentialPardonForm
presidential has been pardoned by Zaphod Beeblebrox.
thaqer executed PresidentialPardonForm
thaqer signed RobotomyRequestForm
          Drilling noises
Robotomy failed on robotomy!
thaqer executed RobotomyRequestForm
thaqer signed ShrubberyCreationForm
Shrubbery has been created at shrubbery_shrubbery
thaqer executed ShrubberyCreationForm

# An unknown name prints:
Intern cannot create form: unknown form (unknown form type)
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

### Makefile Considerations

Same as Exercise 02, but now includes:
- `src/Intern.cpp`
- `includes/Intern.hpp`

### Running the Program

```bash
$ make
$ ./bureaucrat

# Creates:
# - Executable: bureaucrat
# - Potential shrubbery files if created forms are executed
```

### Memory Leak Checking

```bash
# Compile with AddressSanitizer (detects leaks on Linux)
c++ -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g -Iincludes src/*.cpp -o bureaucrat
./bureaucrat

# Or use valgrind
valgrind --leak-check=full ./bureaucrat
```

**Important**: All dynamically created forms must be deleted!

---

## Common Pitfalls & Solutions

### ❌ Pitfall 1: Non-Static Factory Methods
```cpp
// Wrong - a non-static member function has a hidden 'this' parameter,
// so its address is a pointer-to-member, not a plain function pointer
class Intern {
    AForm* createShrubbery(const std::string& target);  // Non-static
};

// Function pointer won't compile
AForm* (*ptr)(const std::string&) = &Intern::createShrubbery;  // ❌
```

**Solution**: Make factory methods `static`
```cpp
static AForm* createShrubbery(const std::string& target);  // ✓
```

### ❌ Pitfall 2: Forgetting to Delete Forms
```cpp
// Memory leak!
Intern intern;
AForm* form = intern.makeForm("shrubbery creation", "home");
// ... use form ...
// Missing: delete form;  ❌
```

**Solution**: Always delete dynamically allocated forms
```cpp
if (form) {
    // ... use form ...
    delete form;  // ✓
}
```

### ❌ Pitfall 3: Not Checking for NULL
```cpp
// Dangerous - accessing NULL pointer!
AForm* form = intern.makeForm("invalid", "target");
std::cout << *form << std::endl;  // ❌ Segfault if NULL
```

**Solution**: Always check before dereferencing
```cpp
AForm* form = intern.makeForm("invalid", "target");
if (form) {  // ✓
    std::cout << *form << std::endl;
    delete form;
}
```

### ❌ Pitfall 4: Case-Sensitive Mismatches
```cpp
// Won't match - case sensitive!
form = intern.makeForm("Shrubbery Creation", "home");  // ❌ NULL
form = intern.makeForm("ROBOTOMY REQUEST", "target");  // ❌ NULL
```

**Solution**: Use exact lowercase names as defined
```cpp
form = intern.makeForm("shrubbery creation", "home");  // ✓
```

### 💡 Note 5: Function Pointer Syntax
```cpp
// Both are valid for static member functions:
AForm* (*creators[3])(const std::string&) = {
    Intern::createShrubbery,   // implicit conversion to pointer
};
AForm* (*creators[3])(const std::string&) = {
    &Intern::createShrubbery,  // explicit '&' (used here, clearer intent)
};
```

### 💡 Note 6: Unknown Forms - Exception or NULL?
```cpp
// Also possible, but then every caller must catch it
if (not found)
    throw UnknownFormException();
```

**This implementation**: print an error message and return NULL
```cpp
if (not found) {
    std::cout << "Intern cannot create form..." << std::endl;
    return NULL;  // ✓
}
```

---

## Advanced Concepts

### Extensibility

**Adding a New Form Type**:

1. Create the new form class
2. Add static factory method in Intern
3. Add to dispatch tables in `makeForm()`

```cpp
// Step 1: New form class
class TaxForm : public AForm { ... };

// Step 2: Factory method ('static' goes only on the declaration in Intern.hpp)
AForm* Intern::createTax(const std::string& target) {
    return new TaxForm(target);
}

// Step 3: Update dispatch tables
std::string formNames[4] = {
    "shrubbery creation",
    "robotomy request",
    "presidential pardon",
    "tax form"  // New!
};

AForm* (*formCreators[4])(const std::string&) = {
    &Intern::createShrubbery,
    &Intern::createRobotomy,
    &Intern::createPresidential,
    &Intern::createTax  // New!
};
```

**Limitation**: Must recompile to add forms. True plugin architecture requires dynamic loading.

### Function Pointer Deep Dive

```cpp
// Declaration: pointer to function taking string, returning AForm*
AForm* (*functionPtr)(const std::string&);

// Assignment: address of static member function
functionPtr = &Intern::createShrubbery;

// Call: parenthesize pointer, then call
AForm* result = (*functionPtr)("target");

// Shorthand call: a function pointer can be called directly
AForm* result = functionPtr("target");

// Array: 3 such function pointers
AForm* (*array[3])(const std::string&);
```

---

## Key Takeaways

1. **Factory Pattern** encapsulates object creation and decouples client from concrete classes
2. **Function Pointers** enable dispatch tables and callbacks in C++98
3. **Static Member Functions** have no `this` pointer and can be used as function pointers
4. **Parallel Arrays** provide simple name-to-function mapping
5. **NULL Returns** are C++98 way to indicate failure (vs. exceptions in C++11+)
6. **Caller Responsibility** for memory management when factory returns raw pointers
7. **Loose Coupling** allows adding new products without changing client code

---

## Resources

### C++ Concepts
- Factory Method Pattern
- Function pointers
- Static member functions
- Dynamic memory allocation
- NULL pointer handling

### Design Patterns
- Factory Method
- Dispatch tables
- Parallel arrays for lookup

### Best Practices
- Always check pointers before dereferencing
- Delete what you new
- Use static for stateless factory methods
- Clear error messages for failures

---

## Comparison: Ex02 vs Ex03

| Aspect                | Ex02                     | Ex03                          |
|-----------------------|--------------------------|-------------------------------|
| **Focus**             | Polymorphism             | Factory Pattern               |
| **New Class**         | AForm + 3 Concrete Forms | Intern                        |
| **Creation Method**   | Direct instantiation     | Factory method                |
| **Coupling**          | Client knows all classes | Client uses string names      |
| **Extensibility**     | Must update client code  | Only update factory           |
| **Error Handling**    | Exceptions               | Exceptions + NULL for unknown form names |
| **Key Technique**     | Virtual functions        | Function pointers             |

---

**Project Completion Checklist:**
- [x] Intern class with Orthodox Canonical Form
- [x] Static factory methods for each form type
- [x] makeForm() with function pointer dispatch
- [x] Parallel arrays for name-to-creator mapping
- [x] Correct form names (lowercase, with spaces)
- [x] NULL return for unknown forms (no exceptions)
- [x] Success/failure messages printed
- [x] Memory management: delete all created forms
- [x] No memory leaks (checked with AddressSanitizer)
- [x] Integration tests with Bureaucrat
- [x] Makefile includes Intern.cpp
- [x] Code compiles with -Wall -Wextra -Werror -std=c++98
- [x] All previous exercise functionality still works

---

**Good luck with your evaluation! 🚀**
