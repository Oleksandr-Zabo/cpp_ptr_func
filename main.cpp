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
        arr[i] = rand() % 20-10;//range of rand_num
    }
    return arr;
}

template<typename T>
void print_array(T* arr, int* size)
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
void array_remove(T*& arr, int*& size, int* size_block, int* index)
{
    if (arr == nullptr && size == nullptr
        && size_block == nullptr
        && index == nullptr)
    {
        cout << "Error value ";
    }
    else {
        int* size_new = new  int{ (*size) - (*size_block) };
        T* arr_new = new T[*size_new];

        for (int i = 0, j = 0; i < *size_new; i++)
        {
            if (i < *index) {

                arr_new[i] = arr[j];
                j++;
            }
            else {
                arr_new[i] = arr[i + *size_block];
            }
        }

        T* temp = arr;//delete old ptr
        arr = arr_new;
        *size = *size_new;
        delete_ptr(size_new);
        delete_ptr(temp, PointerType::ARRAY);

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
    void (*ptr_func)(int*, int*) = print_array<int>;
    ptr_func(arr, size);


    int* size_remove_block = new  int{ 1 };
    do
    {
        cout << "Enter size of block: ";
        cin >> *size_remove_block;
    } while (*size_remove_block < 1 || *size_remove_block > *size);

    int* index = new  int{ 1 };
    do
    {
        cout << "Enter index of block: ";
        cin >> *index;
    } while (*index < 0 || (*index + *size_remove_block) > *size);



    array_remove<int>(arr, size, size_remove_block, index);

    cout << "Array 2: " << endl;
    ptr_func(arr, size);



    delete_ptr(size);
    delete_ptr(index);
    delete_ptr(arr, PointerType::ARRAY);
    delete_ptr(size_remove_block);


    system("pause");
    return 0;
}