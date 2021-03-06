#ifndef _GLIBCXX_DATE_IO_TCC
#define _GLIBCXX_DATE_IO_TCC 1

#pragma GCC system_header

namespace std {
namespace chrono {

  // DURATION I/O

// Make a generic to_string for char and wchar_t.
// std::basic_ostream<_CharT, _Traits> to_basic_string();
/*
  
  template<typename _CharT, typename _Traits, typename _Period>
    const _CharT*
    get_units<_CharT, _Traits>(typename __type = _Period::type{})
    {
      switch (__type)
	{
	case: std::atto "as"
	case: std::femto "fs"
	case: std::pico "ps"
	case: std::nano "ns"
	case: std::micro "�s (U+00B5)" or else "us"
	case: std::milli "ms"
	case: std::centi "cs"
	case: std::deci "ds"
	case: std::ratio<1> "s"
	case: std::deca "das"
	case: std::hecto "hs"
	case: std::kilo "ks"
	case: std::mega "Ms"
	case: std::giga "Gs"
	case: std::tera "Ts"
	case: std::peta "Ps"
	case: std::exa "Es"
	case: std::ratio<60> "min"
	case: ratio<3600> "h"
	case: ratio<86400> "d"
	default:
	  if constexpr _Period::den == 1
	    "[_Period::num]s"
	  else
	    "[_Period::num/_Period::den]s"
	}
    }
*/

  template<typename _CharT, typename _Traits, typename _Rep, typename _Period>
    std::basic_ostream<_CharT, _Traits>&
    operator<<(std::basic_ostream<_CharT, _Traits>& __os,
	       const duration<_Rep, _Period>& __d)
    {
      //basic_string<_CharT, _Traits> __dstr = to_string
      return __os;
    }

  template<typename _CharT, typename _Traits, typename _Rep, typename _Period>
    std::basic_ostream<_CharT, _Traits>&
    to_stream(std::basic_ostream<_CharT, _Traits>& __os, const _CharT* __fmt,
	      const duration<_Rep, _Period>& __d)
    {
      return __os;
    }

  template<typename _CharT, typename _Traits, typename _Rep,
	   typename _Period, typename _Alloc = allocator<_CharT>>
    std::basic_istream<_CharT, _Traits>&
    from_stream(std::basic_istream<_CharT, _Traits>& __is, const _CharT* __fmt,
	        duration<_Rep, _Period>& __d,
	        basic_string<_CharT, _Traits, _Alloc>* __abbrev,
	        minutes* __offset)
    {
      return __is;
    }

  // TIME_POINT I/O

  // OPERATOR<<

  template<typename _CharT, typename _Traits, typename _Duration>
    std::basic_ostream<_CharT, _Traits>&
    operator<<(std::basic_ostream<_CharT, _Traits>& __os,
	       const sys_time<_Duration>& __tp)
    {
      const auto __dp = std::chrono::floor<days>(__tp);
      __os << year_month_day{__dp} << ' ' << time_of_day{__tp - __dp};
      return __os;
    }

  template<typename _CharT, typename _Traits, typename _Duration>
    std::basic_ostream<_CharT, _Traits>&
    operator<<(std::basic_ostream<_CharT, _Traits>& __os,
	       const local_time<_Duration>& __tp)
    {
      return __os;
    }

  template<typename _CharT, typename _Traits>
    std::basic_ostream<_CharT, _Traits>&
    operator<<(std::basic_ostream<_CharT, _Traits>& __os,
	       const sys_days& __dp)
    {
      __os << year_month_day{__dp};
      return __os;
    }

  template<typename _CharT, typename _Traits, typename _Duration>
    std::basic_ostream<_CharT, _Traits>&
    operator<<(std::basic_ostream<_CharT, _Traits>& __os,
	       const utc_time<_Duration>& __t)
    {
      return __os;
    }

  template<typename _CharT, typename _Traits, typename _Duration>
    std::basic_ostream<_CharT, _Traits>&
    operator<<(std::basic_ostream<_CharT, _Traits>& __os,
	       const tai_time<_Duration>& __t)
    {
      return __os;
    }

  template<typename _CharT, typename _Traits, typename _Duration>
    std::basic_ostream<_CharT, _Traits>&
    operator<<(std::basic_ostream<_CharT, _Traits>& __os,
	       const gps_time<_Duration>& __t)
    {
      return __os;
    }

