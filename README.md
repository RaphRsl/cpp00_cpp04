# cpp00_cpp04

When should I use reference / pointer ?
https://isocpp.org/wiki/faq/references#:~:text=Use%20references%20when%20you%20can,and%20pointers%20on%20the%20inside.

files manipulation in cpp
https://www.mygreatlearning.com/blog/file-handling-in-cpp/


=========== CPP03 - ex03, Diamond

A(1) : energy = 10
B : energy(A(1)) = 100
D : energy = B
A(2) : energy = 10
C : energy(A(2)) = 50
D : energy = C 

D::B.energy -> get -> 100
D::C.energy -> get -> 50


a		a
B		C
	D



A : energy = 10
B : energy(A) = 100
B : attack(A) = 100
C : attack(A) = 50
C : energy(A) = 50
D : energy = C ou B


	A
B		C
	D

=========== CPP04 - ex01, shallo/deep copy

https://www.geeksforgeeks.org/shallow-copy-and-deep-copy-in-c/


=========== CPP04 - ex02, base class non instantiable

https://www.appsloveworld.com/cplus/100/107/protected-constructor-to-make-base-class-not-instantiable


CPP06 - CASTING
https://cplusplus.com/articles/iG3hAqkS/

=========== CPP07 ex 00

why using :: before the template functions:
	The :: operator is used to specify the global namespace.
	In your case, you have defined min, max, and swap functions in your whatever.hpp file.
	These functions are template functions and can work with any data type.

	When you include whatever.hpp in your main file, these functions become part of
	the global namespace. Therefore, when you call min, max, or swap without ::,
	the compiler will use the versions from whatever.hpp.

	However, the std namespace also contains min, max, and swap functions.
	When you use std::string, the compiler prefers the min, max, and swap
	functions from the std namespace over the ones in the global namespace.
	This is due to Argument-Dependent Lookup (ADL), a feature in C++ where the compiler
	also considers functions in the namespace of the arguments.

	To force the compiler to use your versions of min, max, and swap,
	you need to use the :: operator to specify the global namespace.
	This is why you need to use ::min(a, b) and ::max(a, b) for strings, but not
	for floats. For floats, there is no min and max in the std namespace that takes two floats,
	so the compiler uses your versions without needing ::.

	============== CPP08 - ex00

	std::list<int>::const_iterator	it = test_list.end();
		--> FIND

The `find` function is a standard algorithm provided by the C++ Standard Library. It is used to find the first occurrence of a specific value in a range of elements.

Here's a breakdown of the `find` function in your code:

```cpp
it = find(intContainer.begin(), intContainer.end(), i);
```

- `intContainer.begin()`: This is an iterator pointing to the start of the container `intContainer`.
- `intContainer.end()`: This is an iterator pointing to the end of the container `intContainer`. It actually points one past the last element, not the last element itself.
- `i`: This is the value you are searching for in the container.
- `find`: This function will iterate over the range [begin, end) and return an iterator to the first element that equals `i`. If no such element is found, it returns the `end` iterator.
- `it`: This is an iterator where the result of the `find` operation is stored. If `i` is found in `intContainer`, `it` will point to it. If `i` is not found, `it` will be equal to `intContainer.end()`.

In summary, this line of code is searching for the value `i` in the container `intContainer` and storing the result in `it`.


		--> initialize "it" at the end

Initializing an iterator to the `end()` of a container is a common practice in C++ when you know you're going to assign a valid value to it before you use it. 

In your case:

```cpp
std::list<int>::const_iterator it = test_list.end();
```

Here, `it` is being initialized to `test_list.end()`. This is a safe initialization because `end()` is a valid value for an iterator. 

This is often done for a couple of reasons:

1. **To avoid uninitialized variables:** In C++, local variables are not automatically initialized when they are declared. Using an uninitialized variable can lead to undefined behavior. Initializing `it` to `test_list.end()` ensures that `it` is always in a valid state.

2. **As a sentinel value:** `end()` often serves as a sentinel value indicating that the iterator doesn't point to any valid element in the container. This can be useful in situations where you want to check if the iterator has been assigned a valid position or not.

Remember, even though `it` is initialized to `end()`, you should not dereference `it` until it has been assigned a valid position that points to an actual element in the list.

		--> beginning ok too ?
Yes, initializing an iterator to the `begin()` of a container is also a common practice in C++. 

```cpp
std::list<int>::const_iterator it = test_list.begin();
```

Whether it's better or not depends on the context and what you're planning to do with the iterator.

- If you're going to immediately start iterating over the elements from the beginning, initializing to `begin()` makes sense.
- If you're going to use the iterator in a search operation (like `std::find`), it doesn't matter whether you initialize to `begin()` or `end()`, because the search operation will assign a new value to the iterator.

Remember, if the list is empty, `begin()` will be equal to `end()`, and you should not dereference the iterator without checking this condition.

==> in our case end is better and safer

		--> why is it a const operator ?
In C++, a `const_iterator` is an iterator that points to constant content. This means that using a `const_iterator`, you can't change the value of the element it points to. However, you can change what element the iterator points to.

Here's an example:

```cpp
std::list<int> myList = {1, 2, 3, 4, 5};
std::list<int>::const_iterator it = myList.begin();
```

In this case, `it` is a `const_iterator`. You can't use `it` to modify the elements of `myList`:

```cpp
*it = 10;  // This is not allowed, it would give a compile error
```

But you can change what `it` points to:

```cpp
++it;  // This is allowed, it now points to the second element
```

So, when you see `const_iterator`, it means that the elements of the container are constant with respect to that iterator, not the iterator itself. The iterator can still be moved around.

	============== CPP08 - ex01

		--> VECTOR
A vector in C++ is a dynamic array that can grow and shrink in size at runtime. It is part of the Standard Template Library (STL). Here's a brief overview of how it works:

1. **Storage**: A vector stores its elements in contiguous memory locations, similar to an array. This allows it to provide fast direct access to its elements.

2. **Dynamic Size**: Unlike an array, a vector can change its size during runtime. When new elements are inserted and the current capacity is not enough, it allocates a larger block of memory, copies the existing elements to the new location, and deallocates the old memory.

3. **Insertion/Deletion**: Elements can be inserted or deleted from any part of the vector using iterators. However, inserting or deleting elements at the end is faster than at the beginning or the middle.

4. **Access**: Elements in a vector can be accessed directly using an index, just like in an array. The `at()`, `front()`, `back()`, and `operator[]` member functions are provided for this purpose.

5. **Other Operations**: Vectors also provide functions to get the size (number of elements) and capacity (total available space), check if it's empty, clear the contents, etc.

Here's a simple example of using a vector in C++:

```cpp
#include <vector>
#include <iostream>

int main() {
    std::vector<int> numbers; // Declare a vector of integers

    numbers.push_back(10); // Add an element at the end
    numbers.push_back(20);
    numbers.push_back(30);

    // Access elements
    std::cout << "First element: " << numbers[0] << std::endl;

    // Get size
    std::cout << "Size: " << numbers.size() << std::endl;

    return 0;
}
```
