#pragma once

#include <stdexcept>


template <class T>
class MyList // Объявление класса
{
	T* array = nullptr; // Указатель на динамически выделенный массив целых чисел
	int count = 0; // Текущее количество элементов в списке
	int size; // Общая ёмкость массива

	void Enlarge(); // метод для увеличения ёмкости массива в 2 раза при заполнении

public:
	MyList() : array(new T[100]), count(0), size(100) {}

	MyList(const MyList& other);

	// Оператор присваивания
	MyList& operator=(const MyList& other);
	// Деструктор
	virtual ~MyList();

	void Add(T value);

	T& operator[](int index);
	int Length() const;
};

#include "MyListLib1.inl"