#include <iostream>
#include <ctime>
using namespace std;

enum PointerType
{
    ARRAY,
    POINTER
};

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
        arr[i] = rand() % 3-3;
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
int* b_in_a_array(T* arr_1, int* size_1, T* arr_2, int* size_2)
{
    if (arr_1 == nullptr || size_1 == nullptr || arr_2 == nullptr || size_2 == nullptr)
    {
        cout << "Error value (nullptr)";
    }
    else {
        int* start_b_a = new int{ 0 };
        bool* b_in_a = new bool{ true };
        for (int i = 0; i < *size_1; i++)
        {
            for (int j = 0; j < *size_2; j++)
            {
                if (arr_1[i + j] != arr_2[j]) {
                    * b_in_a = false;
                }
            }
            if (*b_in_a) {
                *start_b_a = i;
                break;
            }
            *b_in_a = true;


        }
        return start_b_a;
    }
}

template<typename T>
void delete_ptr(T *ptr, PointerType pointer_type = PointerType::POINTER) {
    if (ptr == nullptr)
    {
        cout << "ptr is now nullptr";
    }
    switch (pointer_type)
    {
    case PointerType::ARRAY:
    {
        delete[] ptr;
    }break;
    case PointerType::POINTER:
    {
        delete ptr;
    }break;
    }
    ptr = nullptr;
}

int main()
{
    srand(time(0));

    int* size_a = new  int{ 1 };
    do
    {
        cout << "Enter size a: ";
        cin >> *size_a;
    } while (*size_a < 1);

    int* arr_a = init_array<int>(size_a);

    int* size_b = new  int{ 1 };
    do
    {
        cout << "Enter size b: ";
        cin >> *size_b;
    } while (*size_b < 1 || *size_b>*size_a);

    int* arr_b = init_array<int>(size_b);

    void (*ptr_func_print)(int*, int*) = print_array<int>;

    cout << "Array a: " << endl;
    ptr_func_print(arr_a, size_a);

    cout << "Array b: " << endl;
    ptr_func_print(arr_b, size_b);
     int* start_b_a = b_in_a_array(arr_a, size_a, arr_b, size_b);

    cout << "Array b in a start at: "<< *start_b_a << endl;

    delete_ptr(size_a);
    delete_ptr(size_b);
    delete_ptr(start_b_a);
    delete_ptr(arr_a, PointerType::ARRAY);
    delete_ptr(arr_b, PointerType::ARRAY);

    system("pause");
    return 0;
}