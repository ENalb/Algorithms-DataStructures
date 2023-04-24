#include <iostream>

int max(int a, int b){
	if(a >= b){
		return a;
	}
	return b;
}

int largest_value_of_array(int* arr, int size){
	if(size == 1){
		return arr[0];
	}
	return max(arr[size-1], largest_value_of_array(arr, size - 1));
}

void initialize_array(int* arr, int size){
	for(int i = 0; i < size; ++i){
		std::cout << "array[" << i << "]=";
		std::cin >> arr[i];
	}
}

int main(){
	int size = 0;
	std::cout << "Input size of array: ";
	std::cin >> size;
	int* arr = new int[size];
	initialize_array(arr, size);
	std::cout << "Max element of array: " << largest_value_of_array(arr, size) << std::endl;
    	delete[] arr;
}
