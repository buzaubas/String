#include <iostream>

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
    static const size_t npos = -1; // выделяется место которое используется всеми объектами,а не создается в каждом + size_t npos = -1 ставит максимальное число для этого типа данных
    //static const size_t npos = UINTMAX_MAX; // такая же как и верхняя строчка

    /* Набор конструкторов класса. */
    my_string();
    my_string(const char* str);
    my_string(const my_string& obj); // Копирования
    my_string(my_string&& obj);      // Переноса

    /* Деструктор */
    ~my_string();

    /* Возвращает длинну строки. */
    size_t length() const; //если ты можешь вместо перехода к функций вставь тело функций (для небольших вычислений)

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
    size_t find(const char* str, size_t pos = 0) const; //не меняет внутреннее состояние строки
    size_t find(const my_string& obj, size_t pos = 0) const;

    /* Сравнивает две строки. */
    int compare(const char* str) const;
    int compare(const my_string& obj) const;

    /* Возвращает строку как массив символов в стиле С. */
    const char* c_str() const;

    /* Очищает строку. */
    void clear();
};
