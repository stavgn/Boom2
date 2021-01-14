
#ifndef EXECPTION_H
#define EXECPTION_H


#include "library2.h"



namespace DS
{

    class Exception : public std::exception
    {

    public:
        StatusType type_data;
        Exception(StatusType type);
        ~Exception() = default;
        StatusType type();
    };

} // namespace DS

#endif