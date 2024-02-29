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