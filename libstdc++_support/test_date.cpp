/*
g++ -std=c++17 -g -o test_date test_date.cpp

/home/ed/bin/bin/g++ -std=c++2a -g -o test_date test_date.cpp
*/

#include <chrono.h>

constexpr void
test_day()
{
  using namespace std::chrono;

  day dd{};
  ++dd;
  dd++;
  --dd;
  dd--;
  dd += days{3};
  dd -= days{3};

  static_assert(++day{4} == day{5});
  static_assert(day{4}++ == day{4});
  static_assert(--day{4} == day{3});
  static_assert(day{4}-- == day{4});
  static_assert((day{4} += days{3}) == day{7});
  static_assert((day{4} -= days{3}) == day{1});

  static_assert(!day{}.ok());
  static_assert(day{1}.ok());
  static_assert(day{31}.ok());
  static_assert(!day{32}.ok());

  static_assert(!(day{0} == day{1}));
  static_assert( (day{0} != day{2}));
  static_assert( (day{0} <  day{3}));
  static_assert(!(day{0} >  day{4}));
  static_assert( (day{0} <= day{5}));
  static_assert(!(day{0} >= day{6}));
}

constexpr void
test_month()
{
  using namespace std::chrono;

  month dm{};
  ++dm;
  dm++;
  --dm;
  dm--;
  dm += months{3};
  dm -= months{3};

  static_assert(++month{4} == month{5});
  static_assert(month{4}++ == month{4});
  static_assert(--month{4} == month{3});
  static_assert(month{4}-- == month{4});
  static_assert((month{4} += months{3}) == month{7});
  static_assert((month{4} -= months{3}) == month{1});

  static_assert(!month{}.ok());
  static_assert(month{1}.ok());
  static_assert(month{12}.ok());
  static_assert(!month{13}.ok());

  static_assert(!(month{0} == month{1}));
  static_assert( (month{0} != month{2}));
  static_assert( (month{0} <  month{3}));
  static_assert(!(month{0} >  month{4}));
  static_assert( (month{0} <= month{5}));
  static_assert(!(month{0} >= month{6}));
}

constexpr void
test_year()
{
  using namespace std::chrono;

  year dy{};
  ++dy;
  dy++;
  --dy;
  dy--;
  dy += years{3};
  dy -= years{3};

  static_assert(++year{4} == year{5});
  static_assert(year{4}++ == year{4});
  static_assert(--year{4} == year{3});
  static_assert(year{4}-- == year{4});
  static_assert((year{4} += years{3}) == year{7});
  static_assert((year{4} -= years{3}) == year{1});

  const auto my = -dy;
  const auto py = +dy;

  static_assert((-year{1066} == year{-1066}));
  static_assert((-year{-332} == year{332}));
  static_assert((+year{1066} == year{1066}));
  static_assert((+year{-332} == year{-332}));

  year::min();
  year::max();

  static_assert(year{-12345}.ok());
  static_assert(year{1}.ok());
  static_assert(year{12}.ok());
  static_assert(year{13}.ok());

  static_assert(!(year{0} == year{1}));
  static_assert( (year{0} != year{2}));
  static_assert( (year{0} <  year{3}));
  static_assert(!(year{0} >  year{4}));
  static_assert( (year{0} <= year{5}));
  static_assert(!(year{0} >= year{6}));

  static_assert( year{400}.is_leap());
  static_assert( year{1984}.is_leap());
  static_assert(!year{1}.is_leap());
  static_assert( year{1600}.is_leap());
  static_assert(!year{3000}.is_leap());
  static_assert(!year{2019}.is_leap());
}

constexpr void
test_weekday()
{
  using namespace std::chrono;

  weekday dwd{};
  ++dwd;
  dwd++;
  --dwd;
  dwd--;
  dwd += days{3};
  dwd -= days{3};

/* Test 
    constexpr
    weekday(const sys_days& __dp) noexcept
    : _M_wd(__from_days(__dp.time_since_epoch().count()))
    { }

    explicit constexpr
    weekday(const local_days& __dp) noexcept
    : _M_wd(__from_days(__dp.time_since_epoch().count()))
    { }
*/

/* Test 
    constexpr weekday_indexed
    operator[](unsigned __index) const noexcept;

    constexpr weekday_last
    operator[](last_spec) const noexcept;
*/
  static_assert(weekday{3}[2].weekday() == weekday{3});
  static_assert(weekday{3}[last].weekday() == weekday{3});

  static_assert(++weekday{3} == weekday{4});
  static_assert(weekday{3}++ == weekday{3});
  static_assert(--weekday{3} == weekday{2});
  static_assert(weekday{3}-- == weekday{3});
  static_assert((weekday{3} += days{3}) == weekday{6});
  static_assert((weekday{3} -= days{3}) == weekday{0});

  static_assert(!weekday{127}.ok());
  static_assert(weekday{0}.ok());
  static_assert(weekday{6}.ok());
  static_assert(weekday{7}.ok()); // Ctor wraps 7 to 0.
  static_assert(!weekday{8}.ok());

  static_assert(weekday{7} == weekday{0});
  static_assert(!(weekday{0} == weekday{1}));
  static_assert( (weekday{0} != weekday{2}));
}

constexpr void
test_weekday_indexed()
{
  using namespace std::chrono;

  weekday_indexed dwdi{};

  constexpr auto wdl2 = weekday{3}[2];
  static_assert(wdl2.weekday() == weekday{3});
  static_assert(wdl2.index() == 2);

  static_assert(!weekday_indexed{weekday{127}, 1}.ok());
  static_assert(weekday_indexed{weekday{0}, 1}.ok());
  static_assert(weekday_indexed{weekday{6}, 2}.ok());
  static_assert(weekday_indexed{weekday{7}, 3}.ok()); // Weekday wraps 7 to 0.
  static_assert(!weekday_indexed{weekday{8}, 1}.ok());
  static_assert(!weekday_indexed{weekday{6}, 6}.ok());

  static_assert(weekday{7} == weekday{0});
  static_assert(!(weekday{0} == weekday{1}));
  static_assert( (weekday{0} != weekday{2}));
}

constexpr void
test_weekday_last()
{
  using namespace std::chrono;

  constexpr auto wdl2 = weekday{3}[2];
  static_assert(wdl2.weekday() == weekday{3});
  static_assert(wdl2.index() == 2);
  constexpr auto wdll = weekday{3}[last];
  static_assert(wdll.weekday() == weekday{3});

  static_assert(!weekday_last{weekday{127}}.ok());
  static_assert(weekday_last{weekday{0}}.ok());
  static_assert(weekday_last{weekday{6}}.ok());
  static_assert(weekday_last{weekday{7}}.ok()); // Weekday wraps 7 to 0.
  static_assert(!weekday_last{weekday{8}}.ok());

  static_assert( (weekday_last{weekday{7}} == weekday_last{weekday{0}}));
  static_assert(!(weekday_last{weekday{0}} == weekday_last{weekday{1}}));
  static_assert( (weekday_last{weekday{0}} != weekday_last{weekday{2}}));
}


int
main()
{
  test_day();
  test_month();
  test_year();
  test_weekday();
  test_weekday_indexed();
}
