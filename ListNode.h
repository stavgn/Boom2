#ifndef LISTNODE_H
#define LISTNODE_H

#include "./Exception.h"

namespace DS
{
    template <class DATA>
    class ListNode
    {

    public:
        ListNode *right = nullptr;
        DATA *data = nullptr;
        ListNode(DATA data, ListNode right);
        ~ListNode()
        {
            delete data;
        };
        link(ListNode list);
    };

} // namespace DS

#endif