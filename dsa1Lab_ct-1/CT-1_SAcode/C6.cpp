#include  <iostream>
using namespace std;

void swap(int a, int b, char arr[]) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int binarySearch(char arr[], char target, int left, int right) {
    int count=0;
    while (left <= right) {
        int mid = (right + left) / 2;
        if (arr[mid] == target) {
            count++;
            return count;
        }
        else {
            if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }

    return -1;
}

int main() {

    char arr[] = {"Sifatiii"};
    int size=sizeof(arr)/sizeof(arr[0]);

    char target;
    cin>>target;

    int flag=0;

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                flag++;
                swap(j, j + 1, arr);
            }
        }
        if(flag==0){
            break;
        }
    }

    int result = binarySearch(arr, target, 0, size);

    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}