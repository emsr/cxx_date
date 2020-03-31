// { dg-options "-std=gnu++20" }
// { dg-do compile { target c++20 } }

// Copyright (C) 2020 Free Software Foundation, Inc.
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

// Class template month_day [time.cal.month_day]

#include <chrono>

constexpr void
constexpr_year_month_weekday_last()
{
  using namespace std::chrono;
  using ymwdl = year_month_weekday_last;

  // Div operations...
  static_assert(2015y/August/Friday[last] == ymwdl{year{2015}, month{8}, weekday_last{weekday{5u}}});
  static_assert(2015y/(August/Friday[last]) == ymwdl{year{2015}, month{8}, weekday_last{weekday{5u}}});
  static_assert(2015/(August/Friday[last]) == ymwdl{year{2015}, month{8}, weekday_last{weekday{5u}}});
  //static_assert(August/Friday[last]/2015y == ymwdl{year{2015}, month{8}, weekday_last{weekday{5u}}});
  //static_assert(August/Friday[last]/2015 == ymwdl{year{2015}, month{8}, weekday_last{weekday{5u}}});
}
