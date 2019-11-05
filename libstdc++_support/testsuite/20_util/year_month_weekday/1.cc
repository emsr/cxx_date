// { dg-options "-std=gnu++2a" }
// { dg-do compile { target c++2a } }

// Copyright (C) 2019 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING3.  If not see
// <http://www.gnu.org/licenses/>.

// Class template day [time.cal.year_month_weekday]

#include <chrono>

constexpr void
constexpr_year_month_weekday()
{
  using namespace std::chrono;
  using ymwd = year_month_weekday;

  year_month_weekday ymwd1{};
  ymwd1 += months{9};
  ymwd1 -= months{9};
  ymwd1 += years{12};
  ymwd1 -= years{12};

  constexpr ymwd ymwd2{year{1984}, month{August},
		       weekday_indexed{Wednesday, 3}};
  static_assert(ymwd2.year() == year{1984});
  static_assert(ymwd2.month() == August);
  static_assert(ymwd2.weekday() == Wednesday);
  static_assert(ymwd2.index() == 3);
  static_assert(ymwd2.weekday_indexed() == weekday_indexed{Wednesday, 3});

  //constexpr ymwd unix(local_days{0});
  constexpr ymwd unix{year{1970}, January, weekday_indexed{Thursday, 1}};
  static_assert(unix.year() == year{1970});
  static_assert(unix.month() == January);
  static_assert(unix.weekday() == Thursday);
  static_assert(unix.index() == 1);
  static_assert(unix.weekday_indexed() == weekday_indexed{Thursday, 1});
}
