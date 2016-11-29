// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

static_assert(sizeof(void*) == 8, "64-bit compilation only");

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

#include <algorithm>
#include <chrono>
#include <experimental\filesystem>
#include <iostream>
#include <string>
#include <vector>

#include <boost\algorithm\algorithm.hpp>
#include <boost\algorithm\string.hpp>
#include <boost\concept_check.hpp>
#include <boost\core\swap.hpp>
#include <boost\iterator.hpp>
#include <boost\range.hpp>
#include <boost\range\adaptors.hpp>
#include <boost\range\algorithm.hpp>
#include <boost\range\algorithm_ext.hpp>
#include <boost\ratio.hpp>
#include <boost\optional.hpp>
#include <boost\logic\tribool.hpp>
#include <boost\logic\tribool_io.hpp>
#include <boost\variant.hpp>
#include <boost\utility\string_view.hpp>

#include <gsl\gsl_algorithm>
#include <gsl\gsl_assert>
#include <gsl\gsl_util>
#include <gsl\span>

#define GSL_EXPECTS(cond) Expects(cond)
#define GSL_ENSURES(cond) Ensures(cond)

namespace SM
{
//for easy upgrade to std:: versions of these boost libs
template<typename... T>
using variant = boost::variant<T...>;

template<typename T>
using optional = boost::optional<T>;

using tribool = boost::logic::tribool;

using string_view = boost::string_view;
using wstring_view = boost::wstring_view;

using namespace boost::algorithm;
using boost::swap;
}

namespace adapt = boost::adaptors;
namespace fs = std::experimental::filesystem;
