#pragma once
#include "Doctor.h"
#include "Room.h"
#include <iostream>
#include <vector>
#include <sstream>

namespace Hospital
{
	class Doctor;
	class Room;
	class Patient;
	class Patient final : public std::enable_shared_from_this<Patient>
	{
	private:
		std::string firstName;
		std::string secondName;
		std::string patronymicName;
		std::string disease;
		std::vector<std::shared_ptr<Doctor>> doctors;
		std::shared_ptr<Room> room;
	public:
		Patient(const std::string& firstName, const std::string& secondName, const std::string& patronymicName, const std::string& disease);
		static std::shared_ptr<Patient> CreatePatient(const std::string& firstName, const std::string& secondName, const std::string& patronymicName, const std::string& disease);
		std::string ToString();
		std::string GetFirstName();
		std::string GetSecondName();
		std::string GetPatronymicName();
		std::string GetDisease();
		std::shared_ptr<Room>& GetRoom();
		bool AddDoctor(std::shared_ptr<Doctor>& doctor);
		std::vector<std::shared_ptr<Doctor>>& GetDoctors();
	};
}





