// Copyright (c) 2020-2021 The SPECTRESECURITY Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or https://www.opensource.org/licenses/mit-license.php.

#ifndef SPECTRESECURITY_SAPLING_TEST_FIXTURE_H
#define SPECTRESECURITY_SAPLING_TEST_FIXTURE_H

#include "test/test_spectresecurity.h"

/**
 * Testing setup that configures a complete environment for Sapling testing.
 */
struct SaplingTestingSetup : public TestingSetup
{
    SaplingTestingSetup(const std::string& chainName = CBaseChainParams::MAIN);
    ~SaplingTestingSetup();
};

/**
 * Regtest setup with sapling always active
 */
struct SaplingRegTestingSetup : public SaplingTestingSetup
{
    SaplingRegTestingSetup();
};


#endif //SPECTRESECURITY_SAPLING_TEST_FIXTURE_H
