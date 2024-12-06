#pragma once
#include "Patient.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

namespace Hospital
{
	class Patient;
	class Room;
	class Room final : public std::enable_shared_from_this<Room>
	{
	private:
		int number;
		std::vector<std::shared_ptr<Patient>> patients;
		Room(int number);
	public:
		static std::shared_ptr<Room> CreateRoom(int number);
		std::string ToString() const;
		int GetNumber() const noexcept;
		bool AddPatient(std::shared_ptr<Patient>& patient);
		std::vector<std::shared_ptr<Patient>>& GetPatients();
	};
}

