//Objective:  

// To sort a given set of elements using the Quick Sort method and determine the time required to sort the elements. Repeat the experiment for different values of n and plot a graph of time taken vs number of elements.

#include <iostream> 

using namespace std; 

  

int partition(int arr[], int low, int high) { 

    int pivot = arr[high]; 

    int i = low - 1; 

  

    for(int j = low; j < high; j++) { 

        if(arr[j] <= pivot) { 

            i++; 

            swap(arr[i], arr[j]); 

        }
            } 

  

    swap(arr[i + 1], arr[high]); 

    return i + 1; 

} 

  

void quickSort(int arr[], int low, int high) { 

    if(low < high) { 

        int pi = partition(arr, low, high); 

        quickSort(arr, low, pi - 1); 

        quickSort(arr, pi + 1, high); 

    } 

}
int main() { 

    int n; 

  

    cout << "Enter the number of elements: "; 

    cin >> n; 
     int arr[n]; 

  

    cout << "Enter the elements:\n"; 

    for(int i = 0; i < n; i++) { 

        cin >> arr[i]; 

    } 

  

    quickSort(arr, 0, n - 1); 

  

    cout << "Sorted array:\n"; 

    for(int i = 0; i < n; i++) { 

        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}