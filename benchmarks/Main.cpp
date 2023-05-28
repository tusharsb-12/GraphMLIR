//===- Main.cpp -----------------------------------------------------------===//
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
// This is the main file of the Graph processing Algorithm benchmark.
//
//===----------------------------------------------------------------------===//

#include <benchmark/benchmark.h>

void initializeBoostBfs();
void initializeLemonBFS();
void initializeGraphMLIRBfs();
void initializeGraphMLIRFloydWarshall();
void initializeFloydWarshall();
void initializeBoostFLoydWarshall();
void initializeGraphMLIRBellmanFord();
void initializeLemonBellmanFord();
void initializeBoostBellmanFord();

void generateResultBoostBfs();
void generateResultLemonBFS();
void generateResultGraphMLIRBfs();
void generateResultGraphMLIRFloydWarshall();
void generateResultFloydWarshall();
void generateResultBoostFLoydWarshall();
void generateResultGraphMLIRBellmanFord();
void generateResultLemonBellmanFord();
void generateResultBoostBellmanFord();

int main(int argc, char **argv) {

  initializeBoostBfs();
  initializeLemonBFS();
  initializeGraphMLIRBfs();
  initializeGraphMLIRFloydWarshall();
  initializeFloydWarshall();
  initializeBoostFLoydWarshall();
  initializeGraphMLIRBellmanFord();
  initializeLemonBellmanFord();
  initializeBoostBellmanFord();

  ::benchmark::Initialize(&argc, argv);
  ::benchmark::RunSpecifiedBenchmarks();

  generateResultBoostBfs();
  generateResultLemonBFS();
  generateResultGraphMLIRBfs();
  generateResultGraphMLIRFloydWarshall();
  generateResultFloydWarshall();
  generateResultBoostFLoydWarshall();
  generateResultGraphMLIRBellmanFord();
  generateResultLemonBellmanFord();
  generateResultBoostBellmanFord();

  return 0;
}
