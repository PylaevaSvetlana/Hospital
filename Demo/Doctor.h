#pragma once
#include "Patient.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

namespace Hospital
{
	class Doctor;
	class Patient;
	class Doctor final : public std::enable_shared_from_this<Doctor>
	{
	private:
		std::string firstName;
		std::string secondName;
		std::string patronymicName;
		std::string specialization;
		std::vector<std::shared_ptr<Patient>> patients;
	public:
		Doctor(const std::string& firstName, const std::string& secondName, const std::string& patronymicName, const std::string& specialization);
		static std::shared_ptr<Doctor> CreateDoctor(const std::string& firstName, const std::string& secondName, const std::string& patronymicName, const std::string& specialization);
		bool AddPatient(std::shared_ptr<Patient>& patient);
		std::string ToString();
		std::string GetFirstName();
		std::string GetSecondName();
		std::string GetPatronymicName();
		std::string GetSpecialization();
		std::vector<std::shared_ptr<Patient>>& GetPatients();
	};
}

