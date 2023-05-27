//===- BoostBfs.cpp -----------------------------------===//
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
//===----------------------------------------------------------------------===//
//
// This file implements the benchmark for Boost Breadth First search example
// benchmark.
//
//===----------------------------------------------------------------------===//

#include <Utility/Utils.h>
#include <benchmark/benchmark.h>
#include <boost/config.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/breadth_first_search.hpp>
#include <boost/graph/exterior_property.hpp>
#include <boost/graph/undirected_graph.hpp>
#include <iostream>
#include <vector>

using namespace std;

#define SIZE 1000

namespace {
// define the graph type
typedef boost::adjacency_list<boost::vecS, boost::hash_setS, boost::undirectedS,
                              uint32_t, uint32_t, boost::no_property>
    Graph;

struct my_visitor : boost::default_bfs_visitor {

  void initialize_vertex(const Graph::vertex_descriptor &s,
                         const Graph &g) const {
    std::cout << "Initialize: " << g[s] << std::endl;
  }
  void discover_vertex(const Graph::vertex_descriptor &s,
                       const Graph &g) const {
    std::cout << "Discover: " << g[s] << std::endl;
  }
  void examine_vertex(const Graph::vertex_descriptor &s, const Graph &g) const {
    std::cout << "Examine vertex: " << g[s] << std::endl;
  }
  void examine_edge(const Graph::edge_descriptor &e, const Graph &g) const {
    std::cout << "Examine edge: " << g[e] << std::endl;
  }
  void tree_edge(const Graph::edge_descriptor &e, const Graph &g) const {
    std::cout << "Tree edge: " << g[e] << std::endl;
  }
  void non_tree_edge(const Graph::edge_descriptor &e, const Graph &g) const {
    std::cout << "Non-Tree edge: " << g[e] << std::endl;
  }
  void gray_target(const Graph::edge_descriptor &e, const Graph &g) const {
    std::cout << "Gray target: " << g[e] << std::endl;
  }
  void black_target(const Graph::edge_descriptor &e, const Graph &g) const {
    std::cout << "Black target: " << g[e] << std::endl;
  }
  void finish_vertex(const Graph::vertex_descriptor &s, const Graph &g) const {
    std::cout << "Finish vertex: " << g[s] << std::endl;
  }
};

Graph g(SIZE);
vector<Graph::vertex_descriptor> nodes(SIZE);
my_visitor vis;
} // namespace

void initializeBoostBfs() {

  const int vertices = SIZE;
  int num_edges = vertices * (vertices - 1) / 2;

  std::vector<int> edges;
  std::vector<int> weight;

  graph::generateRandomGraph(edges, weight, vertices);

  for (int i = 0; i < SIZE; i++) {
    nodes[i] = boost::vertex(i, g);
    g[nodes[i]] = i;
  }

  for (std::size_t k = 0; k < num_edges; ++k)
    boost::add_edge(nodes[edges[k * 2] - 1], nodes[edges[k * 2 + 1] - 1],
                    weight[k], g);
}

// Benchmarking function.
static void Boost_Bfs(benchmark::State &state) {

  for (auto _ : state) {
    for (int i = 0; i < state.range(0); ++i) {
      breadth_first_search(
          g, nodes[0],
          boost::visitor(vis).vertex_index_map(get(boost::vertex_bundle, g)));
    }
  }
}

// Register benchmarking function.
// BENCHMARK(Boost_Bfs)->Arg(1);

void generateResultBoostBfs() {
  initializeBoostBfs();
  cout << "-------------------------------------------------------\n";
  cout << "[ BOOST BFS Result Information ]\n";
  // breadth_first_search(
  //     g, nodes[0], boost::visitor(vis).vertex_index_map(get(boost::vertex_bundle, g)));
  cout << "Boost BFS operation finished!\n";
}