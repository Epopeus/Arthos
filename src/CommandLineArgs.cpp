#include "CommandLineArgs.h"
#include <boost/program_options.hpp>

CommandLineArgs::CommandLineArgs(int argc_, const char** argv_):argc(argc_),argv(argv_) {
}

std::string CommandLineArgs::get(std::string name) {
    boost::program_options::options_description desc("Allowed options");
    desc.add_options()(name.c_str(), boost::program_options::value<std::string>());

    boost::program_options::variables_map vm;
    boost::program_options::store(boost::program_options::parse_command_line(argc, argv, desc), vm);
    boost::program_options::notify(vm);

    if (!vm.count(name))
        return "";

    return vm[name].as<std::string>();
}