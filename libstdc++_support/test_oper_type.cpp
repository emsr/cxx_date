// The MIT License (MIT)
//
// Copyright (c) 2015, 2016 Howard Hinnant
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <chrono.h>

#include <type_traits>

template<typename I, typename J, typename K>
  constexpr auto
  test(I i, J j, K k) -> decltype(i/j/k)
  {
      return i/j/k;
  }

void
test(...)
{
}

int
main()
{
  using std::is_same;
  using namespace std::chrono;

  static_assert(is_same<decltype(test(        1,         1,         1)), int>{});
  static_assert(is_same<decltype(test(        1,         1,       1d)), month_day>{});
  static_assert(is_same<decltype(test(        1,         1,       January)), void>{});
  static_assert(is_same<decltype(test(        1,         1,       1y)), void>{});
  static_assert(is_same<decltype(test(        1,         1,      last)), month_day_last>{});
  static_assert(is_same<decltype(test(        1,         1,    Sunday[1])), month_weekday>{});
  static_assert(is_same<decltype(test(        1,         1, Sunday[last])), month_weekday_last>{});

  static_assert(is_same<decltype(test(        1,       1d,         1)), year_month_day>{});
  static_assert(is_same<decltype(test(        1,       1d,       1d)), void>{});
  static_assert(is_same<decltype(test(        1,       1d,       January)), void>{});
  static_assert(is_same<decltype(test(        1,       1d,       1y)), year_month_day>{});
  static_assert(is_same<decltype(test(        1,       1d,      last)), void>{});
  static_assert(is_same<decltype(test(        1,       1d,    Sunday[1])), void>{});
  static_assert(is_same<decltype(test(        1,       1d, Sunday[last])), void>{});

  static_assert(is_same<decltype(test(        1,       January,         1)), void>{});
  static_assert(is_same<decltype(test(        1,       January,       1d)), void>{});
  static_assert(is_same<decltype(test(        1,       January,       January)), void>{});
  static_assert(is_same<decltype(test(        1,       January,       1y)), void>{});
  static_assert(is_same<decltype(test(        1,       January,      last)), void>{});
  static_assert(is_same<decltype(test(        1,       January,    Sunday[1])), void>{});
  static_assert(is_same<decltype(test(        1,       January, Sunday[last])), void>{});

  static_assert(is_same<decltype(test(        1,       1y,         1)), void>{});
  static_assert(is_same<decltype(test(        1,       1y,       1d)), void>{});
  static_assert(is_same<decltype(test(        1,       1y,       January)), void>{});
  static_assert(is_same<decltype(test(        1,       1y,       1y)), void>{});
  static_assert(is_same<decltype(test(        1,       1y,      last)), void>{});
  static_assert(is_same<decltype(test(        1,       1y,    Sunday[1])), void>{});
  static_assert(is_same<decltype(test(        1,       1y, Sunday[last])), void>{});

  static_assert(is_same<decltype(test(        1,      last,         1)), year_month_day_last>{});
  static_assert(is_same<decltype(test(        1,      last,       1d)), void>{});
  static_assert(is_same<decltype(test(        1,      last,       January)), void>{});
  static_assert(is_same<decltype(test(        1,      last,       1y)), year_month_day_last>{});
  static_assert(is_same<decltype(test(        1,      last,      last)), void>{});
  static_assert(is_same<decltype(test(        1,      last,    Sunday[1])), void>{});
  static_assert(is_same<decltype(test(        1,      last, Sunday[last])), void>{});

  static_assert(is_same<decltype(test(        1,    Sunday[1],         1)), year_month_weekday>{});
  static_assert(is_same<decltype(test(        1,    Sunday[1],       1d)), void>{});
  static_assert(is_same<decltype(test(        1,    Sunday[1],       January)), void>{});
  static_assert(is_same<decltype(test(        1,    Sunday[1],       1y)), year_month_weekday>{});
  static_assert(is_same<decltype(test(        1,    Sunday[1],      last)), void>{});
  static_assert(is_same<decltype(test(        1,    Sunday[1],    Sunday[1])), void>{});
  static_assert(is_same<decltype(test(        1,    Sunday[1], Sunday[last])), void>{});

  static_assert(is_same<decltype(test(        1, Sunday[last],         1)), year_month_weekday_last>{});
  static_assert(is_same<decltype(test(        1, Sunday[last],       1d)), void>{});
  static_assert(is_same<decltype(test(        1, Sunday[last],       January)), void>{});
  static_assert(is_same<decltype(test(        1, Sunday[last],       1y)), year_month_weekday_last>{});
  static_assert(is_same<decltype(test(        1, Sunday[last],      last)), void>{});
  static_assert(is_same<decltype(test(        1, Sunday[last],    Sunday[1])), void>{});
  static_assert(is_same<decltype(test(        1, Sunday[last], Sunday[last])), void>{});

  static_assert(is_same<decltype(test(      1d,         1,         1)), year_month_day>{});
  static_assert(is_same<decltype(test(      1d,         1,       1d)), void>{});
  static_assert(is_same<decltype(test(      1d,         1,       January)), void>{});
  static_assert(is_same<decltype(test(      1d,         1,       1y)), year_month_day>{});
  static_assert(is_same<decltype(test(      1d,         1,      last)), void>{});
  static_assert(is_same<decltype(test(      1d,         1,    Sunday[1])), void>{});
  static_assert(is_same<decltype(test(      1d,         1, Sunday[last])), void>{});

  static_assert(is_same<decltype(test(      1d,       1d,         1)), void>{});
  static_assert(is_same<decltype(test(      1d,       1d,       1d)), void>{});
  static_assert(is_same<decltype(test(      1d,       1d,       January)), void>{});
  static_assert(is_same<decltype(test(      1d,       1d,       1y)), void>{});
  static_assert(is_same<decltype(test(      1d,       1d,      last)), void>{});
  static_assert(is_same<decltype(test(      1d,       1d,    Sunday[1])), void>{});
  static_assert(is_same<decltype(test(      1d,       1d, Sunday[last])), void>{});

  static_assert(is_same<decltype(test(      1d,       January,         1)), year_month_day>{});
  static_assert(is_same<decltype(test(      1d,       January,       1d)), void>{});
  static_assert(is_same<decltype(test(      1d,       January,       January)), void>{});
  static_assert(is_same<decltype(test(      1d,       January,       1y)), year_month_day>{});
  static_assert(is_same<decltype(test(      1d,       January,      last)), void>{});
  static_assert(is_same<decltype(test(      1d,       January,    Sunday[1])), void>{});
  static_assert(is_same<decltype(test(      1d,       January, Sunday[last])), void>{});

  static_assert(is_same<decltype(test(      1d,       1y,         1)), void>{});
  static_assert(is_same<decltype(test(      1d,       1y,       1d)), void>{});
  static_assert(is_same<decltype(test(      1d,       1y,       January)), void>{});
  static_assert(is_same<decltype(test(      1d,       1y,       1y)), void>{});
  static_assert(is_same<decltype(test(      1d,       1y,      last)), void>{});
  static_assert(is_same<decltype(test(      1d,       1y,    Sunday[1])), void>{});
  static_assert(is_same<decltype(test(      1d,       1y, Sunday[last])), void>{});

  static_assert(is_same<decltype(test(      1d,      last,         1)), void>{});
  static_assert(is_same<decltype(test(      1d,      last,       1d)), void>{});
  static_assert(is_same<decltype(test(      1d,      last,       January)), void>{});
  static_assert(is_same<decltype(test(      1d,      last,       1y)), void>{});
  static_assert(is_same<decltype(test(      1d,      last,      last)), void>{});
  static_assert(is_same<decltype(test(      1d,      last,    Sunday[1])), void>{});
  static_assert(is_same<decltype(test(      1d,      last, Sunday[last])), void>{});

  static_assert(is_same<decltype(test(      1d,    Sunday[1],         1)), void>{});
  static_assert(is_same<decltype(test(      1d,    Sunday[1],       1d)), void>{});
  static_assert(is_same<decltype(test(      1d,    Sunday[1],       January)), void>{});
  static_assert(is_same<decltype(test(      1d,    Sunday[1],       1y)), void>{});
  static_assert(is_same<decltype(test(      1d,    Sunday[1],      last)), void>{});
  static_assert(is_same<decltype(test(      1d,    Sunday[1],    Sunday[1])), void>{});
  static_assert(is_same<decltype(test(      1d,    Sunday[1], Sunday[last])), void>{});

  static_assert(is_same<decltype(test(      1d, Sunday[last],         1)), void>{});
  static_assert(is_same<decltype(test(      1d, Sunday[last],       1d)), void>{});
  static_assert(is_same<decltype(test(      1d, Sunday[last],       January)), void>{});
  static_assert(is_same<decltype(test(      1d, Sunday[last],       1y)), void>{});
  static_assert(is_same<decltype(test(      1d, Sunday[last],      last)), void>{});
  static_assert(is_same<decltype(test(      1d, Sunday[last],    Sunday[1])), void>{});
  static_assert(is_same<decltype(test(      1d, Sunday[last], Sunday[last])), void>{});

  static_assert(is_same<decltype(test(      January,         1,         1)), year_month_day>{});
  static_assert(is_same<decltype(test(      January,         1,       1d)), void>{});
  static_assert(is_same<decltype(test(      January,         1,       January)), void>{});
  static_assert(is_same<decltype(test(      January,         1,       1y)), year_month_day>{});
  static_assert(is_same<decltype(test(      January,         1,      last)), void>{});
  static_assert(is_same<decltype(test(      January,         1,    Sunday[1])), void>{});
  static_assert(is_same<decltype(test(      January,         1, Sunday[last])), void>{});

  static_assert(is_same<decltype(test(      January,       1d,         1)), year_month_day>{});
  static_assert(is_same<decltype(test(      January,       1d,       1d)), void>{});
  static_assert(is_same<decltype(test(      January,       1d,       January)), void>{});
  static_assert(is_same<decltype(test(      January,       1d,       1y)), year_month_day>{});
  static_assert(is_same<decltype(test(      January,       1d,      last)), void>{});
  static_assert(is_same<decltype(test(      January,       1d,    Sunday[1])), void>{});
  static_assert(is_same<decltype(test(      January,       1d, Sunday[last])), void>{});

  static_assert(is_same<decltype(test(      January,       January,         1)), void>{});
  static_assert(is_same<decltype(test(      January,       January,       1d)), void>{});
  static_assert(is_same<decltype(test(      January,       January,       January)), void>{});
  static_assert(is_same<decltype(test(      January,       January,       1y)), void>{});
  static_assert(is_same<decltype(test(      January,       January,      last)), void>{});
  static_assert(is_same<decltype(test(      January,       January,    Sunday[1])), void>{});
  static_assert(is_same<decltype(test(      January,       January, Sunday[last])), void>{});

  static_assert(is_same<decltype(test(      January,       1y,         1)), void>{});
  static_assert(is_same<decltype(test(      January,       1y,       1d)), void>{});
  static_assert(is_same<decltype(test(      January,       1y,       January)), void>{});
  static_assert(is_same<decltype(test(      January,       1y,       1y)), void>{});
  static_assert(is_same<decltype(test(      January,       1y,      last)), void>{});
  static_assert(is_same<decltype(test(      January,       1y,    Sunday[1])), void>{});
  static_assert(is_same<decltype(test(      January,       1y, Sunday[last])), void>{});

  static_assert(is_same<decltype(test(      January,      last,         1)), year_month_day_last>{});
  static_assert(is_same<decltype(test(      January,      last,       1d)), void>{});
  static_assert(is_same<decltype(test(      January,      last,       January)), void>{});
  static_assert(is_same<decltype(test(      January,      last,       1y)), year_month_day_last>{});
  static_assert(is_same<decltype(test(      January,      last,      last)), void>{});
  static_assert(is_same<decltype(test(      January,      last,    Sunday[1])), void>{});
  static_assert(is_same<decltype(test(      January,      last, Sunday[last])), void>{});

  static_assert(is_same<decltype(test(      January,    Sunday[1],         1)), year_month_weekday>{});
  static_assert(is_same<decltype(test(      January,    Sunday[1],       1d)), void>{});
  static_assert(is_same<decltype(test(      January,    Sunday[1],       January)), void>{});
  static_assert(is_same<decltype(test(      January,    Sunday[1],       1y)), year_month_weekday>{});
  static_assert(is_same<decltype(test(      January,    Sunday[1],      last)), void>{});
  static_assert(is_same<decltype(test(      January,    Sunday[1],    Sunday[1])), void>{});
  static_assert(is_same<decltype(test(      January,    Sunday[1], Sunday[last])), void>{});

  static_assert(is_same<decltype(test(      January, Sunday[last],         1)), year_month_weekday_last>{});
  static_assert(is_same<decltype(test(      January, Sunday[last],       1d)), void>{});
  static_assert(is_same<decltype(test(      January, Sunday[last],       January)), void>{});
  static_assert(is_same<decltype(test(      January, Sunday[last],       1y)), year_month_weekday_last>{});
  static_assert(is_same<decltype(test(      January, Sunday[last],      last)), void>{});
  static_assert(is_same<decltype(test(      January, Sunday[last],    Sunday[1])), void>{});
  static_assert(is_same<decltype(test(      January, Sunday[last], Sunday[last])), void>{});

  static_assert(is_same<decltype(test(      1y,         1,         1)), year_month_day>{});
  static_assert(is_same<decltype(test(      1y,         1,       1d)), year_month_day>{});
  static_assert(is_same<decltype(test(      1y,         1,       January)), void>{});
  static_assert(is_same<decltype(test(      1y,         1,       1y)), void>{});
  static_assert(is_same<decltype(test(      1y,         1,      last)), year_month_day_last>{});
  static_assert(is_same<decltype(test(      1y,         1,    Sunday[1])), year_month_weekday>{});
  static_assert(is_same<decltype(test(      1y,         1, Sunday[last])), year_month_weekday_last>{});

  static_assert(is_same<decltype(test(      1y,       1d,         1)), void>{});
  static_assert(is_same<decltype(test(      1y,       1d,       1d)), void>{});
  static_assert(is_same<decltype(test(      1y,       1d,       January)), void>{});
  static_assert(is_same<decltype(test(      1y,       1d,       1y)), void>{});
  static_assert(is_same<decltype(test(      1y,       1d,      last)), void>{});
  static_assert(is_same<decltype(test(      1y,       1d,    Sunday[1])), void>{});
  static_assert(is_same<decltype(test(      1y,       1d, Sunday[last])), void>{});

  static_assert(is_same<decltype(test(      1y,       January,         1)), year_month_day>{});
  static_assert(is_same<decltype(test(      1y,       January,       1d)), year_month_day>{});
  static_assert(is_same<decltype(test(      1y,       January,       January)), void>{});
  static_assert(is_same<decltype(test(      1y,       January,       1y)), void>{});
  static_assert(is_same<decltype(test(      1y,       January,      last)), year_month_day_last>{});
  static_assert(is_same<decltype(test(      1y,       January,    Sunday[1])), year_month_weekday>{});
  static_assert(is_same<decltype(test(      1y,       January, Sunday[last])), year_month_weekday_last>{});

  static_assert(is_same<decltype(test(      1y,       1y,         1)), void>{});
  static_assert(is_same<decltype(test(      1y,       1y,       1d)), void>{});
  static_assert(is_same<decltype(test(      1y,       1y,       January)), void>{});
  static_assert(is_same<decltype(test(      1y,       1y,       1y)), void>{});
  static_assert(is_same<decltype(test(      1y,       1y,      last)), void>{});
  static_assert(is_same<decltype(test(      1y,       1y,    Sunday[1])), void>{});
  static_assert(is_same<decltype(test(      1y,       1y, Sunday[last])), void>{});

  static_assert(is_same<decltype(test(      1y,      last,         1)), void>{});
  static_assert(is_same<decltype(test(      1y,      last,       1d)), void>{});
  static_assert(is_same<decltype(test(      1y,      last,       January)), void>{});
  static_assert(is_same<decltype(test(      1y,      last,       1y)), void>{});
  static_assert(is_same<decltype(test(      1y,      last,      last)), void>{});
  static_assert(is_same<decltype(test(      1y,      last,    Sunday[1])), void>{});
  static_assert(is_same<decltype(test(      1y,      last, Sunday[last])), void>{});

  static_assert(is_same<decltype(test(      1y,    Sunday[1],         1)), void>{});
  static_assert(is_same<decltype(test(      1y,    Sunday[1],       1d)), void>{});
  static_assert(is_same<decltype(test(      1y,    Sunday[1],       January)), void>{});
  static_assert(is_same<decltype(test(      1y,    Sunday[1],       1y)), void>{});
  static_assert(is_same<decltype(test(      1y,    Sunday[1],      last)), void>{});
  static_assert(is_same<decltype(test(      1y,    Sunday[1],    Sunday[1])), void>{});
  static_assert(is_same<decltype(test(      1y,    Sunday[1], Sunday[last])), void>{});

  static_assert(is_same<decltype(test(      1y, Sunday[last],         1)), void>{});
  static_assert(is_same<decltype(test(      1y, Sunday[last],       1d)), void>{});
  static_assert(is_same<decltype(test(      1y, Sunday[last],       January)), void>{});
  static_assert(is_same<decltype(test(      1y, Sunday[last],       1y)), void>{});
  static_assert(is_same<decltype(test(      1y, Sunday[last],      last)), void>{});
  static_assert(is_same<decltype(test(      1y, Sunday[last],    Sunday[1])), void>{});
  static_assert(is_same<decltype(test(      1y, Sunday[last], Sunday[last])), void>{});

  static_assert(is_same<decltype(test(     last,         1,         1)), year_month_day_last>{});
  static_assert(is_same<decltype(test(     last,         1,       1d)), void>{});
  static_assert(is_same<decltype(test(     last,         1,       January)), void>{});
  static_assert(is_same<decltype(test(     last,         1,       1y)), year_month_day_last>{});
  static_assert(is_same<decltype(test(     last,         1,      last)), void>{});
  static_assert(is_same<decltype(test(     last,         1,    Sunday[1])), void>{});
  static_assert(is_same<decltype(test(     last,         1, Sunday[last])), void>{});

  static_assert(is_same<decltype(test(     last,       1d,         1)), void>{});
  static_assert(is_same<decltype(test(     last,       1d,       1d)), void>{});
  static_assert(is_same<decltype(test(     last,       1d,       January)), void>{});
  static_assert(is_same<decltype(test(     last,       1d,       1y)), void>{});
  static_assert(is_same<decltype(test(     last,       1d,      last)), void>{});
  static_assert(is_same<decltype(test(     last,       1d,    Sunday[1])), void>{});
  static_assert(is_same<decltype(test(     last,       1d, Sunday[last])), void>{});

  static_assert(is_same<decltype(test(     last,       January,         1)), year_month_day_last>{});
  static_assert(is_same<decltype(test(     last,       January,       1d)), void>{});
  static_assert(is_same<decltype(test(     last,       January,       January)), void>{});
  static_assert(is_same<decltype(test(     last,       January,       1y)), year_month_day_last>{});
  static_assert(is_same<decltype(test(     last,       January,      last)), void>{});
  static_assert(is_same<decltype(test(     last,       January,    Sunday[1])), void>{});
  static_assert(is_same<decltype(test(     last,       January, Sunday[last])), void>{});

  static_assert(is_same<decltype(test(     last,       1y,         1)), void>{});
  static_assert(is_same<decltype(test(     last,       1y,       1d)), void>{});
  static_assert(is_same<decltype(test(     last,       1y,       January)), void>{});
  static_assert(is_same<decltype(test(     last,       1y,       1y)), void>{});
  static_assert(is_same<decltype(test(     last,       1y,      last)), void>{});
  static_assert(is_same<decltype(test(     last,       1y,    Sunday[1])), void>{});
  static_assert(is_same<decltype(test(     last,       1y, Sunday[last])), void>{});

  static_assert(is_same<decltype(test(     last,      last,         1)), void>{});
  static_assert(is_same<decltype(test(     last,      last,       1d)), void>{});
  static_assert(is_same<decltype(test(     last,      last,       January)), void>{});
  static_assert(is_same<decltype(test(     last,      last,       1y)), void>{});
  static_assert(is_same<decltype(test(     last,      last,      last)), void>{});
  static_assert(is_same<decltype(test(     last,      last,    Sunday[1])), void>{});
  static_assert(is_same<decltype(test(     last,      last, Sunday[last])), void>{});

  static_assert(is_same<decltype(test(     last,    Sunday[1],         1)), void>{});
  static_assert(is_same<decltype(test(     last,    Sunday[1],       1d)), void>{});
  static_assert(is_same<decltype(test(     last,    Sunday[1],       January)), void>{});
  static_assert(is_same<decltype(test(     last,    Sunday[1],       1y)), void>{});
  static_assert(is_same<decltype(test(     last,    Sunday[1],      last)), void>{});
  static_assert(is_same<decltype(test(     last,    Sunday[1],    Sunday[1])), void>{});
  static_assert(is_same<decltype(test(     last,    Sunday[1], Sunday[last])), void>{});

  static_assert(is_same<decltype(test(     last, Sunday[last],         1)), void>{});
  static_assert(is_same<decltype(test(     last, Sunday[last],       1d)), void>{});
  static_assert(is_same<decltype(test(     last, Sunday[last],       January)), void>{});
  static_assert(is_same<decltype(test(     last, Sunday[last],       1y)), void>{});
  static_assert(is_same<decltype(test(     last, Sunday[last],      last)), void>{});
  static_assert(is_same<decltype(test(     last, Sunday[last],    Sunday[1])), void>{});
  static_assert(is_same<decltype(test(     last, Sunday[last], Sunday[last])), void>{});

  static_assert(is_same<decltype(test(   Sunday[1],         1,         1)), year_month_weekday>{});
  static_assert(is_same<decltype(test(   Sunday[1],         1,       1d)), void>{});
  static_assert(is_same<decltype(test(   Sunday[1],         1,       January)), void>{});
  static_assert(is_same<decltype(test(   Sunday[1],         1,       1y)), year_month_weekday>{});
  static_assert(is_same<decltype(test(   Sunday[1],         1,      last)), void>{});
  static_assert(is_same<decltype(test(   Sunday[1],         1,    Sunday[1])), void>{});
  static_assert(is_same<decltype(test(   Sunday[1],         1, Sunday[last])), void>{});

  static_assert(is_same<decltype(test(   Sunday[1],       1d,         1)), void>{});
  static_assert(is_same<decltype(test(   Sunday[1],       1d,       1d)), void>{});
  static_assert(is_same<decltype(test(   Sunday[1],       1d,       January)), void>{});
  static_assert(is_same<decltype(test(   Sunday[1],       1d,       1y)), void>{});
  static_assert(is_same<decltype(test(   Sunday[1],       1d,      last)), void>{});
  static_assert(is_same<decltype(test(   Sunday[1],       1d,    Sunday[1])), void>{});
  static_assert(is_same<decltype(test(   Sunday[1],       1d, Sunday[last])), void>{});

  static_assert(is_same<decltype(test(   Sunday[1],       January,         1)), year_month_weekday>{});
  static_assert(is_same<decltype(test(   Sunday[1],       January,       1d)), void>{});
  static_assert(is_same<decltype(test(   Sunday[1],       January,       January)), void>{});
  static_assert(is_same<decltype(test(   Sunday[1],       January,       1y)), year_month_weekday>{});
  static_assert(is_same<decltype(test(   Sunday[1],       January,      last)), void>{});
  static_assert(is_same<decltype(test(   Sunday[1],       January,    Sunday[1])), void>{});
  static_assert(is_same<decltype(test(   Sunday[1],       January, Sunday[last])), void>{});

  static_assert(is_same<decltype(test(   Sunday[1],       1y,         1)), void>{});
  static_assert(is_same<decltype(test(   Sunday[1],       1y,       1d)), void>{});
  static_assert(is_same<decltype(test(   Sunday[1],       1y,       January)), void>{});
  static_assert(is_same<decltype(test(   Sunday[1],       1y,       1y)), void>{});
  static_assert(is_same<decltype(test(   Sunday[1],       1y,      last)), void>{});
  static_assert(is_same<decltype(test(   Sunday[1],       1y,    Sunday[1])), void>{});
  static_assert(is_same<decltype(test(   Sunday[1],       1y, Sunday[last])), void>{});

  static_assert(is_same<decltype(test(   Sunday[1],      last,         1)), void>{});
  static_assert(is_same<decltype(test(   Sunday[1],      last,       1d)), void>{});
  static_assert(is_same<decltype(test(   Sunday[1],      last,       January)), void>{});
  static_assert(is_same<decltype(test(   Sunday[1],      last,       1y)), void>{});
  static_assert(is_same<decltype(test(   Sunday[1],      last,      last)), void>{});
  static_assert(is_same<decltype(test(   Sunday[1],      last,    Sunday[1])), void>{});
  static_assert(is_same<decltype(test(   Sunday[1],      last, Sunday[last])), void>{});

  static_assert(is_same<decltype(test(   Sunday[1],    Sunday[1],         1)), void>{});
  static_assert(is_same<decltype(test(   Sunday[1],    Sunday[1],       1d)), void>{});
  static_assert(is_same<decltype(test(   Sunday[1],    Sunday[1],       January)), void>{});
  static_assert(is_same<decltype(test(   Sunday[1],    Sunday[1],       1y)), void>{});
  static_assert(is_same<decltype(test(   Sunday[1],    Sunday[1],      last)), void>{});
  static_assert(is_same<decltype(test(   Sunday[1],    Sunday[1],    Sunday[1])), void>{});
  static_assert(is_same<decltype(test(   Sunday[1],    Sunday[1], Sunday[last])), void>{});

  static_assert(is_same<decltype(test(   Sunday[1], Sunday[last],         1)), void>{});
  static_assert(is_same<decltype(test(   Sunday[1], Sunday[last],       1d)), void>{});
  static_assert(is_same<decltype(test(   Sunday[1], Sunday[last],       January)), void>{});
  static_assert(is_same<decltype(test(   Sunday[1], Sunday[last],       1y)), void>{});
  static_assert(is_same<decltype(test(   Sunday[1], Sunday[last],      last)), void>{});
  static_assert(is_same<decltype(test(   Sunday[1], Sunday[last],    Sunday[1])), void>{});
  static_assert(is_same<decltype(test(   Sunday[1], Sunday[last], Sunday[last])), void>{});

  static_assert(is_same<decltype(test(Sunday[last],         1,         1)), year_month_weekday_last>{});
  static_assert(is_same<decltype(test(Sunday[last],         1,       1d)), void>{});
  static_assert(is_same<decltype(test(Sunday[last],         1,       January)), void>{});
  static_assert(is_same<decltype(test(Sunday[last],         1,       1y)), year_month_weekday_last>{});
  static_assert(is_same<decltype(test(Sunday[last],         1,      last)), void>{});
  static_assert(is_same<decltype(test(Sunday[last],         1,    Sunday[1])), void>{});
  static_assert(is_same<decltype(test(Sunday[last],         1, Sunday[last])), void>{});

  static_assert(is_same<decltype(test(Sunday[last],       1d,         1)), void>{});
  static_assert(is_same<decltype(test(Sunday[last],       1d,       1d)), void>{});
  static_assert(is_same<decltype(test(Sunday[last],       1d,       January)), void>{});
  static_assert(is_same<decltype(test(Sunday[last],       1d,       1y)), void>{});
  static_assert(is_same<decltype(test(Sunday[last],       1d,      last)), void>{});
  static_assert(is_same<decltype(test(Sunday[last],       1d,    Sunday[1])), void>{});
  static_assert(is_same<decltype(test(Sunday[last],       1d, Sunday[last])), void>{});

  static_assert(is_same<decltype(test(Sunday[last],       January,         1)), year_month_weekday_last>{});
  static_assert(is_same<decltype(test(Sunday[last],       January,       1d)), void>{});
  static_assert(is_same<decltype(test(Sunday[last],       January,       January)), void>{});
  static_assert(is_same<decltype(test(Sunday[last],       January,       1y)), year_month_weekday_last>{});
  static_assert(is_same<decltype(test(Sunday[last],       January,      last)), void>{});
  static_assert(is_same<decltype(test(Sunday[last],       January,    Sunday[1])), void>{});
  static_assert(is_same<decltype(test(Sunday[last],       January, Sunday[last])), void>{});

  static_assert(is_same<decltype(test(Sunday[last],       1y,         1)), void>{});
  static_assert(is_same<decltype(test(Sunday[last],       1y,       1d)), void>{});
  static_assert(is_same<decltype(test(Sunday[last],       1y,       January)), void>{});
  static_assert(is_same<decltype(test(Sunday[last],       1y,       1y)), void>{});
  static_assert(is_same<decltype(test(Sunday[last],       1y,      last)), void>{});
  static_assert(is_same<decltype(test(Sunday[last],       1y,    Sunday[1])), void>{});
  static_assert(is_same<decltype(test(Sunday[last],       1y, Sunday[last])), void>{});

  static_assert(is_same<decltype(test(Sunday[last],      last,         1)), void>{});
  static_assert(is_same<decltype(test(Sunday[last],      last,       1d)), void>{});
  static_assert(is_same<decltype(test(Sunday[last],      last,       January)), void>{});
  static_assert(is_same<decltype(test(Sunday[last],      last,       1y)), void>{});
  static_assert(is_same<decltype(test(Sunday[last],      last,      last)), void>{});
  static_assert(is_same<decltype(test(Sunday[last],      last,    Sunday[1])), void>{});
  static_assert(is_same<decltype(test(Sunday[last],      last, Sunday[last])), void>{});

  static_assert(is_same<decltype(test(Sunday[last],    Sunday[1],         1)), void>{});
  static_assert(is_same<decltype(test(Sunday[last],    Sunday[1],       1d)), void>{});
  static_assert(is_same<decltype(test(Sunday[last],    Sunday[1],       January)), void>{});
  static_assert(is_same<decltype(test(Sunday[last],    Sunday[1],       1y)), void>{});
  static_assert(is_same<decltype(test(Sunday[last],    Sunday[1],      last)), void>{});
  static_assert(is_same<decltype(test(Sunday[last],    Sunday[1],    Sunday[1])), void>{});
  static_assert(is_same<decltype(test(Sunday[last],    Sunday[1], Sunday[last])), void>{});

  static_assert(is_same<decltype(test(Sunday[last], Sunday[last],         1)), void>{});
  static_assert(is_same<decltype(test(Sunday[last], Sunday[last],       1d)), void>{});
  static_assert(is_same<decltype(test(Sunday[last], Sunday[last],       January)), void>{});
  static_assert(is_same<decltype(test(Sunday[last], Sunday[last],       1y)), void>{});
  static_assert(is_same<decltype(test(Sunday[last], Sunday[last],      last)), void>{});
  static_assert(is_same<decltype(test(Sunday[last], Sunday[last],    Sunday[1])), void>{});
  static_assert(is_same<decltype(test(Sunday[last], Sunday[last], Sunday[last])), void>{});
}