  template<typename _CharT, typename _Traits, typename _Duration>
    std::basic_ostream<_CharT, _Traits>&
    operator<<(std::basic_ostream<_CharT, _Traits>& __os,
	       const file_time<_Duration>& __tp)
    {
      return __os;
    }

  // TO_STREAM

  template<typename _CharT, typename _Traits, typename _Duration>
    std::basic_ostream<_CharT, _Traits>&
    to_stream(std::basic_ostream<_CharT, _Traits>& __os, const _CharT* __fmt,
	      const sys_time<_Duration>& __tp)
    {
      return __os;
    }

  template<typename _CharT, typename _Traits, typename _Duration>
    std::basic_ostream<_CharT, _Traits>&
    to_stream(std::basic_ostream<_CharT, _Traits>& __os, const _CharT* __fmt,
	      const local_time<_Duration>& __tp,
	      const string* __abbrev,
	      const seconds* __offset_sec)
    {
      return __os;
    }

  template<typename _CharT, typename _Traits, typename _Duration>
    std::basic_ostream<_CharT, _Traits>&
    to_stream(std::basic_ostream<_CharT, _Traits>& __os, const _CharT* __fmt,
	      const utc_time<_Duration>& __tp)
    {
      return __os;
    }

  template<typename _CharT, typename _Traits, typename _Duration>
    std::basic_ostream<_CharT, _Traits>&
    to_stream(std::basic_ostream<_CharT, _Traits>& __os, const _CharT* __fmt,
	      const tai_time<_Duration>& __tp)
    {
      return __os;
    }

  template<typename _CharT, typename _Traits, typename _Duration>
    std::basic_ostream<_CharT, _Traits>&
    to_stream(std::basic_ostream<_CharT, _Traits>& __os, const _CharT* __fmt,
	      const gps_time<_Duration>& __tp)
    {
      return __os;
    }

  template<typename _CharT, typename _Traits, typename _Duration>
    std::basic_ostream<_CharT, _Traits>&
    to_stream(std::basic_ostream<_CharT, _Traits>& __os, const _CharT* __fmt,
	      const file_time<_Duration>& __tp)
    {
      return __os;
    }

  // FROM_STREAM

  template<typename _CharT, typename _Traits, typename _Duration,
	   typename _Alloc = allocator<_CharT>>
    std::basic_istream<_CharT, _Traits>&
    from_stream(std::basic_istream<_CharT, _Traits>& __is, const _CharT* __fmt,
		sys_time<_Duration>& __tp,
		basic_string<_CharT, _Traits, _Alloc>* __abbrev,
		minutes* __offset)
    {
      return __is;
    }

  template<typename _CharT, typename _Traits, typename _Duration,
	   typename _Alloc = allocator<_CharT>>
    std::basic_istream<_CharT, _Traits>&
    from_stream(std::basic_istream<_CharT, _Traits>& __is, const _CharT* __fmt,
		local_time<_Duration>& __tp,
		basic_string<_CharT, _Traits, _Alloc>* __abbrev,
		minutes* __offset)
    {
      return __is;
    }

  template<typename _CharT, typename _Traits, typename _Duration,
	   typename _Alloc = allocator<_CharT>>
    std::basic_istream<_CharT, _Traits>&
    from_stream(std::basic_istream<_CharT, _Traits>& __is, const _CharT* __fmt,
		utc_time<_Duration>& __tp,
		basic_string<_CharT, _Traits, _Alloc>* __abbrev,
		minutes* __offset)
    {
      return __is;
    }

  template<typename _CharT, typename _Traits, typename _Duration,
	   typename _Alloc = allocator<_CharT>>
    std::basic_istream<_CharT, _Traits>&
    from_stream(std::basic_istream<_CharT, _Traits>& __is, const _CharT* __fmt,
		tai_time<_Duration>& __tp,
		basic_string<_CharT, _Traits, _Alloc>* __abbrev,
		minutes* __offset)
    {
      return __is;
    }

  template<typename _CharT, typename _Traits, typename _Duration,
	   typename _Alloc = allocator<_CharT>>
    std::basic_istream<_CharT, _Traits>&
    from_stream(std::basic_istream<_CharT, _Traits>& __is, const _CharT* __fmt,
		gps_time<_Duration>& __tp,
		basic_string<_CharT, _Traits, _Alloc>* __abbrev,
		minutes* __offset)
    {
      return __is;
    }

