#include <gtest/gtest.h>
#include "daemons/logind/LoginDaemon.h"

TEST(LoginDaemon, ShouldStart) {
    LoginDaemon logind = LoginDaemon();
    ASSERT_TRUE(true);
}