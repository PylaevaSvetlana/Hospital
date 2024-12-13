#pragma once
#include "Patient.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

namespace Hospital
{
	class Doctor;
	/*
	* @brief ����� �������.
	*/
	class Patient;
	/*
	* @brief ����� ������.
	*/
	class Doctor final : public std::enable_shared_from_this<Doctor>
	{
	private:
		/*
	    * @brief ��� �������.
	    */
		std::string firstName;
		/*
		* @brief ������� �������.
		*/
		std::string secondName;
		/*
		* @brief �������� �������.
		*/
		std::string patronymicName;
		/*
		* @brief ������������� �������.
		*/
		std::string specialization;
		/*
		* @brief ������ ���������� �� ���������.
		*/
		std::vector<std::weak_ptr<Patient>> patients;
		/*
		* @brief ����������� ������ ������.
		* @param firstName - ��� �������.
		* @param secondName - ������� �������.
		* @param patronymicName - �������� �������.
		* @param specialization - ������������� �������.
		*/
		Doctor(const std::string& firstName, const std::string& secondName, const std::string& patronymicName, const std::string& specialization);
	public:
		/*
		* @brief ����� �������� ������� ������.
		* @param firstName - ��� �������.
		* @param secondName - ������� �������.
		* @param patronymicName - �������� �������.
		* @param specialization - ������������� �������.
		*/
		static std::shared_ptr<Doctor> CreateDoctor(const std::string& firstName, const std::string& secondName, const std::string& patronymicName, const std::string& specialization);
		/*
		* @brief ����� ���������� ����� ������� � ���������.
		* @param patient - ������ ������ �������.
		* @return ���������� true ���� ��� ������ �������.
		*/
		bool AddPatient(std::shared_ptr<Patient>& patient);
		/*
		* @brief ����� ������������ � ������ ToString().
		* @return ���������� ������ � ������� � ������� � ��� ���������.
		*/
		std::string ToString() const;
		/*
		* @brief ����� ��������� ����� �������.
		* @return ���������� ��� �������.
		*/
		std::string GetFirstName() const noexcept;
		/*
		* @brief ����� ��������� ������� �������.
		* @return ���������� ������� �������.
		*/
		std::string GetSecondName() const noexcept;
		/*
		* @brief ����� ��������� �������� �������.
		* @return ���������� �������� �������.
		*/
		std::string GetPatronymicName() const noexcept;
		/*
		* @brief ����� ��������� ������������� �������.
		* @return ���������� ������������� �������.
		*/
		std::string GetSpecialization() const noexcept;
		/*
		* @brief ����� ��������� ������� ��������� �������.
		* @return ���������� ������ ��������� �������.
		*/
		std::vector<std::weak_ptr<Patient>>& GetPatients() noexcept;
		/*
		* @brief ����� ��������� ������� ��������� �������.
		* @return ���������� ������ ��������� �������.
		*/
		const std::vector<std::weak_ptr<Patient>>& GetPatients() const noexcept;
	};
}