#ifndef GRAPH_PROVIDER_H
#define GRAPH_PROVIDER_H

#include "graph-tests.h"
#include "gtest/gtest.h"
#include <tuple>
#include <vector>

INSTANTIATE_TEST_CASE_P(
        Graph,
        GraphAlgorithmTests,
        ::testing::Values(
            std::make_tuple(
                static_cast<std::vector<int>>({0, 1, 2, 3, 4),
                static_cast<std::vector<std::list<int>>>(
                    {
                        {},
                        {},
                        {},
                        {},
                        {}
                    }
                    )
                );
            );

#endif
