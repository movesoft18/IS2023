#include <iostream>
#include <stdexcept>
using namespace std;

template <class T>
class MyList // Объявление класса
{
	T* array = nullptr; // Указатель на динамически выделенный массив целых чисел
	int count = 0; // Текущее количество элементов в списке
	int size; // Общая ёмкость массива

	void Enlarge() // метод для увеличения ёмкости массива в 2 раза при заполнении
	{
		// Реализуем увеличение размера массива
		int newSize = size * 2; // Новый размер — удвоенный текущий размер
		int* newArray = new T[newSize]; // Выделяем новый массив большего размера
		for (int i = 0; i < count; ++i) // Копируем все существующие элементы из старого массива в новый
			newArray[i] = array[i];
		delete[] array; // Освобождаем старый массив
		array = newArray; // Обновляем указатель
		size = newSize; //Обновляем ёмкость
	}

public:
	// Конструктор по умолчанию
	MyList() : array(new T[100]), count(0), size(100) {}

	// Конструктор копирования
	MyList(const MyList& other)
		: count(other.count), size(other.size) // Копируем count и size
	{
		array = new T[size]; // Выделяем новый массив той же ёмкости, что и у исходного объекта
		for (int i = 0; i < count; ++i)// Копируем каждый элемент из исходного массива в новый
			array[i] = other.array[i];
	}

	// Оператор присваивания
	MyList& operator=(const MyList& other)
	{
		if (this == &other)// Проверка на самоприсваивание
			return *this;

		delete[] array;// Освобождаем текущую память объекта
		// Копируем поля
		count = other.count;
		size = other.size;
		array = new T[size];// Выделяем новый массив и копируем данные
		for (int i = 0; i < count; ++i)
			array[i] = other.array[i];

		return *this; // Возвращаем ссылку на текущий объект
	}

	// Деструктор
	virtual ~MyList()
	{
		delete[] array;
		array = nullptr; // Защита от двойного удаления
	}

	void Add(T value)// Метод добавления элемента в конец списка
	{
		if (count == size)// Если массив заполнен — увеличиваем его
			Enlarge(); // Вызов приватного метода
		array[count++] = value; // Записываем значение в первую свободную позицию и увеличиваем счётчик
	}

	T& operator[](int index)
	{
		if (index < 0 || index >= count)// Проверка границ
			throw out_of_range("Index out of range.");
		return array[index];// Возвращаем ссылку на элемент
	}

	int Length() const;
};

template <class T>
int MyList<T>::Length() const { return count; } // Метод для получения текущего количества элементов в списке



int main()
{
	MyList<int> list; // Создаём пустой список с помощью конструктора по умолчанию
	// Добавляем три элемента
	list.Add(1);
	list.Add(2);
	list.Add(3);
	list[1] = 100; // Изменяем второй элемент

	MyList<int> list1 = list; // Вызовет конструктор копирования
	list1[1] = 200; // Изменяем второй элемент в КОПИИ
	// Выводим оригинальный список
	cout << "Original list:\n";
	for (int i = 0; i < list.Length(); i++)
		cout << list[i] << "\n";
	cout << "----\n";
	// Выводим скопированный список
	cout << "Copied list:\n";
	for (int i = 0; i < list1.Length(); i++)
		cout << list1[i] << "\n";

	return 0;
}