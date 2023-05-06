#include <iostream>

void initialize(int*, int);

void swap(int&, int&);

void selectionSort(int*, int);

void print(int*, int);

int main(){
	int size = 0;
	std::cout << "Input size of array: ";
	std::cin >> size;
	int* array = new int[size];
	initialize(array, size);
	selectionSort(array, size);
	print(array, size);
	delete[] array;
	array = nullptr;

	return 0;
}

void initialize(int* arr, int size){
	std::cout << "Input array elements:" << std::endl;
	for(int i = 0; i < size; ++i){
		std::cout << "array[" << i << "]=";
		std::cin >> arr[i];
	}
}

void swap(int& a, int& b){
	int temp = a;
	a = b;
	b = temp;
}

void selectionSort(int* arr, int size){
	int min_index = 0;
	for(int i = 0; i < size - 1; ++i){
		for(int j = i + 1; j < size; ++j){
			if(arr[j] < arr[min_index]){
				min_index = j;
			}
		}
		if(min_index != i){
			swap(arr[i], arr[min_index]);
		}
	}
}

void print(int* arr, int size){
	std::cout << "Sorted array: ";
	for(int i = 0; i < size; ++i){
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}
