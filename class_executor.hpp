#ifndef CLASS_EXECUTOR_H
#define CLASS_EXECUTOR_H

#include <iostream>
#include <vector>

#include "class_slide.hpp"

inline void wait_enter(void)
{
    std::cout << "\nPress enter to continue..." << std::flush;
    while(std::cin.get() != '\n');
}

class ClassExecutor
{
    public:
        ClassExecutor(const std::string &subject):
            _subject(subject)
        {}
        void add_slide(const std::string &title,action_t action)
        {
            ClassSlide slide;

            slide.title = title;
            slide.action = action;

            _slides.push_back(slide);
        }
        void execute(void)
        {
            for(auto const &slide : _slides)
            {
                system("clear");
                cout << slide.title << endl;
                slide.action();
                wait_enter();
            }
        }
    private:
        const std::string _subject;
        std::vector<ClassSlide> _slides;
};

#endif
