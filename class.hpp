#ifndef CLASS_H
#define CLASS_H

#include <iostream>
#include <vector>

#include "class_slide.hpp"

class Class
{
    public:
        Class(const std::string &subject,const std::string &teacher,unsigned int info_field_size = 80):
            _subject(subject),
            _teacher(teacher),
            _info_field_size(info_field_size)
        {}
        void add_slide(const std::string &title,action_t action);
        void execute(void);
    private:
        const std::string _subject;
        const std::string _teacher;
        unsigned int _info_field_size;
        std::vector<ClassSlide> _slides;

        void print_line(void);
};

#endif
