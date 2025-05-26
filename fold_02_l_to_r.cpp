/*

  MIT License

  Copyright (c) 2025 Yafiyogi

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.

*/

// g++ -std=c++17 fold_02_l_to_r.cpp -o fold_02 && ./fold_02
// https://en.cppreference.com/w/cpp/language/fold

#include <iostream>

struct Thing
{
    int v;
};

Thing operator+(const Thing & lhs,
                const Thing & rhs)
{
  std::cout << lhs.v << " " << rhs.v << "\n";
  Thing rv{lhs.v + rhs.v};

  return rv;
}


template<typename ...Args>
Thing fold_thing(Args && ...args)
{
  return ( args + ... );
}

int main()
{
  // (Thing{1} + (Thing{2} + (Thing{3} + Thing{4})))

  std::cout << fold_thing(Thing{1}, Thing{2}, Thing{3}, Thing{4}).v << std::endl;
}
