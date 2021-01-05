#include "Hash.h"
#include <cassert>

using namespace DS;

Hash::Hash() : Dynamic()
{
}

bool Hash::insert(int key, ListNode<Course> &data)
{
    if (key < 0)
    {
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
                throw Exception("Course already exists", FAILURE);
                return false;
            }
        }
        data.link(list);
    }
    array[key % size].right = &data;
    count++;
    return true;
}

bool Hash::remove(int key)
{
     if (key < 0)
    {
        throw Exception("Index out of range", INVALID_INPUT);
    }
    
    if (array[key % size].right != nullptr)
    {
        return true;
    }
        ListNode<Course> &list = *(array[key % size].right);
        for (ListNode<Course> *iter = &array[key % size]; iter != nullptr; iter = iter->right)
        {
            if ((iter->right != nullptr) && (iter->right->key == key))
            {
                ListNode<Course> *next = iter->right->right;
                delete iter->right;
                iter->right = next;
                count--;
                if(shouldResize())
                {
                    assert((count < size/4));
                    shrink();
                }
                return true;
            }
        }
        return true;
}

Course& Hash::operator[](int index)
{
     if (index < 0)
    {
        throw Exception("Index out of range", INVALID_INPUT);
    }
     if (array[key % size].right == nullptr)
    {
        throw Exception("Course was not found", FAILURE);
    }

        ListNode<Course> &list = *(array[key % size].right);
        for (ListNode<Course> *iter = &list; iter != nullptr; iter = iter->right)
        {
            if (iter->key == key)
            {
                return *(iter->data);
            }
        }
}