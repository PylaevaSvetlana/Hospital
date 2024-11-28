#include "doctor.h"
#include <sstream>
using namespace Hospital;
Hospital::Doctor::Doctor(const std::string& firstName, const std::string& secondName, const std::string& patronymicName, const std::string& specialization) :firstName{ firstName }, secondName{ secondName }, patronymicName{ patronymicName }, specialization{ specialization } {}

std::shared_ptr<Doctor> Hospital::Doctor::CreateDoctor(const std::string& firstName, const std::string& secondName, const std::string& patronymicName, const std::string& specialization)
{
	return std::make_shared<Doctor>(Doctor{ firstName, secondName, patronymicName, specialization });
}


bool Hospital::Doctor::AddPatient(std::shared_ptr<Patient>& patient)
{
	this->patients.push_back(patient);
	patient->GetPatients().push_back(shared_from_this());
	return true;
}

std::string Hospital::Doctor::ToString() const
{
	std::stringstream buffer{};
	buffer << GetFirstName() << " " << GetSecondName() << " " << GetPatronymicName() << " " << GetSpecialization();
	return buffer.str();
}

std::string Hospital::Doctor::GetFirstName()
{
	return firstName;
}

std::string Hospital::Doctor::GetSecondName()
{
	return secondName;
}

std::string Hospital::Doctor::GetPatronymicName()
{
	return patronymicName;
}

std::string Hospital::Doctor::GetSpecialization()
{
	return specialization;
}


