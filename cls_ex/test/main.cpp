/////////////////////////////////////////////////////////////////////////////////
// The MIT License(MIT)
//
// Copyright (c) 2016 Tiangang Song
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files(the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <future>
#include <boost/container/small_vector.hpp>
#include <cls_ex/deque_x.h>
#include <cls_ex/deque.h>

struct Foo {
    int b = 4;
};

using Subarray = cls::detail::SubarrayT<Foo, 4, cls::Allocator>;

int main(int argc, char* argv[])
{
//    cls::Deque<int> d;
//    std::cout << d.size() << std::endl;
//
//    for (auto i = 0; i < 1e5; ++i) {
//        d.emplace_back(i);
//    }

    boost::container::small_vector<std::future<void>, 8> tasks;
    for (int i = 0; i < 1; ++i) {
        tasks.emplace_back(std::async(std::launch::async, [](){
            std::vector<std::unique_ptr<Subarray>> m_ptr_array;
            m_ptr_array.resize(2);
            for (auto& elem : m_ptr_array) {
                elem = std::make_unique<Subarray>();
                elem->construct(0);
                elem->destruct(0);
            }
        }));
    }
    for (auto& elem : tasks) {
        elem.get();
    }

    return 0;
}