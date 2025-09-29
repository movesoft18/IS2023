#include <iostream>
#include <cassert>
using namespace std;


class List
{
    int* array;
    size_t capacity;
    size_t size;
    
protected:
    void enlarge(int value) {}
public:
    List(int capacity = 10) :
        capacity(capacity),
        size(0)
    {
        array = new int[capacity];
    }

    virtual ~List()
    {
        if (array)
            delete[] array;
    }

    size_t getCapacity() const { return capacity; }
    size_t getSize() const { return size; }

    void add(int value)
    {
        if (size < capacity)
        {
            array[size++] = value;
        }
        else
        {
            enlarge(value);
        }
    }

    int& operator [] (int index)
    {
        assert(!(index >= size || index < 0));
        //if (index >= size || index < 0)
        //    throw out_of_range("List index out of range.");
        return array[index];
    }

    //const int& operator [] (int index)
    //{
    //    return array[index];
    //}

};

int main()
{
    List list;
    list.add(1);
    list.add(2);
    list.add(3);
    list[2] = 700;
    cout << list[0] << " " << list[1] << " " <<
        list[2] << " " << list[3] << endl;
}