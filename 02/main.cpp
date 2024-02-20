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

void printPyramidElement(Pyramid pyr, int index) // Печать элемента пирамиды
{
    std::cout << "Вы находитесь здесь: ";
    if (index == 0)
    {
        std::cout << 0 << " "
            << pyr.getName(index) << " "
            << pyr.getElement(index) << std::endl;
    }
    else
    {
        std::cout << pyr.getLevel(index) << " "
            << pyr.getName(index) << " ("
            << pyr.getElement(pyr.getParent(index)) << ") "
            << pyr.getElement(index) << std::endl;
    }
    std::cout << "Введите команду: ";
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
    int arr[] = { 1, 3, 6, 5, 9, 8 };
    size_t size = std::size(arr);
    Pyramid pyr(arr, size);

    std::cout << "Исходный массив: ";
    printArr(arr, size);

    printPyramid(pyr);

    std::string inputWord = " ";
    int index = 0;

    while (inputWord != "exit")
    {
        printPyramidElement(pyr, index);
        std::cin >> inputWord;

        if (inputWord == "up") // Если ввели up
        {
            if (index == 0) // Если нет родителя
            {
                std::cout << "Ошибка! Отсутствует родитель" << std::endl;
            }
            else // Если родитель есть
            {
                std::cout << "Ок" << std::endl;
                index = pyr.getParent(index); // Получаем индекс родителя
            }
        }
        else if (inputWord == "right") // Если хотим получить правого потомка
        {
            if (pyr.getRightChild(index) >= pyr.getSize()) // Если индекс правого потомка больше размера пирамиды
            {
                std::cout << "Ошибка! Отсутствует правый потомок" << std::endl;
            }
            else
            {
                std::cout << "Ок" << std::endl;
                index = pyr.getRightChild(index); // Получаем индекс правого потомка
            }
        }
        else if (inputWord == "left")// Если хотим получить левого потомка
        {
            if (pyr.getLeftChild(index) >= pyr.getSize())// Если индекс левого потомка больше размера пирамиды
            {
                std::cout << "Ошибка! Отсутствует левый потомок" << std::endl;
            }
            else
            {
                std::cout << "Ок" << std::endl;
                index = pyr.getLeftChild(index);// Получаем индекс левого потомка
            }
        }
        else if (inputWord == "exit")
        {
            break;
        }
        else if (inputWord != "up" && inputWord != "right" && inputWord != "left" && inputWord != "exit") // Если ошибка ввода
        {
            std::cout << "Вы ввели неверную команду" << std::endl;
        }
    }

    pyr.clear_memory(); // Очищение памяти

    return 0;
}