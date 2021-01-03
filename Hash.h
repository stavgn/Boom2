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
        shrink();
        enlarge();

    public:
        Hash();
        ~Hash();
        bool insert(int key, ListNode<Course> *data) override;
        bool remove(int key) override;
        bool shouldResize() override;
    };

} // namespace DS

#endif