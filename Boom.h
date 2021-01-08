#ifndef BOOM_H
#define BOOM_H

#include "./Tree.h"
#include "./Vector.h"
#include "./Hash.h"
#include "./ListNode.h"
#include "./Course.h"
#include "./ClassDataVector.h"
#include "./Exception.h"

namespace DS
{
    class Boom
    {
        Tree<ClassData, ClassData> classes;
        Hash courses;

    public:
        Boom();
        ~Boom() = default;
        StatusType AddCourse(int courseID);
        StatusType AddClass(int courseID);
        StatusType RemoveCourse(int courseID);
        StatusType WatchClass(int courseID, int classID, int time);
        StatusType TimeViewed(int courseID, int classID, int *timeViewed);
        StatusType GetIthWatchedClass(int i, int *courseID, int *classID);
    };

} // namespace DS

#endif