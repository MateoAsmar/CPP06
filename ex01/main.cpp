#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main(void)
{
	Data data;
	data.s = "Hello, world!";
	data.n = 42;

	uintptr_t raw = Serializer::serialize(&data);
	Data* ptr = Serializer::deserialize(raw);

	std::cout << "Original address: " << &data << std::endl;
	std::cout << "Serialized value: " << raw << std::endl;
	std::cout << "Deserialized address: " << ptr << std::endl;
	
	if (&data == ptr)
		std::cout << "Serialization and deserialization succesful." << std::endl;
	else
		std::cout << "Error: addresses do not match." << std::endl;
	return (0);
}