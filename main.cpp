#include <iostream>
#include "IntArray.h"

int main()
{

    // Обьявить массив из 10 элементов
    IntArray array(10);


    // Заполнить массив числами от 1 до 10
    for (int i{ 0 }; i<10; ++i)
      array[i] = i+1;

    try
    {
    // Изменить размер массива до 8 элементов
   array.resize(8);
    }
    catch(std::string &exept)
    {
        std::cout << "Exept!!! Razmer massiva <0" << exept << std::endl;
    }

    try
    {
    // Вставить число 20 перед элементом с индексом 5
    array.insertBefore(20, 5);
    }
    catch(std::string &exept)
    {
        std::cout << "Exept!!!Oshibka razmer massiva" << exept << std::endl;
    }

    // Удалить элемент с индексом 3
    array.remove(3);

    // Добавить 30 и 40 к концу и к началу
    array.insertAtEnd(30);
    array.insertAtBeginning(40);

    // Вывести все элементы массива
    for (int i{ 0 }; i<array.getLenght(); ++i)
        std::cout << array[i] << ' ';

    std::cout << '\n';

    return 0;
}
