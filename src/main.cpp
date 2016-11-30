// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "card.h"

auto main(int /*argc*/, char* [] /*argv*/) -> int
{
	std::ofstream ofs("filename.xml");

	auto c = SM::card{};

	boost::archive::xml_oarchive oa(ofs);
	oa << BOOST_SERIALIZATION_NVP(c);
    return 0;
}

