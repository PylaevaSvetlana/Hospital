#pragma once
#include "Doctor.h"
#include "Room.h"
#include <iostream>
#include <vector>
#include <sstream>

namespace Hospital
{
	/*
	* @brief класс Доктор.
	*/
	class Doctor;
	/*
	* @brief класс Палата.
	*/
	class Room;
	class Patient;
	/*
	* @brief класс Пациент.
	*/
	class Patient final : public std::enable_shared_from_this<Patient>
	{
	private:
		/*
	    * @brief имя пациента.
	    */
		std::string firstName;
		/*
		* @brief фамилия пациента.
		*/
		std::string secondName;
		/*
		* @brief отчество пациента.
		*/
		std::string patronymicName;
		/*
		* @brief болезнь пациента.
		*/
		std::string disease;
		/*
		* @brief вектор указателей на докторов.
		*/
		std::vector<std::shared_ptr<Doctor>> doctors;
		/*
		* @brief указатель на палату.
		*/
		std::shared_ptr<Room> room;
		/*
		* @brief конструктор класса Пациент.
		* @param firstName - имя пациента.
		* @param secondName - фамилия пациента.
		* @param patronymicName - отчество пациента.
		* @param disease - болезнь пациента.
		*/
		Patient(const std::string& firstName, const std::string& secondName, const std::string& patronymicName, const std::string& disease);
	public:
		/*
		* @brief метод создания объекта пациент.
		* @param firstName - имя пациента.
		* @param secondName - фамилия пациента.
		* @param patronymicName - отчество пациента.
		* @param disease - болезнь пациента.
		*/
		static std::shared_ptr<Patient> CreatePatient(const std::string& firstName, const std::string& secondName, const std::string& patronymicName, const std::string& disease);
		/*
		* @brief метод сериализации в строку ToString().
		* @return возвращает строку с данными о пациенте и его палате.
		*/
		std::string ToString() const;
		/*
		* @brief метод получения имени пациента.
		* @return возвращает имя пациента.
		*/
		std::string GetFirstName() const noexcept;
		/*
		* @brief метод получения фамилии пациента.
		* @return возвращает фамилию пациента.
		*/
		std::string GetSecondName() const noexcept;
		/*
		* @brief метод получения отчества пациента.
		* @return возвращает отчество пациента.
		*/
		std::string GetPatronymicName() const noexcept;
		/*
		* @brief метод получения болезни пациента.
		* @return возвращает болезнь пациента.
		*/
		std::string GetDisease() const noexcept;
		/*
		* @brief метод получения палаты пациента.
		* @return возвращает палату пациента.
		*/
		std::shared_ptr<Room>& GetRoom() noexcept;
		/*
		* @brief метод получения палаты пациента.
		* @return возвращает палату пациента.
		*/
		const std::shared_ptr<Room>& GetRoom() const noexcept;
		/*
		* @brief метод добавления связи пациента с палатой.
		* @param room - объект класса палата.
		* @return возваращет true если все прошло успешно.
		*/
		bool AddRoom(std::shared_ptr<Room>& room);
		/*
		* @brief метод добавления связи пациента с доктором.
		* @param doctor - объект класса доктор.
		* @return возваращет true если все прошло успешно.
		*/
		bool AddDoctor(std::shared_ptr<Doctor>& doctor);
		/*
		* @brief метод получения вектора докторв пациента.
		* @return возвращает вектор докторв пациента.
		*/
		std::vector<std::shared_ptr<Doctor>>& GetDoctors();
	};
}