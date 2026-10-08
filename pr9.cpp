#include <exception>
#include <iostream>
#include <string>
using namespace std;

int healths[5] = {20, 50, 80, 100, -20};
int arrSize = 5;

//Ввод даных в массив
void enterData(int* arr, int size){
    for (int i = 0; i < size; i++) {
        cout << "\nEnter num: ";
        cin >> arr[i];
    }
    cout << "\nEnd of enter data\n";
}

//Вывод массива
void showArray(int* arr, int size){
    string result = "\n";
    for (int i = 0; i < size; i++) {
        result += to_string(arr[i]) + "\n";
    }
    cout << result;
}

//Повышение здоровья
void increase(int* arr, int size){
    int value;
    cout << "\nvalue of increase:\n"; cin >> value;
    for (int i = 0; i < size; i++) {
        arr[i] += value;
    }
    cout << "\nHealth increase: " << value << endl;;
}
//Понижение здоровья
void decrease(int* arr, int size){
    int value;
    cout << "\nvalue of decrease:\n"; cin >> value;
    for (int i = 0; i < size; i++) {
        arr[i] -= value;
    }
    cout << "\nHealth decrease: " << value << endl;;
}
//Восстановление здоровья до 100
void restoreHealth(int* arr, int size){
    for (int i = 0; i < size; i++) {
        if (arr[i] < 100) arr[i] = 100;
    }
    cout << "\nAll health are 100\n";
}
//Установка здоровья до лимита
void limit(int* arr, int size){
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) arr[i] = 0;
        if (arr[i] > 100) arr[i] = 100;
    }
    cout << "\nHealth are limited\n";
}

void applyProcessing(
    int* data,
    int size,
    void (*processor)(int*, int)
)
{
    if (processor != nullptr){
        processor(data, size);
    }
}

void (*processors[])(int*, int) = {
    showArray,
    increase,
    decrease,
    restoreHealth,
    limit
};

int main(){
    try {
        int index = -1;
        while (true) {
            cout<< "\n\n0. Show data"
                << "\n1. Increase health"
                << "\n2. Decrease health"
                << "\n3. Restore health to 100"
                << "\n4. Limit all data '0-100'"
                << "\n5. Exit\n";
            cin >> index;
            cout << "\n";

            if (index == 5) break;
            else if (index < 0 || index > arrSize){
                cout << "\nWrong item\n";
            }
            else applyProcessing(healths, arrSize, processors[index]);
        }

        return 0;
    } catch (exception* ex) {
        cout << ex;
    }
}
