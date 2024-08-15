// Copyright (c) 2020 The SPECTRESECURITY developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or https://www.opensource.org/licenses/mit-license.php.

#ifndef SPECTRESECURITY_SAPLING_TEST_FIXTURE_H
#define SPECTRESECURITY_SAPLING_TEST_FIXTURE_H

#include "test/test_spectresecurity.h"

/**
 * Testing setup that configures a complete environment for Sapling testing.
 */
struct SaplingTestingSetup : public TestingSetup {
    SaplingTestingSetup();
    ~SaplingTestingSetup();
};


#endif //SPECTRESECURITY_SAPLING_TEST_FIXTURE_H
