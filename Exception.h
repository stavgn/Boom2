
#ifndef EXECPTION_H
#define EXECPTION_H

#include <set>
#include <memory>
#include <string>
#include "library2.h"



namespace DS
{

    class Exception : public std::exception
    {

    public:
        std::string desc;
        StatusType type_data;
        Exception(std::string desc, StatusType type);
        ~Exception() = default;
        std::string what();
        StatusType type();
    };

} // namespace DS

#endif