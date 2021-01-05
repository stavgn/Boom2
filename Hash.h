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

    public:
        Hash();
        ~Hash();
        bool insert(int key, ListNode<Course> *data);
        bool remove(int key);
        Course &operator[](int index);
        // bool shouldResize() override;
    };

} // namespace DS

#endif