#include <iostream>
#include <cmath>

struct Pyramid
{
private:
    int size;
    int* pyramid;
public:
    Pyramid(int* arr, int size)
    {
        this->size = size;
        pyramid = new int[size];
        for (int i = 0; i < size; ++i)
        {
            pyramid[i] = arr[i];
        }
    }

    std::string getName(int index)
    {
        if (index == 0)
        {
            return "root";
        }
        else if (index % 2 != 0)
        {
            return "left";
        }
        else if (index % 2 == 0)
        {
            return "right";
        }
    }
    int getElement(int index)
    {
        return pyramid[index];
    }
    int getLeftChild(int parentIndex)
    {
        return 2 * parentIndex + 1;
    }
    int getRightChild(int parentIndex)
    {
        return 2 * parentIndex + 2;
    }
    int getParent(int childIndex)
    {
        return (childIndex - 1) / 2;
    }
    int getSize()
    {
        return size;
    }
    int getLevel(int index)
    {
        return static_cast<int>(log2(index));
    }

    void clear_memory() // Очищение памяти
    {
        delete[] pyramid;
        pyramid = nullptr;
    }
};

void printPyramid(Pyramid pyr) // Печать пирамиды
{
    std::cout << "Пирамида:" << std::endl;
    for (int i = 0; i < pyr.getSize(); ++i)
    {
        if (i == 0)
        {
            std::cout << 0 << " "
                << pyr.getName(i) << " "
                << pyr.getElement(i) << std::endl;
        }
        else
        {
            std::cout << pyr.getLevel(i) << " "
                << pyr.getName(i) << " ("
                << pyr.getElement(pyr.getParent(i)) << ") "
                << pyr.getElement(i) << std::endl;
        }
    }

}

void printArr(int* arr, int size) // Печать массива
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char** argv) {

    system("chcp 1251");
    int arr[] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };
    size_t size = std::size(arr);
    Pyramid pyr(arr, size);

    std::cout << "Исходный массив: ";
    printArr(arr, size);

    printPyramid(pyr);
    pyr.clear_memory();

    return 0;
}