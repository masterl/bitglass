#include "class.hpp"

#include <iomanip>

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
        std::cout << _subject << "\n";
        std::cout << std::setw(_info_field_size) << _teacher << "\n";
        std::cout << slide.title << std::endl;
        print_line();

        slide.action();

        wait_enter();
    }
}

void Class::print_line(void)
{
    char prev = std::cout.fill();

    std::cout << std::setw(_info_field_size) << std::setfill('-') << "" << std::setfill(prev) << std::endl;
}
