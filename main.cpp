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
T* init_array(int*& size)
{
    if (size == nullptr)
    {
        size = new int{ 10 };
    }
    T* arr = new T[*size];
    for (int i = 0; i < *size; i++)
    {
        arr[i] = rand() % 100 + 1;
    }
    return arr;
}

template<typename T>
void print_array(T*& arr, int*& size)
{
    if (arr == nullptr && size == nullptr)
    {
        cout << "Error value ";;
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
void array_without_prime(T*& arr, int*& size)
{
    if (arr == nullptr && size == nullptr)
    {
        cout << "Error value ";
    }
    else {
        int* size_new = new int{ 0 };
        bool* is_prime = new bool[*size](); 

        for (int i = 0; i < *size; i++) 
        {
            if (arr[i] <= 1) continue; 
            bool prime = true;
            for (int j = 2; j * j <= arr[i]; j++) 
            {
                if (arr[i] % j == 0) {
                    prime = false;
                    break;
                }
            }
            is_prime[i] = !prime;
            if (!prime) {
                (*size_new)++;
            }
        }

        T* arr_new = new T[*size_new];
        for (int i = 0, k = 0; i < *size; i++)
        {
            if (is_prime[i]) { 
                arr_new[k++] = arr[i];
            }
        }

        delete[] arr; 
        delete[] is_prime; 

        arr = arr_new;
        *size = *size_new;
        delete size_new;
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

    int* arr = init_array<int>(size);


    cout << "Array: " << endl;
    void (*ptr_func[])(int*&, int*&) = { print_array<int>, array_without_prime<int> };
    ptr_func[0](arr, size);


    //rewrite func
    ptr_func[1](arr, size);

    cout << "Array 2: " << endl;
    ptr_func[0](arr, size);
    delete_ptr(size);
    delete_ptr(arr, PointerType::ARRAY);


    system("pause");
    return 0;
}