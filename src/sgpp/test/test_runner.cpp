/*
 * test_runner.cpp
 *
 *  Created on: Dec 19, 2014
 *      Author: pfandedd
 */

#include <iostream>
#include <vector>

#include "test/TestSuite.hpp"

#include "datadriven/test/OperationMultipleEvalBaseTestSuite.hpp"
#include "datadriven/test/OperationMultipleEvalStreamingTestSuite.hpp"
#include "datadriven/test/OperationMultipleEvalSubspaceTestSuite.hpp"
#include "datadriven/test/LearnerLeastSquaresIdentityTestSuite.hpp"
#include "datadriven/test/MetaLearnerTestSuite.hpp"

//include tests suites here

int main(int argc, char **argv) {

    std::cout << "creating unittests: ";

    //enumerate test suites here, add your test suite here
    std::vector<sg::test::TestSuite *> testSuites = {
//        new sg::test::OperationMultipleEvalBaseTestSuite(),
//        new sg::test::OperationMultipleEvalStreamingTestSuite(),
        new sg::test::OperationMultipleEvalSubspaceTestSuite(),
//        new sg::test::LearnerLeastSquaresIdentityTestSuite(),
//        new sg::test::MetaLearnerTestSuite()
    };

    std::cout << "OK" << std::endl;
    std::cout << "running test suites:" << std::endl;

    bool overallSuccess = true;

    for (sg::test::TestSuite *testSuite : testSuites) {
        std::cout << "processing test suite \"" << testSuite->getName() << "\"" << std::endl;
        testSuite->runAllTests();
        if (testSuite->getSuccessState()) {
            std::cout << testSuite->getName() << ": OK" << std::endl;
        } else {
            std::cout << testSuite->getName() << ": failed" << std::endl;
            overallSuccess = false;
        }
        delete testSuite;
    }

    if (overallSuccess) {
        std::cout << "unittester finished: OK" << std::endl;
    } else {
        std::cout << "unittester finished: failed" << std::endl;
    }

    return 0;
}


