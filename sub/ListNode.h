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
        ListNode(int key, DATA* data);
        ~ListNode()
        {
            delete data;
        };
        void link(ListNode &list);
    };

    template <class DATA>
    ListNode<DATA>::ListNode(int key, DATA* data) 
    {
        this->key = key;
        this->data = data;
    }

    template <class DATA>
    void ListNode<DATA>::link(ListNode &list)
    {
        right = &list;
    }

} // namespace DS

#endif