  template<typename _CharT, typename _Traits, typename _Duration,
	   typename _Alloc = allocator<_CharT>>
    std::basic_istream<_CharT, _Traits>&
    from_stream(std::basic_istream<_CharT, _Traits>& __is, const _CharT* __fmt,
		file_time<_Duration>& __tp,
		basic_string<_CharT, _Traits, _Alloc>* __abbrev,
		minutes* __offset)
    {
      return __is;
    }

  // DAY

  template<typename _CharT, typename _Traits>
    std::basic_ostream<_CharT, _Traits>&
    operator<<(std::basic_ostream<_CharT, _Traits>& __os, const day& __d)
    {
      return __os;
    }

  template<typename _CharT, typename _Traits>
    std::basic_ostream<_CharT, _Traits>&
    to_stream(std::basic_ostream<_CharT, _Traits>& __os,
	      const _CharT* __fmt, const day& __d)
    {
      return __os;
    }

  template<typename _CharT, typename _Traits,
	   typename _Alloc = allocator<_CharT>>
    std::basic_istream<_CharT, _Traits>&
    from_stream(std::basic_istream<_CharT, _Traits>& __is, const _CharT* __fmt,
		day& __d,
		basic_string<_CharT, _Traits, _Alloc>* __abbrev,
		minutes* __offset)
    {
      return __is;
    }

  // MONTH

  template<typename _CharT, typename _Traits>
    std::basic_ostream<_CharT, _Traits>&
    operator<<(std::basic_ostream<_CharT, _Traits>& __os, const month& __m)
    {
      if (__m.ok())
	{
	  _CharT __fmt[]{'%', 'b', '\0'}; // Can we use widen?
	  __os << format(__os.getloc(), __fmt, __m);
	}
      else
	__os << "invalid month: " << static_cast<unsigned>(__m);
      return __os;
    }

  template<typename _CharT, typename _Traits>
    std::basic_ostream<_CharT, _Traits>&
    to_stream(std::basic_ostream<_CharT, _Traits>& __os,
	      const _CharT* __fmt, const month& __m)
    {
      return __os;
    }

  template<typename _CharT, typename _Traits,
	   typename _Alloc = allocator<_CharT>>
    std::basic_istream<_CharT, _Traits>&
    from_stream(std::basic_istream<_CharT, _Traits>& __is, const _CharT* __fmt,
		month& __m,
		basic_string<_CharT, _Traits, _Alloc>* __abbrev,
		minutes* __offset)
    {
      return __is;
    }

  // YEAR

  template<typename _CharT, typename _Traits>
    std::basic_ostream<_CharT, _Traits>&
    operator<<(std::basic_ostream<_CharT, _Traits>& __os, const year& __y)
    {
      return __os;
    }

  template<typename _CharT, typename _Traits>
    std::basic_ostream<_CharT, _Traits>&
    to_stream(std::basic_ostream<_CharT, _Traits>& __os,
	      const _CharT* __fmt, const year& __y)
    {
      return __os;
    }

  template<typename _CharT, typename _Traits,
	   typename _Alloc = allocator<_CharT>>
    std::basic_istream<_CharT, _Traits>&
    from_stream(std::basic_istream<_CharT, _Traits>& __is, const _CharT* __fmt,
		year& __y,
		basic_string<_CharT, _Traits, _Alloc>* __abbrev,
		minutes* __offset)
    {
      return __is;
    }

  // WEEKDAY

  template<typename _CharT, typename _Traits>
    std::basic_ostream<_CharT, _Traits>&
    operator<<(std::basic_ostream<_CharT, _Traits>& __os, const weekday& __wd)
    {
      if (__wd.ok())
	{
	  _CharT __fmt[] = {'%', 'a', '\0'};
	  __os << format(__fmt, __wd);
	}
      else
	__os << unsigned{__wd} << " is not a valid weekday";
      return __os;
    }

  template<typename _CharT, typename _Traits>
    std::basic_ostream<_CharT, _Traits>&
    to_stream(std::basic_ostream<_CharT, _Traits>& __os, const _CharT* __fmt,
	      const weekday& __wd)
    {
      __os << format(__fmt, __wd);
      return __os;
    }

