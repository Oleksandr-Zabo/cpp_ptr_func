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
        arr[i] = rand() % 10;
    }
    return arr;
}

template<typename T>
void print_array(T* arr, int* size)
{
    if (arr == nullptr && size == nullptr)
    {
        cout <<"Error value ";;
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
void sum_product_array(T* arr, int* size, T* &sum, T*& product)
{
    if (arr == nullptr && size == nullptr)
    {
        cout << "Error value ";;
    }
    else{
        T* sum_arr = new T{ 0 };
        T* product_arr = new T{ 1 };
        for (int i = 0; i < *size; i++)
    {
            *sum_arr += arr[i];
            *product_arr *= arr[i];
    }
        *sum = *sum_arr;
        *product = *product_arr;
        delete_ptr(sum_arr);
        delete_ptr(product_arr);
    }
}

int main()
{ 
    srand(time(0));

    int* size = new  int{1};
    do
    {
        cout << "Enter size: ";
        cin >> *size;
    } while (*size < 1);
    int* sum = new int{ 0 };
    int* product = new int{ 1 };

    int* arr = init_array<int>(size);


    cout << "Array: " << endl;
    void (*ptr_func_print)(int*, int*) = print_array<int>;
    ptr_func_print(arr, size);

    sum_product_array(arr, size,sum, product);
    cout << "Sum: "<<*sum << endl;
    cout << "Product: " << *product << endl;
    delete_ptr(size);
    delete_ptr(sum);
    delete_ptr(product);
    delete_ptr(arr, PointerType::ARRAY);
	

	system("pause");
	return 0;
}