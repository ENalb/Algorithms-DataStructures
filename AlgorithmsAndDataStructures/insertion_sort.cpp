#include <iostream>

void initialize(int*, int);

void swap(int&, int&);

void insertionSort(int*, int);

void print(int*, int);

int main(){
	int size = 0;
	std::cout << "Input size of array: ";
	std::cin >> size;
	int* array = new int[size];
	initialize(array, size);
	insertionSort(array, size);
	print(array, size);

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

void insertionSort(int* arr, int size){
	for(int i = 1; i < size; ++i){
		int j = i;
		while(j > 0 && arr[j] < arr[j - 1]){
			swap(arr[j], arr[j - 1]);
			j--;
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
