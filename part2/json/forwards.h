#ifndef JSON_FORWARDS_H_INCLUDED
# define JSON_FORWARDS_H_INCLUDED

# include "config.h"

namespace Json {

   // writer.h
   class FastWriter;
   class StyledWriter;

   // reader.h
   class Reader;

   // features.h
   class Features;

   // value.h
   typedef int Int;
   typedef unsigned int UInt;

#if defined(WIN32) || defined(WIN64)
   typedef __int64 Int64;
   typedef unsigned __int64 UInt64;
	#define _JSON_I64FMT_ "%I64d"
	#define _JSON_U64FMT_ "%I64u"
#elif defined(LINUX32)
   typedef long long Int64;
   typedef unsigned long long UInt64;
   	#define _JSON_I64FMT_ "%lld"
	#define _JSON_U64FMT_ "%llu"
#elif defined(LINUX64)
   typedef long Int64;
   typedef unsigned long UInt64;
   	#define _JSON_I64FMT_ "%ld"
	#define _JSON_U64FMT_ "%lu"
#else
	#pragma error("WIN32|WIN64|LINUX32|LINUX64 should defined to determine os platform to LibJson")
#endif

   class StaticString;
   class Path;
   class PathArgument;
   class Value;
   class ValueIteratorBase;
   class ValueIterator;
   class ValueConstIterator;
#ifdef JSON_VALUE_USE_INTERNAL_MAP
   class ValueAllocator;
   class ValueMapAllocator;
   class ValueInternalLink;
   class ValueInternalArray;
   class ValueInternalMap;
#endif // #ifdef JSON_VALUE_USE_INTERNAL_MAP

} // namespace Json


#endif // JSON_FORWARDS_H_INCLUDED
