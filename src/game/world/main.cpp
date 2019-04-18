#include <common/di/boost/BoostFactory.h>
#include "WorldApp.h"

int main(int argc, const char** argv) {
    BoostFactory<WorldApp, int, const char**> appFactory;
    WorldApp app = appFactory.create(argc, argv);
    app.run();
}