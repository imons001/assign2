#include <utility>
#include <algorithm>
#include <numeric>

#include "Schedule.h"

using namespace std::rel_ops;

//------------------------------------------------------------------------------
/**
 * @todo sanity check - is this function complete?
 */
Schedule::Schedule()
{
}

//------------------------------------------------------------------------------
/**
 * @todo implement this method.
 */
int Schedule::getCredits() const
{
    //Use the accumulate function to go through the allCourses vector and add up all the credits from the schedule
    int totalCredits = std::accumulate(allCourses.begin(), allCourses.end(), 0,
                                       [](int t, const Course& cr) -> int
                                       {
                                           return t + cr.getCredits();
                                       });
    //return the total credits from the schedule
    return totalCredits;
}

//------------------------------------------------------------------------------
/**
 * @todo implement this function
 */
void Schedule::appendNoCheck(Course course)
{
    //Add the new course to the schedule
    allCourses.push_back(course);
}

//------------------------------------------------------------------------------
/**
 * @todo implement this function
 */
bool Schedule::wouldViolateCreditLimit(Course course) const
{
    //check if adding the new course with exceed the schedule credit limit
    if (course.getCredits() + getCredits() > CREDIT_LIMIT) {
        //return true if the course would exceed the credit limit
        return true;
    }
    //return false if the course can be added
    return false;
}

//------------------------------------------------------------------------------
/**
 * @todo implement this function
 */
bool Schedule::alreadyInSchedule(Course course) const
{
    //check if the course being added is already in the schedule or if the course being added is the same as another then return true
    const_iterator it = this->begin();
    while (it != this->end()){
        if (course.getNumber() == it->getNumber()) {
            return true;
        }
        it++;
    }
    //if course is not already in the schedule then return false
    return false;
}

//------------------------------------------------------------------------------
/**
 * @todo implement this function
 */
void Schedule::display(std::ostream& outs) const
{
    //display the schedule for the student
    const_iterator it = this->begin();
    while (it != this->end())
    {
        outs << "  - " << *it << "\n";
        it++;
    }
    outs << "  (" << getCredits() << " Total Credits)" << "\n";
}
