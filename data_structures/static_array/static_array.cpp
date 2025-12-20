
using namespace std;

bool append(int arr[], int value, int &size, int capacity);

int main(){
    int arr[100];
    int size = 0;
    int capacity = 100;
}

bool append(int arr[], int value, int &size, int capacity){
    if (size >= capacity){
        return false;
    }
    arr[size] = value;
    size++;
    return true;
}