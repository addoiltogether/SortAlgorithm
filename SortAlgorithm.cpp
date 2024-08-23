#include <iostream>
#include <vector> 
#include <cstdlib>
#include <ctime>
using namespace std;


void quickSortInternal(vector<int>& nums, int left, int right) {
	if (left >= right) {
		return;
	}
	int i = left;
	int j = right;
	int pivot = nums[left];
	while (i < j) {
		while(i < j && nums[j] >= pivot) {
			j--;
		}
		swap(nums[i], nums[j]);
		while(i < j && nums[i] < pivot) {
			i++;
		}
		swap(nums[i], nums[j]);
	}
	quickSortInternal(nums, left, i - 1);
	quickSortInternal(nums, i + 1, right); 
}


void quickSort(vector<int>& nums) {
	quickSortInternal(nums, 0, nums.size() - 1);
}




void mergeTwoVec(vector<int>& nums, int left, int mid, int right) {
	int i = left;
	int j = mid + 1;
	vector<int> tmp;
	while(i <= mid && j <= right) {
		if (nums[i] <= nums[j]) {
			tmp.push_back(nums[i]);
			i++; 
		} else {
			tmp.push_back(nums[j]);
			j++;
		}
	}
	while(i <= mid) {
		tmp.push_back(nums[i]);
		i++;
	}
	while(j <= right) {
		tmp.push_back(nums[j]);
		j++;
	}
	int index = 0;
	for (int k = left; k <= right; k++) {
		nums[k] = tmp [index++];	
	}
}

void mergeSortInternal(vector<int>& nums, int left, int right) {
	if (left >= right) {
		return;
	}
	int mid = left + (right - left) / 2;
	mergeSortInternal(nums, left, mid);
	mergeSortInternal(nums, mid + 1, right);
	mergeTwoVec(nums, left, mid, right); 
}


void mergeSort(vector<int>& nums) {
	mergeSortInternal(nums, 0, nums.size() - 1);
}


void heapModify(vector<int>& nums, int size, int modify_index) {
	int largest = modify_index;
	int left_index = modify_index * 2 + 1;
	int right_index = modify_index * 2 + 2;
	if (left_index < size && nums[left_index] > nums[largest]) {
		largest = left_index;
	}
	if (right_index < size && nums[right_index] > nums[largest]) {
		largest = right_index;
	}
	if (largest != modify_index) {
		swap(nums[largest], nums[modify_index]);
		heapModify(nums, size, largest);
	}
}


void heapSort(vector<int>& nums) {
	int size = nums.size();
	for (int i = size / 2 - 1; i >= 0; i--) {
		heapModify(nums, size, i);
	}
	for (int i = size - 1; i >= 0; i--) {
		swap(nums[0], nums[i]);
		heapModify(nums, i, 0); 
	}
}




/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void printVec(vector<int>& vec) {
	for (int i = 0; i < vec.size(); i++) {
		if (i == vec.size() - 1) {
			cout << vec[i] << endl;
		} else {
			cout << vec[i] << " ";
		}
	}
	return;
}


int main(int argc, char** argv) {
	srand(time(NULL));
	vector<int> vec;
	for (int i = 0; i < 10; i++) {
		vec.push_back(rand() % 100);
	} 
	
	cout << "before Sort: " << endl;
	printVec(vec);
	// quick sort 
	cout << "after quickSort:" << endl;
	quickSort(vec);
	printVec(vec);
	
	// merge sort
	cout << "after mergeSort:" << endl;
	mergeSort(vec);
	printVec(vec);
	
	// heap sort
	cout << "after heapSort:" << endl;
	heapSort(vec);
	printVec(vec);
	return 0;
}
