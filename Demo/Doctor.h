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
	* @brief класс Кациент.
	*/
	class Patient;
	/*
	* @brief класс Доктор.
	*/
	class Doctor final : public std::enable_shared_from_this<Doctor>
	{
	private:
		/*
	    * @brief имя доктора.
	    */
		std::string firstName;
		/*
		* @brief фамилия доктора.
		*/
		std::string secondName;
		/*
		* @brief отчество доктора.
		*/
		std::string patronymicName;
		/*
		* @brief специализация доктора.
		*/
		std::string specialization;
		/*
		* @brief вектор указателей на пациентов.
		*/
		std::vector<std::weak_ptr<Patient>> patients;
		/*
		* @brief конструктор класса Доктор.
		* @param firstName - имя доктора.
		* @param secondName - фамилия доктора.
		* @param patronymicName - отчество доктора.
		* @param specialization - специализация доктора.
		*/
		Doctor(const std::string& firstName, const std::string& secondName, const std::string& patronymicName, const std::string& specialization);
	public:
		/*
		* @brief метод создания объекта доктор.
		* @param firstName - имя доктора.
		* @param secondName - фамилия доктора.
		* @param patronymicName - отчество доктора.
		* @param specialization - специализация доктора.
		*/
		static std::shared_ptr<Doctor> CreateDoctor(const std::string& firstName, const std::string& secondName, const std::string& patronymicName, const std::string& specialization);
		/*
		* @brief метод добавления связи доктора с пациентом.
		* @param patient - объект класса пациент.
		* @return возваращет true если все прошло успешно.
		*/
		bool AddPatient(std::shared_ptr<Patient>& patient);
		/*
		* @brief метод сериализации в строку ToString().
		* @return возвращает строку с данными о докторе и его пациентах.
		*/
		std::string ToString() const;
		/*
		* @brief метод получения имени доктора.
		* @return возвращает имя доктора.
		*/
		std::string GetFirstName() const noexcept;
		/*
		* @brief метод получения фамилии доктора.
		* @return возвращает фамилию доктора.
		*/
		std::string GetSecondName() const noexcept;
		/*
		* @brief метод получения отчества доктора.
		* @return возвращает отчество доктора.
		*/
		std::string GetPatronymicName() const noexcept;
		/*
		* @brief метод получения специализации доктора.
		* @return возвращает специализацию доктора.
		*/
		std::string GetSpecialization() const noexcept;
		/*
		* @brief метод получения вектора пациентов доктора.
		* @return возвращает вектор пациентов доктора.
		*/
		std::vector<std::weak_ptr<Patient>>& GetPatients() noexcept;
		/*
		* @brief метод получения вектора пациентов доктора.
		* @return возвращает вектор пациентов доктора.
		*/
		const std::vector<std::weak_ptr<Patient>>& GetPatients() const noexcept;
	};
}