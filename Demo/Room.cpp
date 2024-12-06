#include "Room.h"
using namespace Hospital;
Hospital::Room::Room(int number) :number{ number } {}

std::shared_ptr<Room> Hospital::Room::CreateRoom(int number)
{
	return std::make_shared<Room>(Room{ number });
}

std::string Hospital::Room::ToString() const
{
	std::stringstream buffer{};
	buffer << GetNumber();
	return buffer.str();
}

int Hospital::Room::GetNumber() const noexcept
{
	return number;
}

bool Hospital::Room::AddPatient(std::shared_ptr<Patient>& patient)
{
	this->patients.push_back(patient);
	patient->GetRoom() = shared_from_this();
	return true;
}

std::vector<std::shared_ptr<Patient>>& Hospital::Room::GetPatients()
{
	return patients;
}




