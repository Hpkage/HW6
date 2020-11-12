// Source.cpp Hiromi Kageyama Nov. 11, 2020
// Write a c++ program that uses the <random> header to test both a uniform
// distribution of random numbers and a normal distribution of random numbers 
// using a std::map<int, int> to simulate a histogram

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <cmath>
#include <stdlib.h>

using std::random_device;

int RandomBetweenU(int first, int last) {
    // Seed with a real random value, if available
    random_device r;

    // Choose a random mean between 1 and 6
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(first, last);
    int mean = uniform_dist(e1);
    return mean;
}

int RandomBetweenN(float first, float last) {
    // Seed with a real random value, if available
    random_device r;

    // Choose a random mean between 1 and 6
    std::default_random_engine e1(r());
    std::normal_distribution<float> normal_dist(first, last);
    int mean =abs((int) normal_dist(e1)) % (int) (last - first + 1) + first;
    return mean;
}

int RandomBetween(int first, int last) {
    srand(time(0));
    int randNum = rand()%(last - first +1) + first;
    return randNum;
}

void PrintDistribution(const std::map<int, int>& numbers) {
    for (auto p : numbers) {
        std::cout << std::fixed << std::setprecision(1) << std::setw(2)
            << p.first << ' ' << std::string (p.second / 200, '*') << '\n';
    }
}

int main() {
    // Seed with a real random value, if available
    random_device r;

    int first = 1;
    int last = 6;
    int mean = RandomBetweenU(first, last);
    float mean2 = RandomBetweenN(first, last);
    int mean3 = RandomBetween(first, last);

    // Generate a normal distribution around that mean
    std::seed_seq seed2{ r(), r(), r(), r(), r(), r(), r(), r() };
    std::mt19937 e2(seed2);
    std::normal_distribution<> normal_dist(mean2, 2);

    std::uniform_int_distribution<> uniform_dist(mean, last);

    std::map<int, int> hist;
    std::map<int, int> hist2;

    for (int n = 0; n <10000; ++n) {
        ++hist[std::round(normal_dist(e2))];
    }
    std::cout << "Normal distribution around " << mean2 << ":\n";
    PrintDistribution(hist);
    std::cout << std::endl;

    for (int n = 0; n < 10000; ++n) {
        ++hist2[std::round(uniform_dist(e2))];
    }
    std::cout << "Uniform distribution around " << mean << ":\n";
    PrintDistribution(hist2);

    std::cout << "Rand distribution around " << mean3 << ":\n" << "\n";

    std::cout << mean3 << std::endl; 
}