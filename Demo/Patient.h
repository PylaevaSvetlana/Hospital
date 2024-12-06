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
		std::shared_ptr<Room> room=nullptr;
		Patient(const std::string& firstName, const std::string& secondName, const std::string& patronymicName, const std::string& disease);
	public:
		static std::shared_ptr<Patient> CreatePatient(const std::string& firstName, const std::string& secondName, const std::string& patronymicName, const std::string& disease);
		std::string ToString() const;
		std::string GetFirstName() const noexcept;
		std::string GetSecondName() const noexcept;
		std::string GetPatronymicName() const noexcept;
		std::string GetDisease() const noexcept;
		std::shared_ptr<Room>& GetRoom() noexcept;
		const std::shared_ptr<Room>& GetRoom() const noexcept;
		bool AddRoom(std::shared_ptr<Room>& room);
		bool AddDoctor(std::shared_ptr<Doctor>& doctor);
		std::vector<std::shared_ptr<Doctor>>& GetDoctors();
	};
}





