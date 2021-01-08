#include "./Course.h"
#include "./Dynamic.h"
#include "Exception.h"

using namespace DS;

Course::Course(int id) : id(id), classes(Dynamic<int>())
{
    if (id < 0)
    {
        throw Exception("Invalid CourseId", INVALID_INPUT);
    }
}

int Course::appendNewClass()
{
    int count = classes.push();
    return count;
}
int Course::getWatchTime(int classId)
{
    return classes[classId];
}

bool Course::watchClass(int classId, int watchTime)
{
    if (classId < 0 || watchTime <= 0)
    {
        throw Exception("Invalid CourseId", INVALID_INPUT);
    }
    classes[classId] += watchTime;
    return true;
}