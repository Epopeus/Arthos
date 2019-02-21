#pragma once

#include <boost/multi_index_container.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/member.hpp>
#include <common/entity/Guid.h>

struct Test {
    Guid id;
    std::string name;
};
using namespace boost::multi_index;

using MyIndex = boost::multi_index_container<
        Test,
        indexed_by<
                hashed_unique<member<Test, Guid, &Test::id>>,
                hashed_unique<member<Test, std::string, &Test::name>>
                >
        >;
