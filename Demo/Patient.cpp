#include "Patient.h"
using namespace Hospital;
Hospital::Patient::Patient(const std::string& firstName, const std::string& secondName, const std::string& patronymicName, const std::string& disease) :firstName{ firstName }, secondName{ secondName }, patronymicName{ patronymicName }, disease{ disease } {}

std::shared_ptr<Patient> Hospital::Patient::CreatePatient(const std::string& firstName, const std::string& secondName, const std::string& patronymicName, const std::string& disease)
{
	return std::make_shared<Patient>(Patient{ firstName, secondName, patronymicName, disease });
}

std::string Hospital::Patient::ToString() const 
{
	std::stringstream buffer{};
	buffer << GetFirstName() << " " << GetSecondName() << " " << GetPatronymicName() << " " << GetDisease();
	if (GetRoom())
	{
		buffer << " " << GetRoom()->GetNumber();
	}
	return buffer.str();
}

std::string Hospital::Patient::GetFirstName() const noexcept
{
	return firstName;
}

std::string Hospital::Patient::GetSecondName() const noexcept
{
	return secondName;
}

std::string Hospital::Patient::GetPatronymicName() const noexcept
{
	return patronymicName;
}

std::string Hospital::Patient::GetDisease() const noexcept
{
	return disease;
}

std::shared_ptr<Room>& Hospital::Patient::GetRoom() noexcept
{
	return room;
}

const std::shared_ptr<Room>& Hospital::Patient::GetRoom() const noexcept
{
	return room;
}

bool Hospital::Patient::AddRoom(std::shared_ptr<Room>& room)
{
	this->room = room;
	room->GetPatients().push_back(shared_from_this().get());
	return true;
}

bool Hospital::Patient::AddDoctor(std::shared_ptr<Doctor>& doctor)
{
	this->doctors.push_back(doctor);
	doctor->GetPatients().push_back(shared_from_this());
	return true;
}

std::vector<std::shared_ptr<Doctor>>& Hospital::Patient::GetDoctors()
{
	return doctors;
}