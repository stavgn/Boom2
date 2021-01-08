#include "./Boom.h"
#include "./Vector.h"
#include "./ListNode.h"
#include "./ClassDataVector.h"
#include "./tree_node.h"
#include "./Exception.h"

using namespace DS;

Boom::Boom() : classes(Tree<ClassData, ClassData>()), courses(Hash())
{
}

StatusType Boom::AddCourse(int courseID)
{

    if (courses[courseID] == nullptr)
    {
        Course course = Course(courseID);
        courses.insert(courseID, &LinkNode(course));
    }
    else
    {
        throw Exception("invalid courseId", FAILURE);
    }

    return SUCCESS;
}

StatusType Boom::RemoveCourse(int courseID)
{
    if (courses[courseID] == nullptr)
    {
        throw Exception("Course was not found", FAILURE);
    }
    Dynamic<int> &c = courses[courseID].classes;
    for (int i = 0; i < c.size; i++)
    {
        if (c[i] != 0)
        {
            ClassData key = ClassData(courseID, i, c[i]);
            classes.remove(key);
        }
    }
    courses.remove(courseID);
    return SUCCESS;
}

StatusType Boom::WatchClass(int courseID, int classID, int time)
{
    if (courses[courseID] != nullptr)
    {
        Course &c = courses[courseID];
        ClassData prev_record = ClassData(courseID, classID, c.getWatchTime(classID));
        ClassData *next_record_key = new ClassData(courseID, classID, c.getWatchTime(classID) + time);
        c.watchClass(classID, time);
        classes.remove(prev_record);
        classes.insert(*next_record_key, next_record_key);
    }
    else
    {
        throw Exception("course wasn't found", FAILURE);
    }

    return SUCCESS;
}

StatusType Boom::TimeViewed(int courseID, int classID, int *timeViewed)
{
    if (courses[courseID] != nullptr)
    {
        throw Exception("course was'nt found", FAILURE);
    }
    Course &c = courses[courseID];
    *timeViewed = c.getWatchTime(classID); //Todo MAke sure INVALID_INPUT Ex
    return SUCCESS;
}

StatusType Boom::GetIthWatchedClass(int i, int *courseID, int *classID)
{
    return SUCCESS;
}