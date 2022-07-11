#include <iostream>
#include "stdio.h"

/**
Класс контейнер, предоставляющий инструменты для работы со строками.
Учебная реализация основанная на базовом классе.
http://www.cplusplus.com/reference/string/string/
*/

class my_string
{
private:
    char* str; /* Указатель для хранения массива символов в стиле С. */
public:
    /* Предустановленное значение. Означает «до конца строки». */
    static const size_t npos = -1;
    //static const size_t npos = UINTMAX_MAX;

    /* Набор конструкторов класса. */
    my_string();
    my_string(const char* str);
    my_string(const my_string& obj); // Копирования
    my_string(my_string&& obj);      // Переноса

    /* Деструктор */
    ~my_string();

    /* Возвращает длинну строки. */
    inline size_t length() const;

    /* Возвращает символ из соответствующей позиции. */
    const char at(size_t pos) const;

    /* Добавляет символ в конец строки. */
    void push_back(char ch);

    /* Удаляет последний символ из строки. */
    void pop_back();

    /* Добавить строку в конец текущей строки. */
    void append(const char* str);
    void append(const my_string& obj);

    /* Вставляет строку непосредственно перед символом, обозначенным pos. */
    void insert(size_t pos, const char* str);
    void insert(size_t pos, const my_string& obj);

    /* Очищает строку. */
    void erase();

    /* Заменяет часть строки, которая начинается с символа pos и заменяет len символов,
       новым содержимым. При значении len = npos копируются все символы до конца строки. */
    void replace(size_t pos, size_t len, const char* str);
    void replace(size_t pos, size_t len, const my_string& obj);

    /* Обменивает содержание двух строк. */
    void swap(my_string&& obj);

    /* Копирует строку. */
    void copy(const char* str);
    void copy(const my_string& obj);

    /* Ищет в строке первое вхождение подстроки, указанной ее аргументами.
       Когда задано значение pos, поиск начинается с указанной позиции.
       Положение первого символа найденной последовательности.
       Если совпадений не найдено, функция возвращает my_string::npos.  */
    size_t find(const char* str, size_t pos = 0) const;
    size_t find(const my_string& obj, size_t pos = 0) const;

    /* Сравнивает две строки. */
    int compare(const char* str) const;
    int compare(const my_string& obj) const;

    /* Возвращает строку как массив символов в стиле С. */
    const char* c_str() const;

    /* Очищает строку. */
    void clear();
};

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

inline size_t my_string::length() const
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
    
    size_t size = strlen(this->str);
    char* tmp = new char[size+2];
    strcpy_s(tmp, size + 2, this->str);
    tmp[size] = ch;
    tmp[size + 1] = '\0';
    delete[] this->str;
    this->str = tmp;
    tmp = nullptr;

}

void my_string::pop_back()
{
    size_t size = strlen(this->str);
    this->str[size - 1] = '\0';
}

void my_string::append(const char* str)
{
    size_t i1 = strlen(this->str);
    size_t i2 = strlen(str);
    size_t origin = i1;
    size_t i{ 0 };
    char* tmp = new char[i1+i2+1];
    strcpy_s(tmp, i1+1, this->str);
    for (origin; origin < i1 + i2; origin++)
    {
        tmp[origin] = str[i];
        i++;
    }
    tmp[i1 + i2] = '\0';
    delete[] this->str;
    this->str = tmp;
    tmp = nullptr;
    std::cout << this->str << std::endl;
}

void my_string::append(const my_string& obj)
{
    size_t i1 = strlen(this->str);
    size_t i2 = strlen(obj.str);
    size_t origin = i1;
    size_t i{ 0 };
    char* tmp = new char[i1 + i2 + 1];
    strcpy_s(tmp, i1 + 1, this->str);
    for (origin; origin < i1 + i2; origin++)
    {
        tmp[origin] = obj.str[i];
        i++;
    }
    tmp[i1 + i2] = '\0';
    delete[] this->str;
    this->str = tmp;
    tmp = nullptr;
}

void my_string::insert(size_t pos, const char* str)
{
    size_t i1 = strlen(this->str);
    size_t i2 = strlen(str);
    size_t origin{ 0 };
    size_t i{ 0 };
    size_t z{ 0 };
    char* tmp = new char[i1 + i2 + 1];
    for (i; i < i1; i++)
    {
        if (i == (pos - 1))
        {
            for (z; z < i2; z++)
            {
                tmp[origin] = str[z];
                origin++;
            }
        }
            tmp[origin] = this->str[i];
            origin++;
    }
    tmp[i1 + i2] = '\0';
    delete[] this->str;
    this->str = tmp;
    tmp = nullptr;
    std::cout << this->str;
}

