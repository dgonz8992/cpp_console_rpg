#include <random>

int  RNG(const int min, const int max)
{
    static std::random_device randomDevice;
    static std::mt19937 generator(randomDevice());

    std::uniform_int_distribution<int> distribution(min, max);

    return distribution(generator);
}