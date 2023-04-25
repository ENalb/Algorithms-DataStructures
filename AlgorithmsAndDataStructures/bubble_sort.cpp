#include <iostream>

void swap(int& a, int& b){
	int temp = a;
	a = b;
	b = temp;
}

bool is_sorted(int* arr, int size){
	if(size == 0 || size == 1){
		return true;
	}
	if(arr[size - 1] < arr[size - 2]){
		return false;
	}
	return is_sorted(arr, size - 1);
}

void bubble_sort(int* arr, int size){
	bool flag = is_sorted(arr, size);
	if(flag){
		std::cout << "Array is already sorted!!!" << std::endl;
	}
	else{
		for(int i = 0; i < size; ++i){
			for(int j = 0; j < (size - i - 1); ++j){
				if(arr[j] > arr[j + 1]){
					swap(arr[j], arr[j + 1]);
				}
			}
		}
	}
}

void initialize_array(int* arr, int size){
	std::cout << "Input array elements:" << std::endl;
	for(int i = 0; i < size; ++i){
		std::cout << "array[" << i << "]=";
		std::cin >> arr[i];
	}
}

void print_array(int* arr, int size){
	bubble_sort(arr, size);
	std::cout << "Sorted array: ";
	for(int i = 0; i < size; ++i){
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

int main(){
	int size = 0;
	std::cout << "Input size of array: ";
	std::cin >> size;
	int* arr = new int[size];
	initialize_array(arr, size);
	print_array(arr, size);
	delete[] arr;
	arr = nullptr;

	return 0;
}