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

// g++ -std=c++17 fold_00.cpp -o fold_00 && ./fold_00
// https://en.cppreference.com/w/cpp/utility/variadic/va_start

#include <cstdarg>
#include <cstring>
#include <iostream>

int not_folding(int count...)
{
  std::va_list args;
  int result = 0;

  va_start(args, count);

  for (int i = 0; i < count; ++i)
  {
    int v = va_arg(args, int);
    result += v;
    std::cout << std::hex << v << " " << result << std::endl;
  }

  va_end(args);

  return result;
}

int main()
{
  std::cout << not_folding(4, 1, 2, 3, 4) << '\n';
  // std::cout << '\n';
  // std::cout << add_nums(10, 1, 2, 3, 4) << '\n';
  // std::cout << '\n';
  // std::cout << add_nums(4, 1, double(2.0), 3, 4) << '\n';
}
