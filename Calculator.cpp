#include <iostream>
#include <random>
using namespace std;

const uint32_t MAGIC_NUMBER = 0xCAFE;
typedef uint32_t name_hash;

name_hash calc_name_hash(string name) {
  uint32_t hash = 0;
  int i = 0;

  // magic calculation
  for (char c : name) {
    uint32_t x = (uint32_t)c;
    x = (x >> i) | (x << (32 - i));
    hash += x;
    i = ++i % 32;
  }

  return hash;
}

void calculate_scores(name_hash h1, name_hash h2) {
  const uint32_t MIN = 40;
  const uint32_t MAX = 100;

  uint32_t num = h1 ^ h2;
  num ^= MAGIC_NUMBER;

  mt19937 rng(num);
  uniform_int_distribution<> magic(MIN, MAX);

  cout << "в Любви:       " << magic(rng) << "%" << endl;
  cout << "в Браке:       " << magic(rng) << "%" << endl;
  cout << "в Сексе:       " << magic(rng) << "%" << endl;
  cout << "в Отношениях:  " << magic(rng) << "%" << endl;
}

int main() {
  string name_1, name_2;
  
  cout << "Enter name 1: ";
  cin >> name_1;
  
  cout << "Enter name 2: ";
  cin >> name_2;

  name_hash h2 = calc_name_hash(name_1);
  name_hash h1 = calc_name_hash(name_2);

  cout << endl << "Совместимость имен:" << endl;
  calculate_scores(h1, h2);
}
