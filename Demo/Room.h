#pragma once
#include "Patient.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

namespace Hospital
{
	/*
	* @brief ����� �������.
	*/
	class Patient;
	class Room;
	/*
	* @brief ����� ������.
	*/
	class Room final : public std::enable_shared_from_this<Room>
	{
	private:
		/*
	    * @brief ����� ������.
	    */
		int number;
		/*
		* @brief ������ ���������� �� ���������.
		*/
		std::vector< Patient* > patients;
		/*
		* @brief ����������� ������ ������.
		* @param number - ����� ������.
		*/
		Room(int number);
	public:
		/*
		* @brief ����� �������� ������� ������.
		* @param number - ����� ������.
		*/
		static std::shared_ptr<Room> CreateRoom(int number);
		/*
		* @brief ����� ������������ � ������ ToString().
		* @return ���������� ������ � ������� � ������.
		*/
		std::string ToString() const;
		/*
		* @brief ����� ��������� ������ ������.
		* @return ���������� ����� ������.
		*/
		int GetNumber() const noexcept;
		/*
		* @brief ����� ���������� ����� ������ � ���������.
		* @param patient - ������ ������ �������.
		* @return ���������� true ���� ��� ������ �������.
		*/
		bool AddPatient(std::shared_ptr<Patient>& patient);
		/*
		* @brief ����� ��������� ��������� ������.
		* @return ���������� ������ ��������� ������.
		*/
		std::vector<Patient*>& GetPatients() noexcept;
		/*
		* @brief ����� ��������� ��������� ������.
		* @return ���������� ������ ��������� ������.
		*/
		const std::vector<Patient*>& GetPatients() const noexcept;
	};
}