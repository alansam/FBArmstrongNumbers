/*
 *  @see: https://atechdaily.com/posts/algorithm-for-armstrong-number
 *  @see: https://en.wikipedia.org/wiki/Narcissistic_number
 *  @see: https://rosettacode.org/wiki/Narcissistic_decimal_number
 *  @see: https://oeis.org/A005188
 *  @see: https://mathworld.wolfram.com/NarcissisticNumber.html
 *  @see:
 */

#include <iostream>
#include <iomanip>
#include <vector>

bool is_armstrong(uint64_t nr);
bool isArmstrongNumber(uint64_t candidate);

/*
 *  MARK: main()
 */
int main(int argc, char const * argv[]) {
  std::cout << "321-ArmstrongNumbers\n";
  auto results = std::vector<uint64_t>();
  for (uint64_t result = 1ull; results.size() <= 25; ++result) {
    std::clog << "1: " << result << '\n';
    if (isArmstrongNumber(result)) {
      std::clog << "2: " << result << '\n';
      results.push_back(result);
    }
    // if (result == 153ull) { break; }
  }

  for (auto cc = 1ul; auto anum : results) {
    std::cout << std::setw(7) << anum << (cc++ % 5 == 0 ? "\n" : "");
  }

  return 0;
}

/*
 *  MARK: is_armstrong()
 *          1,          2,           3,           4,         5,
 *          6,          7,           8,           9,       153,
 *        370,        371,         407,        1634,      8208,
 *       9474,      54748,       92727,       93084,    548834,
 *    1741725,    4210818,     9800817,     9926315,  24678050,
 *   24678051,   88593477,   146511208,   472335975, 534494836,
 *  912985153, 4679307774, 32164049650, 32164049651
 *
 *  UINT_MAX   =           4294967295U
 *  ULONG_MAX  = 18446744073709551615UL
 *  ULLONG_MAX = 18446744073709551615ULL
 */
bool is_armstrong(uint64_t nr) {
  auto sum { 0ull };
  auto nr_save { nr };
  std::clog << "..1: " << nr_save << '\n';

  while (nr >= 0ull) {
    auto nrem = (nr % 10ull);
    std::clog << "..2: " << nrem << '\n';
    sum += nrem * nrem * nrem;
    std::clog << "..3: " << sum << '\n';
    nr /= 10ull;
    std::clog << "..4: " << nr << '\n';
    break;
  }

  std::clog << std::boolalpha;
  std::clog << "..5: " << (sum == nr_save) << '\n';
  return (sum == nr_save);
}

bool isArmstrongNumber(uint64_t candidate) {
  auto getNumberOfDigits = [](uint64_t nr) -> uint64_t {
    auto sum = 0ull;
    while (nr != 0ull) {
      nr /= 10ull;
      ++sum;
    }
    return sum;
  };

  auto numberOfDigits = getNumberOfDigits(candidate);
  auto sum = 0ull;
  for (auto i_ = candidate; i_ != 0ull; i_ /= 10ull) {
    auto num = i_ % 10ull;
    auto n_ = 1ull;
    for (auto j_ = 0ull; j_ < numberOfDigits; ++j_) {
		  n_ *= num;
	  }
    sum += n_;
  }

  return sum == candidate;
}
