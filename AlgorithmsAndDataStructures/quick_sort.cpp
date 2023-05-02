#include <iostream>

void initialize_array(int*, int);

void swap(int&, int&);

int partition(int*, int, int);

void quickSort(int*, int, int);

void printArray(int*, int);

int main(){
	int size = 0;
	std::cout << "Input size of array: ";
	std::cin >> size;
	int* arr = new int[size];
	initialize_array(arr, size);
	quickSort(arr, 0, size - 1);
	printArray(arr, size);

	return 0;
}

void initialize_array(int* arr, int size){
	std::cout << "Input array elements:" << std::endl;
	for(int i = 0; i < size; ++i){
		std::cout << "array[" << i <<"]=";
		std::cin >> arr[i];
	}
}

void swap(int& a, int& b){
	int temp = a;
	a = b;
	b = temp;
}

int partition(int* arr, int start, int end){
	int pivot = arr[start];
	int count = 0;
	for(int i = start + 1; i <= end; ++i){
		if(arr[i] <= pivot){
			count++;
		}
	}
	int pivotIndex = start + count;
	swap(arr[pivotIndex], arr[start]);
	int first = start, last = end;
	while(first < pivotIndex && last > pivotIndex){
		while(arr[first] <= pivot){
			first++;
		}
		while(arr[last] > pivot){
			last--;
		}
		if(first < pivotIndex && last > pivotIndex){
			swap(arr[first++], arr[last--]);
		}
	}
	return pivotIndex;
}

void quickSort(int* arr, int start, int end){
	if(start >= end){
		return;
	}
	int pivotIndex = partition(arr, start, end);
	quickSort(arr, start, pivotIndex - 1);
	quickSort(arr, pivotIndex + 1, end);
}

void printArray(int* arr, int size){
	std::cout << "Sorted array:" << std::endl;
	for(int i = 0; i < size; ++i){
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}