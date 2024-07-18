// FORME CACONIQUE - Coplien's form

	// HPP








// CONST

- When const is at the end of the member function declaration, it means that the function does not modify the state of the object.
This means that none of the member variables can be changed within that function. These functions can be called on const objects.

	std::string const & getTitle() const;
	void introduce() const;

Here, getTitle and introduce promise not to modify any member variables of the Warlock object.

- When const is at the beginning of the function declaration (before the return type), it means the function returns a constant value.
This implies that the caller cannot modify the returned value directly.

	std::string const & getTitle() const;

In this case, getTitle returns a reference to a constant std::string, meaning the caller cannot modify the returned string directly.
This is important for protecting internal class data from being changed inadvertently.

- When const is used inside the parameter list, it means that the parameter is read-only within the function.
The function will not (and cannot) modify the value of this parameter. If the parameter is passed by reference, this can also help avoid unnecessary copying.

	void setTitle(std::string const & title);

Here, setTitle takes a constant reference to a std::string.
This means the function will not modify the input string title, and it also avoids copying the string, which is more efficient.

// REFERENCES, POINTERS, VALUES			(cpp_01/ex02)

#include <iostream>
#include <string>

int	main(void)
{
	std::string	str;
	str = "HI THIS IS BRAIN";

	std::string *stringPTR;
	stringPTR = &str;

	std::string &stringREF(str);

	std::cout << "1 - Memory adress of the string variable: " << &str << std::endl;
	std::cout << "    Memory adress held by stringPTR: " << stringPTR << std::endl;
	std::cout << "    Memory adress held by stringREF: " << &stringREF << std::endl;
	
	std::cout << "2 - Value of the string variable: " << str << std::endl;
	std::cout << "    Value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "    Value pointed to by stringREF: " << stringREF << std::endl;

	return (0);
}


// POINTERS OR REFERENCES?			(cpp_01/ex03)

	// ...


// FILES MANIPULATION			(cpp_01/ex04)

	// ...


// POINTER TO FUNCTIONS			(cpp_01/ex05)


void	Harl::debug(void)
{
	std::cout << "[DEBUG] I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[INFO] I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

// and other functions...

void	Harl::complain(std::string level)
{
	int	detectedLevel = levelDetector(level);
	void	(Harl::*levelFunctions[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	if (detectedLevel == -1)
		std::cout << "Invalid level. Expected level are [DEBUG]/[INFO]/[WARNING]/[ERROR]." << std::endl;
	else
		(this->*levelFunctions[detectedLevel])();
}


// SWITCH CASE			(cpp_01/ex06)


// ABSTRACT CALSSES - BASE CALSSES - INTERFACES

Sure, let's break it down simply:

### Abstract Classes
- **What**: An abstract class is a class that cannot be used to create objects directly.
- **Why**: It's meant to be a blueprint for other classes.
- **How**: It has at least one pure virtual function (a function with `= 0`).
- **Example**:
  ```cpp
  class Animal {
  public:
      virtual void makeSound() = 0; // Pure virtual function
  };
  ```

### Base Classes
- **What**: A base class is a class that is meant to be inherited by other classes.
- **Why**: It provides common properties and functions that derived classes can use.
- **Example**:
  ```cpp
  class Animal {
  public:
      void eat() {
          // Eating behavior
      }
  };
  ```

### Interface
- **What**: An interface is a class with only pure virtual functions.
- **Why**: It defines a contract for what derived classes should do, but not how they do it.
- **Example**:
  ```cpp
  class Shape {
  public:
      virtual void draw() = 0; // Pure virtual function
      virtual void resize() = 0; // Another pure virtual function
  };
  ```

In summary:
- **Abstract classes** are blueprints with some defined behavior but need to be extended.
- **Base classes** provide common functionality for derived classes.
- **Interfaces** define what methods must be implemented by derived classes but don't provide any implementation themselves.

// ABSTRACT CLASSES INHERITAGE

Yes, abstract classes are a type of base class that can't be instantiated on their own. They are meant to be inherited by other classes that will implement their pure virtual functions.

### Inheriting an Abstract Class

Here's a simple step-by-step:

1. **Define the Abstract Class**: This class will have at least one pure virtual function.
2. **Inherit the Abstract Class**: Create a derived class that inherits from the abstract class.
3. **Implement Pure Virtual Functions**: In the derived class, provide implementations for all pure virtual functions.

### Example

#### Step 1: Define the Abstract Class

```cpp
class Animal {
public:
    virtual void makeSound() = 0; // Pure virtual function
    virtual ~Animal() {} // Virtual destructor
};
```

#### Step 2: Inherit the Abstract Class

```cpp
class Dog : public Animal {
public:
    void makeSound() override {
        std::cout << "Woof!" << std::endl;
    }
};
```

#### Step 3: Use the Derived Class

```cpp
int main() {
    Dog myDog;
    myDog.makeSound(); // Outputs: Woof!
    return 0;
}
```

### Explanation

1. **Abstract Class**: `Animal` has a pure virtual function `makeSound()` making it abstract.
2. **Derived Class**: `Dog` inherits from `Animal` and provides an implementation for `makeSound()`.
3. **Usage**: You can now create a `Dog` object and call its `makeSound()` function.

By following these steps, you can effectively inherit and implement an abstract class in C++.

// ABSTRACT CLASSES AND INTERFACES

### Abstract Classes
- **What**: A class that can't be instantiated on its own.
- **Why**: Provides a base with both implemented and pure virtual functions.
- **Usage**: Can have both regular and pure virtual methods.
- **Example**:
  ```cpp
  class Animal {
  public:
      void eat() { /* implementation */ }
      virtual void makeSound() = 0; // Pure virtual function
  };
  ```

### Interfaces
- **What**: A class with only pure virtual functions.
- **Why**: Defines a contract with no implementation, only function declarations.
- **Usage**: All methods must be pure virtual.
- **Example**:
  ```cpp
  class Shape {
  public:
      virtual void draw() = 0; // Pure virtual function
      virtual void resize() = 0; // Pure virtual function
  };
  ```

### Key Differences
- **Abstract Class**: Can have both implemented methods and pure virtual functions.
- **Interface**: Only pure virtual functions, no implemented methods.

//

