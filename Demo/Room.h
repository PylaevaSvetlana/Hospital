#pragma once
#include "Patient.h"
#include <iostream>
#include <vector>

namespace Hospital
{
	class Patient;
	class Room;
	class Room final : public std::enable_shared_from_this<Room>
	{
	private:
		int number;
		std::vector<std::shared_ptr<Patient>> patients;
	public:
		Room(int number);
		static std::shared_ptr<Room> CreateRoom(int number);
		int GetNumber();
		bool AddPatient(std::shared_ptr<Patient>& patient);
		std::vector<std::shared_ptr<Patient>>& GetPatients();
	};
}

