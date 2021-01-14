#ifndef COURSE_H
#define COURSE_H

#include "./Exception.h"
#include "./Dynamic.h"
 
namespace DS
{
    class Course
    {
        

    public:
        Dynamic<int> classes;
        int id;
        Course(int id);
        ~Course() = default;
        Course(const Course& source) = default;
        int appendNewClass();
        int getWatchTime(int classId);
        bool watchClass(int classId, int watchTime);

    };

} // namespace DS

#endif