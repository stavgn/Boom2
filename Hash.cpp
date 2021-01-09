#include "Hash.h"
#include <cassert>

using namespace DS;

Hash::Hash() : Dynamic()
{
}
Hash::~Hash()
{
    for (int i = 0; i < size; i++)
    {
        ListNode<Course> *tmp_next;
        for(ListNode<Course> *iter = array[i].right; iter != nullptr; iter=tmp_next)
        {
            tmp_next = iter->right;
            delete iter;
        }
    }
}

void Hash::insert(int key, ListNode<Course> &data)
{
    if (key < 0)
    {
        delete &data;
        throw Exception("Index out of range", INVALID_INPUT);
    }
    if (shouldResize())
    {
        assert((count > size / 2));
        enlarge();
    }
    if (array[key % size].right != nullptr)
    {
        ListNode<Course> &list = *(array[key % size].right);
        for (ListNode<Course> *iter = &list; iter != nullptr; iter = iter->right)
        {
            if (iter->key == key)
            {
                delete &data;
                throw Exception("Course already exists", FAILURE);
            }
        }
        data.link(list);
    }
    array[key % size].right = &data;
    count++;
}

void Hash::remove(int key)
{
    if (key < 0)
    {
        throw Exception("Index out of range", INVALID_INPUT);
    }

    if (array[key % size].right == nullptr)
    {
        return;
    }
    for (ListNode<Course> *iter = &array[key % size]; iter != nullptr; iter = iter->right)
    {
        if ((iter->right != nullptr) && (iter->right->key == key))
        {
            ListNode<Course> *next = iter->right->right;
            delete iter->right;
            iter->right = next;
            count--;
            if (shouldResize())
            {
                assert((count < size / 4));
                shrink();
            }
            return;
        }
    }
}

Course &Hash::operator[](int index)
{
    if (index < 0)
    {
        throw Exception("Index out of range", INVALID_INPUT);
    }

    for (ListNode<Course> *iter = array[index % size].right; iter != nullptr; iter = iter->right)
    {
        if (iter->key == index)
        {
            return *(iter->data);
        }
    }
    // course was'nt found
    throw Exception("Course was not found", FAILURE);
}

void Hash::shrink()
{
    double growth_factor = 0.5;
   change_size(growth_factor);
}

void Hash::enlarge()
{
    double growth_factor = 2;
   change_size(growth_factor);
}

void Hash::change_size(double factor)
{
    int new_size = size * factor;
    ListNode<Course> *new_array = new ListNode<Course>[new_size]();
    for (int i = 0; i < size; i++)
    {
        ListNode<Course> *tmp_next;
        for(ListNode<Course> *iter = array[i].right; iter != nullptr; iter=tmp_next)
        {
            tmp_next = iter->right;
            iter->right = new_array[iter->key % new_size].right;
            new_array[iter->key % new_size].right = iter;
        }
    }
    delete[] array;
    array = new_array;
    size = new_size;
}