#include <iostream>
#include<time.h>
using namespace std;

template<class T>
void completion(T* array, int size) {
	for (int i = 0; i < size; i++)
		* (array + i) = rand() % 100;
}
template<class T>
void showArray(T* array, int size) {
	for (int i = 0; i < size; i++)
		cout << *(array + i) << " ";
	cout << endl;
}
template<class T>
void searchMin(T* array, int size) {
	int min = *array;
	for (int i = 0; i < size; i++)
		if (*(array + i) < min)
			min = *(array + i);
	cout << "Минимальное значение: " << min << endl;
}
template<class T>
void searchMax(T* array, int size) {
	int max = *array;
	for (int i = 0; i < size; i++)
		if (*(array + i) > max)
			max = *(array + i);
	cout << "Максимальное значение: " << max << endl;
}
template<class T>
void sort(T* array, int size) {
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (*(array + i) < *(array + j))
				swap(*(array + i), *(array + j));
}
template<class T>
void edit(T* array, int size) {
	int index;
	T value;
	cout << "Введите номер элемента, который хотите заменить(1 - " << size << "): ";
	cin >> index;
	cout << "Введите новое значение: " << endl;
	cin >> value;
	array[index - 1] = value;
}
template<class T>
void binarySearch(T* array, int size) {
	T key;
	int begin = 0;
	int end = size;
	int mid;
	cout << "Введите значение для поиска: ";
	cin >> key;
	while (begin < end) {
		mid = (begin + end) / 2;
		if (array[mid] > key) end = mid;
		else begin = mid + 1;
	}
	end--;
	if (array[end] == key) cout << "Индекс элемента " << key << " в массиве равен: " << end << endl;
	else cout << "Такого элемента в массиве нет" << endl;

}

int main()
{
	srand(time(0));
	setlocale(0, "");
	const int SIZE = 10;
	int Array[SIZE];
	completion(Array, SIZE);
	cout << "Создание массива из " << SIZE << " элементов. " << endl;
	showArray(Array, SIZE);
	cout << "Сортировка масива: " << endl;
	sort(Array, SIZE);
	showArray(Array, SIZE);
	cout << "Поиск максимального значения массива.\n";
	searchMax(Array, SIZE);
	cout << "Поиск минимального значения массива.\n";
	searchMin(Array, SIZE);
	cout << "Бинарный поиск элемента массива: " << endl;
	binarySearch(Array, SIZE);
	cout << "Замена элемента массива: " << endl;
	edit(Array, SIZE);
	showArray(Array, SIZE);
}