  template<typename _CharT, typename _Traits,
	   typename _Alloc = allocator<_CharT>>
    std::basic_istream<_CharT, _Traits>&
    from_stream(std::basic_istream<_CharT, _Traits>& __is, const _CharT* __fmt,
		weekday& __wd,
		basic_string<_CharT, _Traits, _Alloc>* __abbrev,
		minutes* __offset)
    {
      return __is;
    }

  // WEEKDAY_INDEXED

  template<typename _CharT, typename _Traits>
    std::basic_ostream<_CharT, _Traits>&
    operator<<(std::basic_ostream<_CharT, _Traits>& __os,
	       const weekday_indexed& __wdi)
    {
      __os << __wdi.weekday() << "[" << __wdi.index()
	   << (__wdi.ok() ? "]" : " is not a valid index]");
      return __os;
    }

  // WEEKDAY_LAST

  template<typename _CharT, typename _Traits>
    std::basic_ostream<_CharT, _Traits>&
    operator<<(std::basic_ostream<_CharT, _Traits>& __os,
	       const weekday_last& __wdl)
    {
      return __os << __wdl.weekday() << "[last]";
    }

  // MONTH_DAY

  template<typename _CharT, typename _Traits>
    std::basic_ostream<_CharT, _Traits>&
    operator<<(std::basic_ostream<_CharT, _Traits>& __os, const month_day& __md)
    {
      return __os << __md.month() << '/' << __md.day();
    }

  template<typename _CharT, typename _Traits>
    std::basic_ostream<_CharT, _Traits>&
    to_stream(std::basic_ostream<_CharT, _Traits>& __os,
	      const _CharT* __fmt, const month_day& __md)
    {
      return __os;
    }

  template<typename _CharT, typename _Traits,
	   typename _Alloc = allocator<_CharT>>
    std::basic_istream<_CharT, _Traits>&
    from_stream(std::basic_istream<_CharT, _Traits>& __is, const _CharT* __fmt,
		month_day& __md,
		basic_string<_CharT, _Traits, _Alloc>* __abbrev,
		minutes* __offset)
    {
      return __is;
    }

  // MONTH_DAY_LAST

  template<typename _CharT, typename _Traits>
    std::basic_ostream<_CharT, _Traits>&
    operator<<(std::basic_ostream<_CharT, _Traits>& __os,
	       const month_day_last& __mdl)
    {
      return __os << __mdl.month() << "/last";
    }

  // MONTH_WEEKDAY

  template<typename _CharT, typename _Traits>
    std::basic_ostream<_CharT, _Traits>&
    operator<<(std::basic_ostream<_CharT, _Traits>& __os,
	       const month_weekday& __mwd)
    {
      return __os << __mwd.month() << '/' << __mwd.weekday_indexed();
    }

  // MONTH_WEEKDAY_LAST

  template<typename _CharT, typename _Traits>
    std::basic_ostream<_CharT, _Traits>&
    operator<<(std::basic_ostream<_CharT, _Traits>& __os,
	       const month_weekday_last& __mwdl)
    {
      return __os << __mwdl.month() << '/' << __mwdl.weekday_last();
    }

  // YEAR_MONTH

  template<typename _CharT, typename _Traits>
    std::basic_ostream<_CharT, _Traits>&
    operator<<(std::basic_ostream<_CharT, _Traits>& __os,
	       const year_month& __ym)
    {
      return __os << __ym.year() << '/' << __ym.month();
    }

  template<typename _CharT, typename _Traits>
    std::basic_ostream<_CharT, _Traits>&
    to_stream(std::basic_ostream<_CharT, _Traits>& __os,
	      const _CharT* __fmt, const year_month& __ym)
    {
      return __os;
    }

  template<typename _CharT, typename _Traits,
	   typename _Alloc = allocator<_CharT>>
    std::basic_istream<_CharT, _Traits>&
    from_stream(std::basic_istream<_CharT, _Traits>& __is, const _CharT* __fmt,
		year_month& __ym,
		basic_string<_CharT, _Traits, _Alloc>* __abbrev,
		minutes* __offset)
    {
      return __is;
    }

  // YEAR_MONTH_DAY

  template<typename _CharT, typename _Traits>
    std::basic_ostream<_CharT, _Traits>&
    operator<<(std::basic_ostream<_CharT, _Traits>& __os,
	       const year_month_day& __ymd)
    {
      return __os;
    }

