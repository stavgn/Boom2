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

    Course* course = new Course(courseID);
    ListNode<Course>* l(new ListNode<Course>(courseID, course));
    courses.insert(courseID, *l);

    return SUCCESS;
}
StatusType Boom::AddClass(int courseID, int* classID)
{
    Dynamic<int> &c = courses[courseID].classes;
    *classID = c.push();
    return SUCCESS;
}

StatusType Boom::RemoveCourse(int courseID)
{
    Dynamic<int> &c = courses[courseID].classes;
    for (int i = 0; i < c.count; i++)
    {
        if (c[i] != 0)
        {
            ClassData key = ClassData(courseID, i, int(c[i]));
            classes.remove(key);
        }
    }
    courses.remove(courseID);
    return SUCCESS;
}

StatusType Boom::WatchClass(int courseID, int classID, int time)
{
    Course &c = courses[courseID];
    ClassData prev_record = ClassData(courseID, classID, int(c.getWatchTime(classID)));
    ClassData next_record_key =  ClassData(courseID, classID, int(c.getWatchTime(classID) + time));
    c.watchClass(classID, time);
    classes.remove(prev_record);
    classes.insert(next_record_key, nullptr);
    return SUCCESS;
}

StatusType Boom::TimeViewed(int courseID, int classID, int *timeViewed)
{
    Course &c = courses[courseID];
    *timeViewed = c.getWatchTime(classID);
    return SUCCESS;
}

StatusType Boom::GetIthWatchedClass(int i, int *courseID, int *classID)
{
    tree_node<ClassData, ClassData> *node = classes.select_rank(i);
    ClassData data = node->key;
    *courseID = data[0];
    *classID = data[1];

    return SUCCESS;
}