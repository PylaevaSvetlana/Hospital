#include <iostream>
#include "../Demo/Doctor.h"
#include "../Demo/Patient.h"
#include "../Demo/Room.h"

using namespace Hospital;

int main()
{
	
	auto  doctor = Hospital::Doctor::CreateDoctor("Svetlana", "Pylaeva", "Alekseevna", "Ortodont");
    std::cout << doctor->ToString()<<"\n";

	auto  patient = Hospital::Patient::CreatePatient("Anna", "Ivanova", "Alexandrovna", "braces");
	std::cout << patient->ToString()<< "\n";

	auto  room = Hospital::Room::CreateRoom(105);
	std::cout << room->GetNumber() << "\n";


	doctor->AddPatient(patient);
	std::cout<<doctor->ToString() << "\n";

	room->AddPatient(patient);
	std::cout << room->ToString();

	return 0;
}