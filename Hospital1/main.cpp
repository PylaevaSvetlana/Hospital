#include <iostream>
#include "../Demo/Doctor.h"
#include "../Demo/Patient.h"
#include "../Demo/Room.h"

int main()
{
	const std::string firstName{ "Svetlana" };
	const std::string familyName{ "Pylaeva" };
	const std::string patronymicName{ "Alekseevna" };
	const std::string specialization{ "Ortodont" };
	auto  test = std::make_shared<Hospital::Doctor>(familyName, firstName, patronymicName, specialization);
	std::cout << test->ToString();
	return 0;
}