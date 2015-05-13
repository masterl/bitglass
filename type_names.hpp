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

#ifndef TYPE_NAMES_HPP
#define TYPE_NAMES_HPP

#include <algorithm>
#include <string>
#include <typeinfo>
#include <values.h>
#include <vector>
#include <utility>

using namespace std;

template <typename T>
string get_type_name()
{
    string default_name(typeid(T).name());
    static vector<pair<string,string> > default_names{
        {typeid(char).name(),"char"},
        {typeid(short).name(),"short"},
        {typeid(int).name(),"int"},
        {typeid(long).name(),"long"},
        {typeid(long long).name(),"long long"},
        {typeid(float).name(),"float"},
        {typeid(double).name(),"double"},
        {typeid(long double).name(),"long double"}
    };

    auto name_it = find_if(default_names.begin(),default_names.end(), [default_name](auto &names){return names.first == default_name;} );

    if(name_it != default_names.end())
    {
        return name_it->second;
    }

    return default_name;
}

#endif
