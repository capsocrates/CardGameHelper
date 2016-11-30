#pragma once

#pragma warning ( push, 1 )

#include "stdafx.h"

#include <boost\serialization\string.hpp>
#include <boost\serialization\vector.hpp>
#include <boost\serialization\variant.hpp>
#pragma warning ( pop )

namespace SM
{

struct no_prerequisites {
	template<class Archive>
	void serialize(Archive& /*ar*/, const unsigned int /*version*/) {}
};

struct prerequisite
{
	template<class Archive>
	void serialize(Archive& ar, const unsigned int /*version*/)
	{
		ar & BOOST_SERIALIZATION_NVP(card_name);
	}	//end function serialize

	std::string card_name;
};	//end class prerequisite

using prerequisites = variant<no_prerequisites, std::vector<prerequisite>>;

struct no_keyword {
	template<class Archive>
	void serialize(Archive& /*ar*/, const unsigned int /*version*/) {}
};

struct keyword
{
	template<class Archive>
	void serialize(Archive& ar, const unsigned int /*version*/)
	{
		ar & BOOST_SERIALIZATION_NVP(value);
	}	//end function serialize

	std::string value;
};	//end class keyword

using keywords = variant<no_keyword, std::vector<keyword>>;

class card
{
	friend class boost::serialization::access;
	std::string name{"card_name"};
	prerequisites prerequisites;
	keywords keywords;

	std::string effect_text{"some effects!"};

	template<class Archive>
	void serialize(Archive& ar, const unsigned int /*version*/)
	{
		ar & BOOST_SERIALIZATION_NVP(name);
		ar & BOOST_SERIALIZATION_NVP(prerequisites);
		ar & BOOST_SERIALIZATION_NVP(keywords);
		ar & BOOST_SERIALIZATION_NVP(effect_text);
	}	//end function serialize
};	//end class card

}	//end namespace SM
