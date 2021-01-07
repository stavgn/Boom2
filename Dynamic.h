#ifndef DYNAMIC_H
#define DYNAMIC_H

#include "./Exception.h"
 
namespace DS
{
    template <class DATA>
    class Dynamic
    {
    private:
        void shrink();
        void enlarge();
    public:
        int size;
        int count;
        DATA* array;

        Dynamic();
        ~Dynamic();
        int push();
        DATA &operator[](int index);
        bool shouldResize();

        
    };

    template <class DATA>
    Dynamic<DATA>::Dynamic() : size(4), count(0)
    {
        array = new DATA [4]();
    }
    template <class DATA>
    Dynamic<DATA>::~Dynamic()
    {
        delete[] array;
    }
    template <class DATA>
    int Dynamic<DATA>::push()
    {
        if (shouldResize())
        {
            enlarge();
        }
        count++;
        return (count - 1);
    }
    template <class DATA>
    DATA& Dynamic<DATA>::operator[](int index)
    {
        if (!((index >= 0 ) && (index < count)))
        {
            throw Exception("Index out of range", INVALID_INPUT);
        }
        return array[index];
    }

    template <class DATA>
    bool Dynamic<DATA>::shouldResize()
    {
        return ((count > 3*size/4) || ((count < size/4) && (size > 4)));
    }

    template <class DATA>
    void Dynamic<DATA>::enlarge()
    {
        size *= 2;
        DATA* new_array = new DATA [size]();
        for(int i = 0; i < count; i++)
        {
            new_array[i] = array[i];
        }
        delete[] array;
        array = new_array;
    }
    template <class DATA>
    void Dynamic<DATA>::shrink()
    {}

} // namespace DS

#endif