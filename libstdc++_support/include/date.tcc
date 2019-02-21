#ifndef _GLIBCXX_DATE_TCC
#define _GLIBCXX_DATE_TCC 1

#pragma GCC system_header

namespace std {
namespace chrono {

  template<typename _CharT, typename _Streamable>
    basic_string<_CharT>
    format(const _CharT* __fmt, const _Streamable& __s);

  template<typename _CharT, typename _Streamable>
    basic_string<_CharT>
    format(const locale& __loc, const _CharT* __fmt, const _Streamable& __s);

  template<typename _CharT, typename _Traits,
	   typename _Alloc, typename _Streamable>
    basic_string<_CharT, _Traits, _Alloc>
    format(const basic_string<_CharT, _Traits, _Alloc>& __fmt,
	   const _Streamable& __s);

  template<typename _CharT, typename _Traits,
	   typename _Alloc, typename _Streamable>
    basic_string<_CharT, _Traits, _Alloc>
    format(const locale& __loc,
	   const basic_string<_CharT, _Traits, _Alloc>& __fmt,
	   const _Streamable& __s);

} // namespace chrono
} // namespace std

#endif // _GLIBCXX_DATE_TCC
