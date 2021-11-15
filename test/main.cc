//
// Created by jacob on 11/10/21.
//

#include <cstdlib>
#include <ctime>
#include <fstream>
#include "trees/binary_tree.h"
#include "trees/binary_search_tree.h"
#include "trees/timer.h"

using namespace std;

double TestFind(int num, BinaryTree<int>* tree) {
  Timer timer;
  for (int i = 0; i < num - 1; i++) {
    tree->Insert(rand() % num);
  }
  int num_to_find = num / 10;
  tree->Insert(num_to_find);

  timer.Start();
  tree->Find(num_to_find);
  timer.Stop();

  return timer.ElapsedSeconds();
}

double TestInsert(int num, BinaryTree<int>* tree) {
  Timer timer;
  timer.Start();
  for (int i = 0; i < num; i++) {
    tree->Insert(rand() % num);
  }
  timer.Stop();

  return timer.ElapsedSeconds();
}

int main(int argc, char **argv) {

  int nums[] = {8000, 16000, 32000, 64000, 128000, 256000, 512000, 1024000};

  srand(time(nullptr));

  double (*test_funcs[])(int, BinaryTree<int>*) = {TestInsert, TestFind};
  BinarySearchTree<int> binary_search_tree;
  BinaryTree<int>* tree = &binary_search_tree;
  for (int i = 1; i < argc; i++) {
    ofstream outfile(argv[i]);
    for (auto num: nums) {
      outfile << num << "," << test_funcs[i - 1](num, tree) << std::endl;
    }
  }

  return 0;
}
