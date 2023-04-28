#include <iostream>

void initialize_array(int*, int);

void merge(int*, int, int, int);

void mergeSort(int*, int, int);

void printArray(int*, int);

int main(){
	int size = 0;
	std::cout << "Input array size: ";
	std::cin >> size;
	int* array = new int[size];
	initialize_array(array, size);
	mergeSort(array, 0, size - 1);
	printArray(array, size);	
	delete[] array;
	array = nullptr;

	return 0;
}

void initialize_array(int* arr, int size){
	std::cout << "Input array elements:" << std::endl;
	for(int i = 0; i < size; ++i){
		std::cout << "array[" << i << "]=";
		std::cin >> arr[i];
	}
}

void printArray(int* arr, int size){
	std::cout << "Sorted array: " << std::endl;
	for(int i = 0; i < size; ++i){
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

void merge(int* arr, int start, int mid, int end){
	int first1 = start;
	int last1 = mid;
	int first2 = mid + 1;
	int last2 = end;
	int index = 0;
	int* tmpArray = new int[end - start + 1];

	while((first1 <= last1) && (first2 <= last2)){
		if(arr[first1] <= arr[first2]){
			tmpArray[index++] = arr[first1++];
		}
		else{
			tmpArray[index++] = arr[first2++];
		}
	}	

	while(first1 <= last1){
		tmpArray[index++] = arr[first1++];
	}

	while(first2 <= last2){
		tmpArray[index++] = arr[first2++];
	}

	for(int i = start; i <= end; ++i){
		arr[i] = tmpArray[i - start];
	}

	delete[] tmpArray;
	tmpArray = nullptr;
}

void mergeSort(int* arr, int start, int end){
	if(start >= end){
		return;
	}
	int mid = start + (end - start) / 2;
	mergeSort(arr, start, mid);
	mergeSort(arr, mid + 1, end);
	merge(arr, start, mid, end);
}