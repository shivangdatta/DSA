#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void shuffle(int *arr, int ll , int ul){
    int i=ul;
    int j;
    srand(time(NULL));
    for( ;i>ll ; i--){
        int j= rand()%(i+1);
        swap(arr[i],arr[j]);
    }
}

int partition(int *arr, int ll , int ul){
    int pivot=arr[ul];
    int i=ll-1;
    int j=ll;
    for(; j<pivot ; j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[ul]);
    return i+1;
}

int partition_r(int arr[], int low, int high)
{
    // Generate a random number in between
    // low .. high
    srand(time(NULL));
    int random = low + rand() % (high - low);
  
    // Swap A[random] with A[high]
    swap(arr[random], arr[low]);
  
    return partition(arr, low, high);
}

void quicksort(int *arr, int ll , int ul){
    if(ll>=ul){
        return;
    }
    int p =partition(arr,ll,ul);
    quicksort(arr,ll,p-1);
    quicksort(arr,p+1,ul);
}

int main(){
    int size;
    cin>>size;
    int arr[size];
    for(int i=0 ; i<size ; i++){
        cin>>arr[i];
    }
    shuffle(arr,0,size-1);
    for(int i=0 ; i<size ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    quicksort(arr, 0 ,size-1);
    for(int i=0 ; i<size ; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}