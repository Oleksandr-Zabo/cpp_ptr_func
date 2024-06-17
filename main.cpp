#include <iostream>
#include <ctime>
using namespace std;

enum PointerType
{
    ARRAY,
    POINTER
};

template<typename T>
void delete_ptr(T* ptr, PointerType pointer_type = PointerType::POINTER) {
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



template<typename T>
void print_array(T* arr, int* size)
{
    if (arr == nullptr && size == nullptr)
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
void dynamic_array(T* arr, int* size, T*& arr_p, T*& arr_z, T*& arr_n, int*& count_p, int*& count_z, int*& count_n)
{
    if (arr == nullptr || size == nullptr)
    {
        cout << "Error value (nullptr)";
    }
    else {
        int posit = 0;
        int zero = 0;
        int neg = 0;
        for (int i = 0; i < *size; i++)
        {
            if (arr[i] > 0) {
                posit++;
            }
            else if (arr[i] < 0) {
                neg++;
            }
            else {
                zero++;
            }
        }

        count_p = new int{ posit };
        count_z = new int{ zero };
        count_n = new int{ neg };

        T* p_arr = new T[*count_p];
        T* z_arr = new T[*count_z];
        T* n_arr = new T[*count_n];

        for (int i = 0, p = 0, z = 0, n = 0; i < *size; i++)
        {
            if (arr[i] > 0) {
                p_arr[p++] = arr[i];
            }
            else if (arr[i] < 0) {
                n_arr[n++] = arr[i];
            }
            else {
                z_arr[z++] = arr[i];
            }
        }

        
        delete[] arr_p;//delete old memory
        delete[] arr_n;
        delete[] arr_z;
        arr_p = p_arr;
        arr_z = z_arr;
        arr_n = n_arr;
         
    }
}



int main()
{
    srand(time(0));

    int const MAX_SIZE = 100;

    int* size = new  int{ 1 };
    do
    {
        cout << "Enter size: ";
        cin >> *size;
    } while (*size < 1 || *size > MAX_SIZE);

    int* count_p = nullptr;
    int* count_z = nullptr;
    int* count_n = nullptr;

    int* pos_arr = nullptr;
    int* zero_arr = nullptr;
    int* neg_arr = nullptr;
    int arr[MAX_SIZE];

    if (size == nullptr)
    {
        size = new int{ 10 };
    }
    for (int i = 0; i < *size; i++)
    {
        arr[i] = rand() % 10 - 5; 
        cout << arr[i] << " ";
    }

    void (*ptr_func_print)(int*, int*) = { print_array<int>};
    cout << endl;

    dynamic_array(arr, size, pos_arr, zero_arr, neg_arr, count_p, count_z, count_n);

    cout << "\nArray of positive: " << endl;
    ptr_func_print(pos_arr, count_p);
    cout << endl;

    cout << "\nArray of zero: " << endl;
    ptr_func_print(zero_arr, count_z); 
    cout << endl;


    cout << "\nArray of negative: " << endl;
    ptr_func_print(neg_arr, count_n);

    delete_ptr(size);
    delete_ptr(count_p);
    delete_ptr(count_z);
    delete_ptr(count_n);
    delete_ptr(pos_arr, PointerType::ARRAY);
    delete_ptr(neg_arr, PointerType::ARRAY);
    delete_ptr(zero_arr, PointerType::ARRAY);
    system("pause");
    return 0;
}