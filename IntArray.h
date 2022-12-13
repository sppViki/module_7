#ifndef INTARRAY_H
#define INTARRAY_H

//#include <cassert> // for assert()
#include <iostream>


class IntArray
{
private:
    int m_length{};
    int* m_data{};

public:
    IntArray() = default;

    IntArray(int length):
        m_length{ length }
    {
       // assert(length >= 0);
        if(length < 0)
        {
            throw std::string("123");
        }
        if (length > 0)
            m_data = new int[length]{};
    }

    ~IntArray()
    {
        delete[] m_data;
    }

    void erase()
    {
        delete[] m_data;
        m_data = nullptr;
        m_length = 0;
    }

    int& operator[](int index)
    {
        //assert(index >= 0 && index < m_length);
        if(index < 0 || index > m_length)
        {
            throw std::string("124");
        }

        return m_data[index];
    }

    void reallocate(int newLength)
    {
        // Удаляем все существующие элементы внутри массива
        erase();

        // Если массив должен быть пустой, возвращаемся сюда
        if (newLength <= 0)
            return;

        // Выделяем новые элементы
        m_data = new int[newLength];
        m_length = newLength;
    }

    // Изменяем размер массива
    void resize(int newLength)
    {
        // Если массив имеет нужную длину, выполняем return
        if (newLength == m_length)
            return;

        // Если изменяем размер до пустого, сделайте это и выполняем return
        if (newLength <= 0)
        {
            erase();
            return;
        }

        // Выделяем новый массив
        int* data{ new int[newLength] };

        // Копируем столько элементов, сколько в меньшем массиве
        if (m_length > 0)
        {
            int elementsToCopy{ (newLength > m_length) ? m_length : newLength };

                                // Поочередно копируем элементы
                                for (int index{ 0 }; index < elementsToCopy; ++index)
                                    data[index] = m_data[index];
                              }

            // Удаляем старый массив
            delete[] m_data;

            // Используем вместо старого массива новый

            m_data = data;
            m_length = newLength;
        }

        void insertBefore(int value, int index)
        {
            // Проверка корректности передаваемого индекса
            //assert(index >= 0 && index <= m_length);
            if(index < 0 || index > m_length)
            {
                throw std::string("123");
            }

            // Создаем новый массив на один элемент больше старого массива
            int* data{ new int[m_length+1] };

            // Копируем все элементы до index
            for (int before{ 0 }; before < index; ++before)
                data[before] = m_data[before];

            // Вставляем новый элемент в новый массив
            data[index] = value;

            // Копируем все значения после вставляемого элемента
            for (int after{ index }; after < m_length; ++after)
                data[after+1] = m_data[after];

            // Удаляем старый массив и используем вместо него новый массив
            delete[] m_data;
            m_data = data;
            ++m_length;
        }

        void remove(int index)
        {
            // Проверка на корректность передаваемого индекса
            //assert(index >= 0 && index < m_length);
            if(index < 0 || index > m_length)
            {
                throw std::string("124");
            }

            // Если это последний элемент массива, то делаем массив пустым и выполняем return
            if (m_length == 1)
            {
                erase();
                return;
            }

            // Создаем новый массив на один элемент меньше старого массива
            int* data{ new int[m_length-1] };

            // Копируем все элементы до индекса
            for (int before{ 0 }; before  < index; ++before)
                data[before] = m_data[before];

            // Копируем все значения после удаляемого элемента
            for (int after{ index+1 }; after < m_length; ++after)
                data[after-1] = m_data[after];

            // Удаляем старый массив и используем вместо него новый массив
            delete[] m_data;
            m_data = data;
            --m_length;
        }

        // Доп.функции для удобства
        void insertAtBeginning(int value) { insertBefore(value, 0); }
        void insertAtEnd(int value) { insertBefore(value, m_length); }

        int getLenght() const {return m_length;}
    };

#endif
