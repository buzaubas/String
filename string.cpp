#include "string.h"

my_string::my_string()
{
	this->str = nullptr;
}

my_string::my_string(const char* str)
{
	size_t size = strlen(str);
	this->str = new char[size + 1];
	strcpy_s(this->str, size + 1, str);
}

my_string::my_string(const my_string& obj)
{
	size_t size = strlen(obj.str);
	this->str = new char[size + 1];
	strcpy_s(this->str, size + 1, obj.str);
}

my_string::my_string(my_string&& obj)
{
	this->str = obj.str;
	obj.str = nullptr; //перенос памяти (экономия времени процессора)
}

my_string::~my_string()
{
	if (this->str)
		delete[] this->str;
}

size_t my_string::length() const
{
	return strlen(this->str);
}

const char my_string::at(size_t pos) const
{
	if (this->str)
	{
		return this->str[pos];
	}
	return npos;
}

void my_string::push_back(char ch)
{
	/*this->str += ch;
	size_t size = strlen(this->str);
	char* old = nullptr;
	strcpy_s(old, size, this->str);
	this->str = new char[size + 2];
	this->str = old;
	this->str[size + 1] = ch;
	this->str[size + 2] = '\0';
	std::cout << str << std::endl;*/

}

size_t my_string::find(const char* str, size_t pos) const
{
	if (this->str)
	{
		const char* ptr = strstr(this->str, str + pos);
		if (ptr)
			return ptr - str;
	}
	return npos;
}

void my_string::replace(size_t pos, size_t len, const char* str)
{
	if (this->str)
	{
		if (len == npos)
			strcpy_s(this->str, strlen(this->str) + 1, str + pos);
		else
			strncpy_s(this->str, strlen(this->str) + 1, str + pos, len);
	}
}

void my_string::pop_back()
{
	size_t size = strlen(this->str);
	this->str[size - 2] = '\0';
}

void my_string::append(const char* str)
{
	size_t i1 = strlen(this->str);
	size_t i2 = strlen(str);
	size_t origin = i1;
	size_t i{ 0 };
	for (origin; origin < i1 + i2; origin++)
	{
		this->str[origin] = str[i];
		i++;
	}
	std::cout << this->str << std::endl;
}
