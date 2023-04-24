#include <iostream>

int binary_search(int* arr, int size, int item){
	int low = 0;
	int high = size - 1;
	while(low <= high){
		int mid = (low + high) / 2;
		int guess = arr[mid];
		if(guess == item){
			return mid;
		}
		if(guess > item){
			high = mid - 1;
		}
		else{
			low = mid + 1;
		}
	}
	return -1;
}

void initialize_array(int* arr, int size){
	std::cout << "Input sorted array elements: " << std::endl;
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
	std::cout << "Input item which index you want to know: ";
	int item = 0;
	std::cin >> item;
	int result = binary_search(arr, size, item);
    	(result == -1) ? std::cout << "Element is not present in array" << std::endl : std::cout << "Element is present at index " 
    		<< result << std::endl;
    	delete[] arr;
}
