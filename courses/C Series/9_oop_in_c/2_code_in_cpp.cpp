#include <iostream>

struct array
{
    int* _data;
    size_t _size;

    array(int capacity)
    {
        this->_data = new int[capacity];
    }
    
    ~array()
    {
        delete[] _data;
    }

    void set(size_t index, int value)
    {
        _data[index] = value;
    }
    int get(size_t index)
    {
        return _data[index];
    }
};

int main() 
{
    array* test = new array(10);
    for(int i=0; i<10; i++)
        test->set(i,i);

    std::cout << "[";
    for(int i=0; i<10; i++)
        std::cout << test->get(i) << ",";
    std::cout << "]\n"; // [0,1,2,3,4,5,6,7,8,9,]

    return 0;
}