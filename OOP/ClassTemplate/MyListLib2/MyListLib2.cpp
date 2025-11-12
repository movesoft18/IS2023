#include "MyListLib2.h"

template <class T>
void MyList<T>::Enlarge() // метод для увеличения ёмкости массива в 2 раза при заполнении
{
	// Реализуем увеличение размера массива
	int newSize = size * 2; // Новый размер — удвоенный текущий размер
	T* newArray = new T[newSize]; // Выделяем новый массив большего размера
	for (int i = 0; i < count; ++i) // Копируем все существующие элементы из старого массива в новый
		newArray[i] = array[i];
	delete[] array; // Освобождаем старый массив
	array = newArray; // Обновляем указатель
	size = newSize; //Обновляем ёмкость
}

template <class T>
MyList<T>::MyList(const MyList<T>& other)
	: count(other.count), size(other.size) // Копируем count и size
{
	array = new T[size]; // Выделяем новый массив той же ёмкости, что и у исходного объекта
	for (int i = 0; i < count; ++i)// Копируем каждый элемент из исходного массива в новый
		array[i] = other.array[i];
}

// Оператор присваивания
template <class T>
MyList<T>& MyList<T>::operator=(const MyList<T>& other)
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
template <class T>
MyList<T>::~MyList()
{
	delete[] array;
	array = nullptr; // Защита от двойного удаления
}

template <class T>
void MyList<T>::Add(T value)// Метод добавления элемента в конец списка
{
	if (count == size)// Если массив заполнен — увеличиваем его
		Enlarge(); // Вызов приватного метода
	array[count++] = value; // Записываем значение в первую свободную позицию и увеличиваем счётчик
}

template <class T>
T& MyList<T>::operator[](int index)
{
	if (index < 0 || index >= count)// Проверка границ
		throw std::out_of_range("Index out of range.");
	return array[index];// Возвращаем ссылку на элемент
}

template <class T>
int MyList<T>::Length() const
{
	return count;
}
