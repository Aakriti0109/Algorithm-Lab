//Objective 

// To implement Parallel Merge Sort using C++ threads.  

// To understand multithreading in C++.  

// To compare sequential and parallel execution.  

// To learn thread creation and synchronization using std::thread. 

#include<iostream> 

#include<vector> 

#include<thread>

 

using namespace std; 

 

void merge(vector<int>& arr, int low, int mid, int high) 

{ 

    vector<int> temp; 

 

    int left = low; 

    int right = mid + 1; 

 

    while (left <= mid && right <= high) 

    { 

        if (arr[left] <= arr[right]) 

        { 

            temp.push_back(arr[left]); 

            left++; 

        } 

        else 

        { 

            temp.push_back(arr[right]); 

            right++; 

        } 

    } 

 

    while (left <= mid) 

    { 

        temp.push_back(arr[left]); 

        left++; 

    } 

 

    while (right <= high) 

    { 

        temp.push_back(arr[right]); 

        right++; 

    } 

 

    for (int i = low; i <= high; i++) 

        arr[i] = temp[i - low]; 

} 

 

void parallelMergeSort(vector<int>& arr, int low, int high) 

{ 

    if (low >= high) 

        return; 

 

    int mid = low + (high - low) / 2; 

 

    thread leftThread(parallelMergeSort, ref(arr), low, mid); 

    thread rightThread(parallelMergeSort, ref(arr), mid + 1, high); 

 

    leftThread.join(); 

    rightThread.join(); 

 

    merge(arr, low, mid, high); 

} 

 

int main() 

{ 

    vector<int> arr = {8, 4, 2, 6, 1, 5, 7, 3}; 

 

    parallelMergeSort(arr, 0, arr.size() - 1); 

 

    for (int x : arr) 

        cout << x << " "; 

 

    return 0; 

} 