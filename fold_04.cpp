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

// g++ -std=c++17 fold_04.cpp -o fold_04 && ./fold_04
// https://en.cppreference.com/w/cpp/language/fold

// See also:
// https://www.youtube.com/watch?v=XJzs4kC9d-Y
// https://github.com/rollbear/cache_functional_ranges
// https://github.com/rollbear/cache_functional_ranges/blob/main/row_select.cpp


#include <iostream>

struct Thing
{
    int v;
};

int operator+=(int & lhs,
              const Thing & rhs)
{
  std::cout << lhs << " " << rhs.v << "\n";

  lhs += rhs.v;
  return lhs;
}

template<typename ...Args>
int fold_thing(Args && ...args)
{
  // return ( args, ... );

  int rv = 0;

  ( (rv += args), ... );
  //( ..., (rv += args));

  return rv;
}

template<typename ...Args>
int fold_int(Args && ...args)
{
  return ( args, ... );
}

template<typename ...Args>
int fold_int_better(Args && ...args)
{
  int rv = 0;

  ( (rv += args), ... );

  return rv;
}

int main()
{
  std::cout << fold_int(1, 2, 3, 4) << std::endl;
  std::cout << fold_int(1, 2, 3.14, 4) << std::endl;

  // std::cout << std::endl;
  // std::cout << fold_int_better(1, 2, 3, 4) << std::endl;
  // std::cout << fold_int_better(1, 2, 3.14, 4) << std::endl;

  // Thing{1};
  // Thing{2};
  // Thing{3};
  // Thing{4};
  // std::cout << fold_thing(Thing{1}, Thing{2}, Thing{3}, Thing{4}) << std::endl;
}
