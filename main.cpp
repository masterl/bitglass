// The MIT License (MIT)

// Copyright (c) 2015 Leonardo de Oliveira Lourenço

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <iostream>
#include <bitset>
#include <string>
#include <typeinfo>
#include <iomanip>
#include <limits>

#include "type_names.hpp"
#include "class.hpp"

using namespace std;



template <typename T>
void print_type_size(void)
{
    cout << setw(25) << get_type_name<T>() << " - bytes: " << setw(4) << sizeof(T) << "  bits: " << setw(5) << _TYPEBITS(T) << endl;
}

template <typename T>
string get_bits(T const &value)
{
    std::bitset<_TYPEBITS(T)> bits_str( *reinterpret_cast<unsigned long long const *>(&value) );

    return bits_str.to_string();
}

template <typename T>
void test_bits(void)
{
    T value;
    cout << "\nInput an " << get_type_name<T>() << ": ";
    cin >> value;
    cout << "Bits: " << get_bits(value) << endl;
}

template <typename T>
void test_number_bits_on_range(void)
{
    T const start = numeric_limits<T>::min();
    T const end = numeric_limits<T>::max();
    T previous = start;
    T auto_step = end/7 - start/7;
    for(T value = start; value < end; value += auto_step)
    {
        if((previous > 0) && (value < 0))
        {
            break;
        }

        cout << "Number: " << value << "\n"
             << "  Bits: " << get_bits(value) << "\n";

        previous = value;
    }
}

int main(void)
{
    Class basic_types_class("Basic types","Leonardo de Oliveira Lourenço");

    basic_types_class.add_slide("Sizes - bits and bytes",[] {
        print_type_size<char>();
        print_type_size<short>();
        print_type_size<int>();
        print_type_size<long>();
        print_type_size<long long>();
        print_type_size<float>();
        print_type_size<double>();
        print_type_size<long double>();
        print_type_size<void *>();
    });

    basic_types_class.add_slide("Character examples",[]{
        unsigned char character;
        bool jump_line = true;

        for(character = ' '; character <= '}'; character += 3)
        {
            jump_line = !jump_line;
            cout << "[" << character << "] -> ASCII: " << setw(3) << (int)character << " -> Bits: " << get_bits(character);
            if(jump_line)
            {
                cout << '\n';
            }
            else
            {
                cout << "    ";
            }
        }
        cout << endl;
    });

    basic_types_class.add_slide("short examples",[]{
        test_number_bits_on_range<short>();
    });

    basic_types_class.add_slide("int examples",[]{
        test_number_bits_on_range<int>();
    });

    basic_types_class.add_slide("long examples",[]{
        test_number_bits_on_range<long>();
    });

    basic_types_class.add_slide("long long examples",[]{
        test_number_bits_on_range<long long>();
    });

    basic_types_class.add_slide("float examples",[]{
        test_number_bits_on_range<float>();
    });

    basic_types_class.add_slide("double examples",[]{
        test_number_bits_on_range<double>();
    });

    basic_types_class.execute();

    // test_bits<short>();
    // test_bits<int>();
    // test_bits<long>();
    // test_bits<long long>();
    // test_bits<float>();
    // test_bits<double>();


    return 0;
}