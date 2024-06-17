#include <iostream>
#include <ctime>
using namespace std;


enum PointerType
{
    ARRAY,
    POINTER
};

template<typename T>
void delete_ptr(T* ptr, PointerType pointer_type = PointerType::POINTER) {//func : delete dynamic array, pointers
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
T* init_array(int*& size)//func :init dynamic arr,  allocates dynamic memory 
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
void print_array(T* arr, int* size)// func : print array
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
void array_append(T*& arr, int*& size, T* elem_to_end)// func: add elem to end
{
    if (arr == nullptr && size == nullptr
        && elem_to_end == nullptr)
    {
        cout << "Error value ";;
    }
    else {
        int* size_new = new  int{ (*size) + 1};
        T* arr_new = new T[*size_new];
        for (int i = 0; i < *size; i++)
        {
            arr_new[i] = arr[i];
            
        }
        arr_new[*size] = *elem_to_end;

        T* temp = arr;//delete old ptr
        arr = arr_new;
        *size = *size_new;
        delete_ptr(size_new);
        delete_ptr(temp, PointerType::ARRAY);

    }
}



template<typename T>
void array_insert(T*& arr, int*& size, T* elem, int* index)// func: add elem to index
{
    if (arr == nullptr && size == nullptr
        && elem == nullptr
        && index == nullptr)
    {
        cout << "Error value ";;
    }
    else {
        int* size_new = new  int{ (*size) + 1 };
        T* arr_new = new T[*size_new];
        for (int i = 0; i < *size_new; i++)
        {
            if (i < *index) {

                arr_new[i] = arr[i];
            }
            else if (i == *index) {
                arr_new[i] = *elem;
            }
            else{
                arr_new[i] = arr[i - 1];
            }
        }

        T* temp = arr;//delete old ptr
        arr = arr_new;
        *size = *size_new;
        delete_ptr(size_new);
        delete_ptr(temp, PointerType::ARRAY);

    }
}

template<typename T>
void array_del_elem(T*& arr, int*& size, int* index)// func: delete elem from index
{
    if (arr == nullptr && size == nullptr
        && index == nullptr)
    {
        cout << "Error value ";;
    }
    else {
        int* size_new = new  int{ (*size) - 1 };
        T* arr_new = new T[*size_new];
        for (int i = 0; i < *size_new; i++)
        {
            if (i < *index) {

                arr_new[i] = arr[i];
            }
            else {
                arr_new[i] = arr[i + 1];
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


    int* size_elem = new  int{ 1 };
    int* arr = init_array<int>(size);
    int* elem = init_array<int>(size_elem);

    cout << "Array 1: " << endl;
    void (*ptr_func)(int*, int*) = print_array<int>;
    ptr_func(arr, size);

    cout << "Elem: " << endl;
    ptr_func(elem, size_elem);
    array_append<int>(arr, size, elem);
    cout << "\nArray 2: " << endl;
    ptr_func(arr, size);


    int* index = new  int{ 1 };
    do
    {
        cout << "Enter index of element to insert: ";
        cin >> *index;
    } while (*index < 0 || *index > *size);


    array_insert<int>(arr, size, elem, index);
    cout << "\nArray 3: " << endl;
    ptr_func(arr, size);

    do
    {
        cout << "Enter index of element to delete: ";
        cin >> *index;
    } while (*index < 0 || *index > *size);

    array_del_elem<int>(arr, size, index);
    cout << "\nArray 4: " << endl;
    ptr_func(arr, size);


    delete_ptr(size);
    delete_ptr(index);
    delete_ptr(elem);
    delete_ptr(size_elem);
    delete_ptr(arr, PointerType::ARRAY);//delete array


    system("pause");
    return 0;
}