//===- lemonBFS.cpp -------------------------------------------------------===//
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
// This file implements the benchmark for Lemon BFS example benchmark.
//
//===----------------------------------------------------------------------===//

#include <benchmark/benchmark.h>
#include <bits/stdc++.h>
#include <lemon/bfs.h>
#include <lemon/list_graph.h>

using namespace std;
using namespace lemon;

#define V 2000
#define MaxWeight 900
#define UpperLimit 100
#define LowerLimit 2

typedef ListDigraph::ArcMap<int> LengthMap;

namespace {
ListDigraph g;
ListDigraph::Node source;
LengthMap length(g);
ListDigraph::Node nodes[V];
} // namespace

void initializeLemonBFS() {
  // ListDigraph::Node nodes[V];

  // for (int i = 0; i < V; i++)
  //   nodes[i] = g.addNode();

  // source = nodes[0];

  // int vertices = V;
  // int NUM = vertices;
  // int MAX_EDGES = vertices * (vertices - 1) / 2;
  // int NUMEDGE = MAX_EDGES;

  // for (int i = 1; i <= NUMEDGE; i++) {
  //   ListDigraph::Node a = nodes[rand() % V];
  //   ListDigraph::Node b = nodes[rand() % V];

  //   g.addArc(a, b);
  // }

  // Bfs<ListDigraph> bfs(g);

  for (int i = 0; i < V; i++) {
    nodes[i] = g.addNode();
  }

  source = nodes[0];

  std::set<std::pair<int, int>> container;
  std::set<std::pair<int, int>>::iterator it;
  srand(time(NULL));

  int NUM = V;
  int MAX_EDGES = V * (V - 1) / 2;
  int NUMEDGE = MAX_EDGES;

  for (int j = 1; j <= NUMEDGE; j++) {
    int a = rand() % NUM;
    int b = rand() % NUM;
    std::pair<int, int> p = std::make_pair(a, b);
    std::pair<int, int> reverse_p = std::make_pair(b, a);

    while (container.find(p) != container.end() ||
           container.find(reverse_p) != container.end()) {
      a = rand() % NUM;
      b = rand() % NUM;
      p = std::make_pair(a, b);
      reverse_p = std::make_pair(b, a);
    }

    container.insert(p);
    length[g.addArc(nodes[a], nodes[b])] = 1 + rand() % MaxWeight;
  }

  Bfs<ListDigraph> bfs(g);
}

// Benchmarking function.
static void Lemon_BFS(benchmark::State &state) {
  for (auto _ : state) {
    Bfs<ListDigraph> bfs(g);
    for (int i = 0; i < state.range(0); ++i) {
      bfs.run(source);
    }
  }
}

// Register benchmarking function.
BENCHMARK(Lemon_BFS)->Arg(1);

void generateResultLemonBFS() {
  initializeLemonBFS();
  cout << "-------------------------------------------------------\n";
  cout << "[ LEMON BFS Result Information ]\n";
  Bfs<ListDigraph> output(g);
  output.run(source);
  cout << "Lemon bfs operation finished!\n";
}