void my_string::insert(size_t pos, const my_string& obj)
{
    size_t i1 = strlen(this->str);
    size_t i2 = strlen(obj.str);
    size_t origin{ 0 };
    size_t i{ 0 };
    size_t z{ 0 };
    char* tmp = new char[i1 + i2 + 1];
    for (i; i < i1; i++)
    {
        if (i == (pos - 1))
        {
            for (z; z < i2; z++)
            {
                tmp[origin] = obj.str[z];
                origin++;
            }
        }
        tmp[origin] = this->str[i];
        origin++;
    }
    tmp[i1 + i2] = '\0';
    delete[] this->str;
    this->str = tmp;
    tmp = nullptr;
    std::cout << this->str << std::endl;
}

void my_string::erase()
{
    this->str[0] = '\0';
    std::cout << this->str << std::endl;
}

void my_string::replace(size_t pos, size_t len, const char* str)
{
    size_t size = strlen(this->str);
    char* tmp = new char[size + 1];
    size_t i{ 0 };
    size_t begin{ 0 };
    for (i; i < size; i++)
    {
        if (i == (pos - 1))
        {
            for (begin; begin < len;begin++)
            {
                tmp[i] = str[begin];
                i++;
            }

        }
        tmp[i] = this->str[i];
    }
    tmp[size] = '\0';
    delete[] this->str;
    this->str = tmp;
    tmp = nullptr;
    std::cout << this->str << std::endl;
}

void my_string::replace(size_t pos, size_t len, const my_string& obj)
{
    size_t size = strlen(this->str);
    char* tmp = new char[size + 1];
    size_t i{ 0 };
    size_t begin{ 0 };
    for (i; i < size; i++)
    {
        if (i == (pos - 1))
        {
            for (begin; begin < len;begin++)
            {
                tmp[i] = obj.str[begin];
                i++;
            }

        }
        tmp[i] = this->str[i];
    }
    tmp[size] = '\0';
    delete[] this->str;
    this->str = tmp;
    tmp = nullptr;
    std::cout << this->str << std::endl;
}

void my_string::swap(my_string&& obj)
{
    char* tmp = this->str;
    this->str = obj.str;
    obj.str = tmp;
    tmp = nullptr;
}

void my_string::copy(const char* str)
{
    size_t size = strlen(str);
    char* tmp = new char[size + 1];
    for (auto i = 0; i < size; i++)
    {
        tmp[i] = str[i];
    }
    delete[] this->str;
    this->str = tmp;
    tmp = nullptr;
}

void my_string::copy(const my_string& obj)
{
    size_t size = strlen(obj.str);
    char* tmp = new char[size + 1];
    for (auto i = 0; i < size; i++)
    {
        tmp[i] = obj.str[i];
    }
    delete[] this->str;
    this->str = tmp;
    tmp = nullptr;
}

size_t my_string::find(const char* str, size_t pos = 0) const
{
    size_t size = strlen(this->str);
    for (auto i = 0; i < size; i++)
    {
        if (this->str[i] == *str)
        {
            return i;
        }
    }
    return npos;
}

size_t my_string::find(const my_string& obj, size_t pos = 0) const
{
    size_t size = strlen(this->str);
    for (auto i = 0; i < size; i++)
    {
        if (this->str[i] == *obj.str)
        {
            return i;
        }
    }
    return npos;
}

int my_string::compare(const char* str) const
{
    size_t size1 = strlen(this->str);
    size_t size2 = strlen(str);
    if (size1 = size2)
    {
        for (auto i = 0; i < size1; i++)
        {
            if (this->str[i] != str[i])
                return 0;
        }
        return 1;
    }
    else
        return 0;
}


int my_string::compare(const my_string& obj) const
{
    size_t size1 = strlen(this->str);
    size_t size2 = strlen(obj.str);
    if (size1 = size2)
    {
        for (auto i = 0; i < size1; i++)
        {
            if (this->str[i] != obj.str[i])
                return 0;
        }
        return 1;
    }
    else
        return 0;
}

const char* my_string::c_str() const
{
    return this->str;
}

void my_string::clear()
{
    this->str[0] = '\0';
    std::cout << this->str << std::endl;
}

int main()
{
    char ex[] = "Hello World";
    my_string example(ex);

    example.push_back('!');
    example.pop_back();

    example.append(" Yes, hello!");
    example.insert(3, "may");

    example.erase();

    char ex2[] = "AAAAAAAAAAAAAAA";
    my_string example2(ex2);

    example2.replace(4, 2, "HHHHHHHH");

    /*char to_swap1[] = "one";
    char to_swap2[] = "two";
    my_string to_swap_one(to_swap1);
    my_string to_swap_two(to_swap2);
    to_swap_one.swap(to_swap_two);*/


}
