#ifndef HASH_H
#define HASH_H

#include "./Exception.h"
#include "./Dynamic.h"
#include "./ListNode.h"
#include "./Course.h"

namespace DS
{
    class Hash : public Dynamic<ListNode<Course>>
    {

    private:
        void shrink();
        void enlarge();
        void change_size(double factor);

    public:
        Hash();
        ~Hash();
        void insert(int key, ListNode<Course>& data);
        void remove(int key);
        Course &operator[](int index);
    };

} // namespace DS

#endif