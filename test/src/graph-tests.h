#ifndef GRAPH_TESTS_H
#define GRAPH_TESTS_H

#include "gtest/gtest.h"
#include <sys/types.h>
#include <tuple>
#include <vector>
#include <list>
//#include <graph.h>
//#include <graph-presented.h>
//#include <graph-alg.h>
#include "../../graph/graph.h"
#include "../../graph/graph-presented.h"
#include "../../graph/graph-alg.h"

class GraphAlgorithmTests
    : public ::testing::TestWithParam< std::tuple<
            std::vector<int>,
            std::vector<Graph::Edge>,
            int >>
{};

#endif // GRAPH_TESTS_H
