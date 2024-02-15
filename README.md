# cpp00_cpp04

When should I use reference / pointer ?
https://isocpp.org/wiki/faq/references#:~:text=Use%20references%20when%20you%20can,and%20pointers%20on%20the%20inside.

files manipulation in cpp
https://www.mygreatlearning.com/blog/file-handling-in-cpp/


CPP03 - ex03, Diamond

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