  template<typename _CharT, typename _Traits>
    std::basic_ostream<_CharT, _Traits>&
    to_stream(std::basic_ostream<_CharT, _Traits>& __os,
	      const _CharT* __fmt, const year_month_day& __ymd)
    {
      return __os;
    }

  template<typename _CharT, typename _Traits,
	   typename _Alloc = allocator<_CharT>>
    std::basic_istream<_CharT, _Traits>&
    from_stream(std::basic_istream<_CharT, _Traits>& __is, const _CharT* __fmt,
		year_month_day& __ymd,
		basic_string<_CharT, _Traits, _Alloc>* __abbrev,
		minutes* __offset)
    {
      return __is;
    }

  // YEAR_MONTH_DAY_LAST

  template<typename _CharT, typename _Traits>
    std::basic_ostream<_CharT, _Traits>&
    operator<<(std::basic_ostream<_CharT, _Traits>& __os,
	       const year_month_day_last& __ymdl)
    {
      return __os << __ymdl.year() << '/' << __ymdl.month_day_last();
    }

  // YEAR_MONTH_WEEKDAY

  template<typename _CharT, typename _Traits>
    std::basic_ostream<_CharT, _Traits>&
    operator<<(std::basic_ostream<_CharT, _Traits>& __os,
	       const year_month_weekday& __ymwdi)
    {
      return __os << __ymwdi.year()
		  << '/' << __ymwdi.month()
		  << '/' << __ymwdi.weekday_indexed();
    }

  // YEAR_MONTH_WEEKDAY_LAST

  template<typename _CharT, typename _Traits>
    std::basic_ostream<_CharT, _Traits>&
    operator<<(std::basic_ostream<_CharT, _Traits>& __os,
	       const year_month_weekday_last& __ymwdl)
    {
      return __os <<  __ymwdl.year()
		  << '/' <<  __ymwdl.month()
		  << '/' <<  __ymwdl.weekday_last();
    }

  // CALENDAR COMPOSITION OPERATORS

  template<typename _CharT, typename _Traits>
    std::basic_ostream<_CharT, _Traits>&
    operator<<(std::basic_ostream<_CharT, _Traits>& __os,
	       const time_of_day<hours>& __t)
    {
      return __os;
    }

  template<typename _CharT, typename _Traits>
    std::basic_ostream<_CharT, _Traits>&
    operator<<(std::basic_ostream<_CharT, _Traits>& __os,
	       const time_of_day<minutes>& __t);

  template<typename _CharT, typename _Traits>
    std::basic_ostream<_CharT, _Traits>&
    operator<<(std::basic_ostream<_CharT, _Traits>& __os,
	       const time_of_day<seconds>& __t)
    {
      return __os;
    }

  template<typename _CharT, typename _Traits, typename _Rep, typename _Period>
    std::basic_ostream<_CharT, _Traits>&
    operator<<(std::basic_ostream<_CharT, _Traits>& __os,
	       const time_of_day<duration<_Rep, _Period>>& __t)
    {
      return __os;
    }

  // INFORMATION CLASSES

  struct sys_info;
  template<typename _CharT, typename _Traits>
    std::basic_ostream<_CharT, _Traits>&
    operator<<(std::basic_ostream<_CharT, _Traits>& __os, const sys_info& __si)
    {
      return __os;
    }

  struct local_info;
  template<typename _CharT, typename _Traits>
    std::basic_ostream<_CharT, _Traits>&
    operator<<(std::basic_ostream<_CharT, _Traits>& __os,
		const local_info& __li)
    {
      return __os;
    }

  // ZONED_TIME

  template<typename _CharT, typename _Traits,
	   typename _Duration, typename _TimeZonePtr>
    std::basic_ostream<_CharT, _Traits>&
    operator<<(std::basic_ostream<_CharT, _Traits>& __os,
	       const zoned_time<_Duration, _TimeZonePtr>& __t)
    {
      return __os;
    }

  template<typename _CharT, typename _Traits,
	   typename _Duration, typename _TimeZonePtr>
    std::basic_ostream<_CharT, _Traits>&
    to_stream(std::basic_ostream<_CharT, _Traits>& __os, const _CharT* __fmt,
	      const zoned_time<_Duration, _TimeZonePtr>& __tp)
    {
      return __os;
    }

} // namespace chrono
} // namespace std

#endif // _GLIBCXX_DATE_IO_TCC

