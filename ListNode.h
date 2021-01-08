#ifndef LISTNODE_H
#define LISTNODE_H

#include "./Exception.h"

namespace DS
{
    template <class DATA>
    class ListNode
    {

    public:
        int key = -1;
        ListNode *right = nullptr;
        DATA *data = nullptr;
        ListNode(){};
        ListNode(int key, DATA &data, ListNode &right = nullptr);
        ~ListNode()
        {
            delete data;
        };
        void link(ListNode &list);
    };

    template <class DATA>
    ListNode<DATA>::ListNode(int key, DATA &data, ListNode &right) : key(key), data(&data), right(&right)
    {
    }

    template <class DATA>
    void ListNode<DATA>::link(ListNode &list)
    {
        right = &list;
    }

} // namespace DS

#endif