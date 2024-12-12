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
		std::vector<std::weak_ptr<Patient>> patients;
		Doctor(const std::string& firstName, const std::string& secondName, const std::string& patronymicName, const std::string& specialization);
	public:
		static std::shared_ptr<Doctor> CreateDoctor(const std::string& firstName, const std::string& secondName, const std::string& patronymicName, const std::string& specialization);
		bool AddPatient(std::shared_ptr<Patient>& patient);
		std::string ToString() const;
		std::string GetFirstName() const noexcept;
		std::string GetSecondName() const noexcept;
		std::string GetPatronymicName() const noexcept;
		std::string GetSpecialization() const noexcept;
		std::vector<std::weak_ptr<Patient>>& GetPatients() noexcept;
		const std::vector<std::weak_ptr<Patient>>& GetPatients() const noexcept;
	};
}