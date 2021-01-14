#include "./Exception.h"

using namespace DS;
using namespace std;

Exception::Exception(StatusType type) 
{
    type_data = type;
}


StatusType Exception::type()
{
    return type_data;
}