#include "./library2.h"
#include "./Boom.h"

using namespace DS;

void *Init()
{
    return ((void *)new Boom());
}

StatusType AddCourse(void *DS, int courseID)
{

    if (DS == nullptr || courseID <= 0)
    {
        return INVALID_INPUT;
    }
    try
    {
        Boom *boom = static_cast<Boom *>(DS);
        if (boom == NULL)
        {
            return INVALID_INPUT;
        }
        return boom->AddCourse(courseID);
    }
    catch (Exception &e)
    {
        return e.type();
    }
    catch (std::bad_alloc &ba)
    {
        return ALLOCATION_ERROR;
    }
}

StatusType RemoveCourse(void *DS, int courseID)
{
    if (DS == nullptr || courseID <= 0)
    {
        return INVALID_INPUT;
    }
    try
    {
        Boom *boom = static_cast<Boom *>(DS);
        if (boom == NULL)
        {
            return INVALID_INPUT;
        }
        return boom->RemoveCourse(courseID);
    }
    catch (Exception &e)
    {
        return e.type();
    }
    catch (std::bad_alloc &ba)
    {
        return ALLOCATION_ERROR;
    }
}

StatusType AddClass(void *DS, int courseID, int *classID)
{
    if (DS == nullptr || courseID <= 0 || classID < 0)
    {
        return INVALID_INPUT;
    }
    try
    {
        Boom *boom = static_cast<Boom *>(DS);
        if (boom == NULL)
        {
            return INVALID_INPUT;
        }
        //return boom->WatchClass(courseID, classID, time);
    }
    catch (Exception &e)
    {
        return e.type();
    }
    catch (std::bad_alloc &ba)
    {
        return ALLOCATION_ERROR;
    }
}

StatusType WatchClass(void *DS, int courseID, int classID, int time)
{
    if (DS == nullptr || courseID <= 0 || classID < 0 || time <= 0)
    {
        return INVALID_INPUT;
    }
    try
    {
        Boom *boom = static_cast<Boom *>(DS);
        if (boom == NULL)
        {
            return INVALID_INPUT;
        }
        return boom->WatchClass(courseID, classID, time);
    }
    catch (Exception &e)
    {
        return e.type();
    }
    catch (std::bad_alloc &ba)
    {
        return ALLOCATION_ERROR;
    }
}
StatusType TimeViewed(void *DS, int courseID, int classID, int *timeViewed)
{
    if (DS == nullptr || courseID <= 0 || classID < 0)
    {
        return INVALID_INPUT;
    }
    try
    {
        Boom *boom = static_cast<Boom *>(DS);
        if (boom == NULL)
        {
            return INVALID_INPUT;
        }
        return boom->TimeViewed(courseID, classID, timeViewed);
    }
    catch (Exception &e)
    {
        return e.type();
    }
    catch (std::bad_alloc &ba)
    {
        return ALLOCATION_ERROR;
    }
}

StatusType GetIthWatchedClass(void *DS, int i, int *courseID, int *classID)
{
    if (DS == nullptr || i < 0)
    {
        return INVALID_INPUT;
    }
    try
    {
        Boom *boom = static_cast<Boom *>(DS);
        if (boom == NULL)
        {
            return INVALID_INPUT;
        }
        // return boom->GetMostViewedClasses(numOfClasses, courses, classes);
    }
    catch (Exception &e)
    {
        return e.type();
    }
    catch (std::bad_alloc &ba)
    {
        return ALLOCATION_ERROR;
    }
}

void Quit(void **DS)
{
    Boom **boom = (Boom **)(DS);
    delete *boom;
    *boom = nullptr;
}
