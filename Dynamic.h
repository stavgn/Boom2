#ifndef DYNAMIC_H
#define DYNAMIC_H

#include "./Exception.h"
 
namespace DS
{
    template <class DATA>
    class Dynamic
    {
    private:
        shrink();
        enlarge();
    public:
        int size;
        int count
        DATA* array;

        Dynamic();
        ~Dynamic();
        int push();
        bool &operator[](int);
        bool shouldResize()

        
    };

} // namespace DS

#endif