#pragma once
class CStudent
{
public:
	CStudent(std::string name, std::string surname, std::string patronymic, unsigned age);

	std::string GetName() const;
	std::string GetSurname() const;
	std::string GetPatronymic() const;
	unsigned GetAge() const;

	void Rename(std::string name, std::string surname, std::string patronymic);
	void SetAge(unsigned age);
private:
	std::string m_name;
	std::string m_surname;
	std::string m_patronymic;
	unsigned m_age;
};

const unsigned MIN_AGE = 14;
const unsigned MAX_AGE = 60;
bool IsCorrectString(const std::string &s);
bool IsCorrectAge(unsigned age);