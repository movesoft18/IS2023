#include <iostream>
using namespace std;

int main()
{
	const int arraySize = 10;
	int array[arraySize];
	setlocale(LC_ALL, "");
	for (int i = 0; i < arraySize; i++)
	{
		cout << "Введите " << i + 1 << "-й элемент массива: ";
		cin >> array[i];
	}

	for (int i = 0; i < arraySize; i++)
		cout << array[i] << ' ';
	cout << endl;

	int valueForSearch;
	cout << "Введите число для поиска: ";
	cin >> valueForSearch;
	bool found = false;
	for (int i = 0; i < arraySize; i++)
	{
		if (array[i] == valueForSearch)
		{
			cout << "Элемент со значением " << valueForSearch
				<< " найден в позиции " << i << endl;
			found = true;
			break;
		}	
		/*if (i == arraySize - 1)
			cout << "Элемент со значением " << valueForSearch
			<< " не найден\n";*/
	}
	if (!found)
		cout << "Элемент со значением " << valueForSearch
		<< " не найден\n";
}
