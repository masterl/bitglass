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

#include "type_names.hpp"

using namespace std;

template <typename T>
void print_type_size(void)
{
    cout << setw(11) << get_type_name<T>() << " - bytes: " << setw(3) << sizeof(T) << "  bits: " << setw(3) << _TYPEBITS(T) << endl;
}

void print_basic_type_sizes(void)
{
    cout << "\nSome basic types sizes:" << endl;
    print_type_size<char>();
    print_type_size<short>();
    print_type_size<int>();
    print_type_size<long>();
    print_type_size<long long>();
    print_type_size<float>();
    print_type_size<double>();
    print_type_size<long double>();
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

int main(void)
{
    print_basic_type_sizes();

    test_bits<char>();
    test_bits<short>();
    test_bits<int>();
    test_bits<long>();
    test_bits<long long>();
    test_bits<float>();
    test_bits<double>();


    return 0;
}