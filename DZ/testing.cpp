#include <iostream>
#include <random>
#include <fstream>
#include <vector>

using namespace std;

class FastRandom {
private:
    unsigned long long rnd;
public:
    FastRandom() {
        rnd = 1;
    }
    void seed(unsigned long long seed) {
        rnd = seed;
    }
    unsigned long long rand() {
        rnd ^= rnd << 21;
        rnd ^= rnd >> 35;
        rnd ^= rnd << 4;
        return rnd;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    const int N = 50, M = 100000;
    FastRandom r;
    r.seed(time(NULL));
    ofstream fout("generate.txt");
    fout << N << " " << M << endl;

    for (int i = 0; i < M; i++) {
        int s = r.rand()%100;
        fout << s << "\n";
    }
    fout << endl;

    fout.close();
    return 0;
}