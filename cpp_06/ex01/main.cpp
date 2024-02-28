#include "Serializer.hpp"

int main()
{
	Data ptr2;
	ptr2.time = "Dinner time!";
	ptr2.food = "A mug of potage!";
	ptr2.next = NULL;

	Data ptr;
	ptr.time = "Lunch time!";
	ptr.food = "A plate of spaghetti!";
	ptr.next = &ptr2;

	std::cout << "\n===== POST INITIALIZATION PRINT =====" <<
				"\n\taddress: " << &ptr <<
				"\n\ttime: " << ptr.time <<
				"\n\tfood: " << ptr.food <<
				"\n\taddress next: " << ptr.next << std::endl;
	std::cout << "\taddress ptr2: " << &ptr2 <<
				"\n\ttime: " << ptr2.time <<
				"\n\tfood: " << ptr2.food <<
				"\n\taddress next: " << ptr2.next << "\n" << std::endl;

	Serializer a;
	Serializer b(a);

	Data *reserialized_struct = b.deserialize(b.serialize(&ptr));

	std::cout << "\n===== POST RESERIALIZATION PRINT =====" <<
				"\n\taddress: " << reserialized_struct <<
				"\n\ttime: " << reserialized_struct->time <<
				"\n\tfood: " << reserialized_struct->food <<
				"\n\taddress next: " << reserialized_struct->next << std::endl;
	std::cout << "\taddress ptr2: " << &ptr2 <<
				"\n\ttime: " << ptr2.time <<
				"\n\tfood: " << ptr2.food <<
				"\n\taddress next: " << ptr2.next << "\n" << std::endl;

	return (0);
}
