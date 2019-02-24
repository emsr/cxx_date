/*
g++ -std=c++17 -g -o test_date test_date.cpp

/home/ed/bin/bin/g++ -std=c++2a -g -o test_date test_date.cpp
*/

#include <chrono.h>
#include <iostream>

constexpr void
constexpr_day()
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
constexpr_month()
{
  using namespace std::chrono;

  month dm{};
  ++dm;
  dm++;
  --dm;
  dm--;
  dm += months{3};
  dm -= months{3};

  static_assert(February + months{11} == January);
  static_assert(January - February == months{11});

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
constexpr_year()
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
constexpr_weekday()
{
  using namespace std::chrono;

  weekday dwd{};
  ++dwd;
  dwd++;
  --dwd;
  dwd--;
  dwd += days{3};
  dwd -= days{3};

  static_assert(Monday + days{6} == Sunday);
  static_assert(Sunday - Monday == days{6});
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
constexpr_weekday_indexed()
{
  using namespace std::chrono;

  weekday_indexed dwdi{};

  // wdi0 is the second Sunday of an as yet unspecified month.
  constexpr auto wdi0 = Sunday[2];
  static_assert(wdi0.weekday() == Sunday);
  static_assert(wdi0.index() == 2);

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
constexpr_weekday_last()
{
  using namespace std::chrono;

  constexpr auto wdl0 = Sunday[last];
  static_assert(wdl0.weekday() == Sunday);

  constexpr auto wdl1 = weekday{3}[2];
  static_assert(wdl1.weekday() == weekday{3});
  static_assert(wdl1.index() == 2);
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

constexpr void
constexpr_month_day()
{
  using namespace std::chrono;
  using md = month_day;

  //constexpr unsigned
  //dim[12]
  //{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  month_day md0 = April/4;
  month_day md2 = 4d/April;

  constexpr auto md1 = month_day{month{3}, day{13}};
  static_assert(md1.month() == month{3});
  static_assert(md1.day() == day{13});

  static_assert(!month_day{month{1}, day{}}.ok());
  static_assert( month_day{month{2}, day{1}}.ok());
  static_assert( month_day{month{3}, day{31}}.ok());
  static_assert(!month_day{month{4}, day{32}}.ok());
  static_assert(!month_day{month{0}, day{11}}.ok());
  static_assert(!month_day{month{13}, day{7}}.ok());
  static_assert( month_day{month{2}, day{28}}.ok());
  static_assert( month_day{month{2}, day{29}}.ok());
  static_assert(!month_day{month{2}, day{30}}.ok());
  //for (unsigned m = 0; m < 12; ++m)
  //  for (unsigned d = 1; d <= dim[m]; ++d)
  //    static_assert(month_day{month{m+1}, day{d}}.ok());

  static_assert(!(md{month{1}, day{0}} == md{month{1}, day{1}}));
  static_assert( (md{month{2}, day{0}} != md{month{2}, day{2}}));
  static_assert( (md{month{3}, day{0}} <  md{month{3}, day{3}}));
  static_assert(!(md{month{4}, day{0}} >  md{month{4}, day{4}}));
  static_assert( (md{month{5}, day{0}} <= md{month{5}, day{5}}));
  static_assert(!(md{month{6}, day{0}} >= md{month{6}, day{6}}));
  static_assert( (md{month{10}, day{13}} == md{month{10}, day{13}}));
  static_assert( (md{month{9}, day{13}} != md{month{10}, day{13}}));
  static_assert( (md{month{8}, day{13}} < md{month{10}, day{13}}));
  static_assert( (md{month{11}, day{13}} > md{month{10}, day{13}}));
  static_assert( (md{month{10}, day{13}} <= md{month{10}, day{13}}));
  static_assert( (md{month{10}, day{13}} >= md{month{10}, day{13}}));
}

constexpr void
constexpr_month_day_last()
{
  using namespace std::chrono;
  using mdl = month_day_last;

  constexpr auto mdl0 = February / last;
  static_assert(mdl0.month() == February);

  constexpr auto mdl1 = month_day_last{month{3}};
  static_assert(mdl1.month() == month{3});

  static_assert( mdl{month{3}}.ok());
  static_assert(!mdl{month{0}}.ok());
  static_assert(!mdl{month{13}}.ok());

  static_assert( (mdl{month{1}} == mdl{month{1}}));
  static_assert(!(mdl{month{2}} != mdl{month{2}}));
  static_assert(!(mdl{month{3}} <  mdl{month{3}}));
  static_assert(!(mdl{month{4}} >  mdl{month{4}}));
  static_assert( (mdl{month{5}} <= mdl{month{5}}));
  static_assert( (mdl{month{6}} >= mdl{month{6}}));
  static_assert( (mdl{month{10}} == mdl{month{10}}));
  static_assert( (mdl{month{9}} != mdl{month{10}}));
  static_assert( (mdl{month{8}} < mdl{month{10}}));
  static_assert( (mdl{month{11}} > mdl{month{10}}));
  static_assert( (mdl{month{10}} <= mdl{month{10}}));
  static_assert( (mdl{month{10}} >= mdl{month{10}}));
}

constexpr void
constexpr_month_weekday()
{
  using namespace std::chrono;
  using mwd = month_weekday;

  // mwd0 is the third Tuesday of February of an as yet unspecified year.
  constexpr auto mwd0 = February / Tuesday[3];
  static_assert(mwd0.month() == February);
  static_assert(mwd0.weekday_indexed() == Tuesday[3]);

}

constexpr void
constexpr_month_weekday_last()
{
  using namespace std::chrono;
  using mwdl = month_weekday;

  // mwd0 is the third Tuesday of February of an as yet unspecified year.
  constexpr auto mwdl0 = February / Tuesday[last];
  static_assert(mwdl0.month() == February);
  static_assert(mwdl0.weekday_last() == Tuesday[last]);

}

constexpr void
constexpr_year_month()
{
  using namespace std::chrono;
  using ym = year_month;

  year_month ym0 = 2015y/April;
}

constexpr void
constexpr_year_month_day()
{
  using namespace std::chrono;
  using ymd = year_month_day;

  static_assert(ymd{sys_days{2017y/January/0}}  == 2016y/December/31);
  static_assert(ymd{sys_days{2017y/January/31}} == 2017y/January/31);
  static_assert(ymd{sys_days{2017y/January/32}} == 2017y/February/1);
//time_point_cast<days>(now)
  constexpr ymd ymd2{year{1984}, August, 3d};
  static_assert(ymd2.year() == year{1984});
  static_assert(ymd2.month() == August);
  static_assert(ymd2.day() == 3d);
  //static_assert(sys_days(ymd2) == time_point_cast<days>(days{5356}));
  //static_assert(local_days(ymd2) == time_point_cast<days>(days{5356}));

  constexpr ymd unix = 1970y/1/1;
  static_assert(unix.year() == year{1970});
  static_assert(unix.month() == January);
  static_assert(unix.day() == day{1});
  //static_assert(sys_days(unix) == time_point_cast<days>(days{0}));
  //static_assert(local_days(unix) == time_point_cast<days>(days{0}));
}

constexpr void
constexpr_year_month_day_last()
{
  using namespace std::chrono;
  using mdl = month_day_last;
  using ymdl = year_month_day_last;

  year_month_day_last ymdl1{year{1066}, mdl{October}};
  ymdl1 += months{9};
  ymdl1 -= months{9};
  ymdl1 += years{12};
  ymdl1 -= years{12};

  constexpr ymdl ymdl2{year{1984}, mdl{August}};
  static_assert(ymdl2.year() == year{1984});
  static_assert(ymdl2.month() == August);
  static_assert(ymdl2.month_day_last() == mdl{August});
  static_assert(ymdl2.day() == day{31});
  //static_assert(sys_days(ymdl2).count() == 5356);
  //static_assert(local_days(ymdl2).count() == 5356);

  static_assert( (ymdl{year{1984}, mdl{August}}.ok()));
  static_assert(!(ymdl{year{1984}, mdl{month{13}}}.ok()));
}

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

constexpr void
constexpr_year_month_weekday_last()
{
  using namespace std::chrono;
  using ymwdl = year_month_weekday_last;
}

int
main()
{
}
