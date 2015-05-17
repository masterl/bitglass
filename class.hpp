#ifndef CLASS_H
#define CLASS_H

#include <iostream>
#include <vector>

#include "class_slide.hpp"

class Class
{
    public:
        Class(const std::string &subject):
            _subject(subject)
        {}
        void add_slide(const std::string &title,action_t action);
        void execute(void);
    private:
        const std::string _subject;
        std::vector<ClassSlide> _slides;
};

#endif
