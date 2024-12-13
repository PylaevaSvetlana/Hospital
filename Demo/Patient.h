#pragma once
#include "Doctor.h"
#include "Room.h"
#include <iostream>
#include <vector>
#include <sstream>

namespace Hospital
{
	/*
	* @brief ����� ������.
	*/
	class Doctor;
	/*
	* @brief ����� ������.
	*/
	class Room;
	class Patient;
	/*
	* @brief ����� �������.
	*/
	class Patient final : public std::enable_shared_from_this<Patient>
	{
	private:
		/*
	    * @brief ��� ��������.
	    */
		std::string firstName;
		/*
		* @brief ������� ��������.
		*/
		std::string secondName;
		/*
		* @brief �������� ��������.
		*/
		std::string patronymicName;
		/*
		* @brief ������� ��������.
		*/
		std::string disease;
		/*
		* @brief ������ ���������� �� ��������.
		*/
		std::vector<std::shared_ptr<Doctor>> doctors;
		/*
		* @brief ��������� �� ������.
		*/
		std::shared_ptr<Room> room;
		/*
		* @brief ����������� ������ �������.
		* @param firstName - ��� ��������.
		* @param secondName - ������� ��������.
		* @param patronymicName - �������� ��������.
		* @param disease - ������� ��������.
		*/
		Patient(const std::string& firstName, const std::string& secondName, const std::string& patronymicName, const std::string& disease);
	public:
		/*
		* @brief ����� �������� ������� �������.
		* @param firstName - ��� ��������.
		* @param secondName - ������� ��������.
		* @param patronymicName - �������� ��������.
		* @param disease - ������� ��������.
		*/
		static std::shared_ptr<Patient> CreatePatient(const std::string& firstName, const std::string& secondName, const std::string& patronymicName, const std::string& disease);
		/*
		* @brief ����� ������������ � ������ ToString().
		* @return ���������� ������ � ������� � �������� � ��� ������.
		*/
		std::string ToString() const;
		/*
		* @brief ����� ��������� ����� ��������.
		* @return ���������� ��� ��������.
		*/
		std::string GetFirstName() const noexcept;
		/*
		* @brief ����� ��������� ������� ��������.
		* @return ���������� ������� ��������.
		*/
		std::string GetSecondName() const noexcept;
		/*
		* @brief ����� ��������� �������� ��������.
		* @return ���������� �������� ��������.
		*/
		std::string GetPatronymicName() const noexcept;
		/*
		* @brief ����� ��������� ������� ��������.
		* @return ���������� ������� ��������.
		*/
		std::string GetDisease() const noexcept;
		/*
		* @brief ����� ��������� ������ ��������.
		* @return ���������� ������ ��������.
		*/
		std::shared_ptr<Room>& GetRoom() noexcept;
		/*
		* @brief ����� ��������� ������ ��������.
		* @return ���������� ������ ��������.
		*/
		const std::shared_ptr<Room>& GetRoom() const noexcept;
		/*
		* @brief ����� ���������� ����� �������� � �������.
		* @param room - ������ ������ ������.
		* @return ���������� true ���� ��� ������ �������.
		*/
		bool AddRoom(std::shared_ptr<Room>& room);
		/*
		* @brief ����� ���������� ����� �������� � ��������.
		* @param doctor - ������ ������ ������.
		* @return ���������� true ���� ��� ������ �������.
		*/
		bool AddDoctor(std::shared_ptr<Doctor>& doctor);
		/*
		* @brief ����� ��������� ������� ������� ��������.
		* @return ���������� ������ ������� ��������.
		*/
		std::vector<std::shared_ptr<Doctor>>& GetDoctors();
	};
}