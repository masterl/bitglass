#include "class.hpp"

#ifdef __linux__
    #define CLEAR "clear"
#else
    #define CLEAR "cls"
#endif

inline void wait_enter(void)
{
    std::cout << "\nPress enter to continue..." << std::flush;
    while(std::cin.get() != '\n');
}

void Class::add_slide(const std::string &title,action_t action)
{
    ClassSlide slide;

    slide.title = title;
    slide.action = action;

    _slides.push_back(slide);
}

void Class::execute(void)
{
    for(auto const &slide : _slides)
    {
        system(CLEAR);
        std::cout << _subject << std::endl;
        std::cout << slide.title << std::endl;
        slide.action();
        wait_enter();
    }
}