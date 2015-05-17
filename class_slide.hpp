#ifndef CLASS_SLIDE_H
#define CLASS_SLIDE_H

#include <string>
#include <functional>

typedef std::function<void(void)> action_t;

struct ClassSlide
{
    std::string title;
    action_t    action;
};

#endif
