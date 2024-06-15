#include <iostream>
#include <ctime>
using namespace std;


template<typename T>
T* init_array(int*& size)
{
    if (size == nullptr)
    {
        size = new int{ 10 };
    }
    T* arr = new T[*size];
    for (int i = 0; i < *size; i++)
    {
        arr[i] = rand() % 10 - 5;
    }
    return arr;
}

template<typename T>
void print_array(T* arr, int* size)
{
    if (arr == nullptr || size == nullptr)
    {
        cout << "Error value (nullptr) ";;
    }
    else {
        for (int i = 0; i < *size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

template<typename T>
void sum_product_array(T* arr, int* size, T*& count_p, T*& count_z, T*& count_n)
{
    if (arr == nullptr || size == nullptr)
    {
        cout << "Error value (nullptr)";;
    }
    else {
        T* posit = new T{ 0 };
        T* zero = new T{ 0 };
        T* neg = new T{ 0 };
        for (int i = 0; i < *size; i++)
        {
            if (arr[i] > 0) {
                *posit += 1;
            }
            else if (arr[i] < 0) {
                *neg += 1;
            }
            else {
                *zero += 1;
            }

        }
        count_p = new T{ *posit };
        count_z = new T{ *zero };
        count_n = new T{ *neg };
       
    }
}

int main()
{
    srand(time(0));

    int* size = new  int{ 1 };
    do
    {
        cout << "Enter size: ";
        cin >> *size;
    } while (*size < 1);
    int* count_p = nullptr;
    int* count_z = nullptr;
    int* count_n = nullptr;

    int* arr = init_array<int>(size);


    cout << "Array: " << endl;
    void (*ptr_func_print)(int*, int*) = print_array<int>;
    ptr_func_print(arr, size);

    sum_product_array<int>(arr, size, count_p, count_z, count_n);

    cout << "Count of positive: " << *count_p << endl;
    cout << "Count of zero: " << *count_z << endl;
    cout << "Count of negative: " << *count_n << endl;

    system("pause");
    return 0;
}