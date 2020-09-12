#include <cpr/cpr.h>
#include <fmt/core.h>
#include <fmt/ranges.h>

int main() {
  std::string hello = "hello";
  std::vector<char> world = { 'w', 'o', 'r', 'l', 'd' };
  fmt::print("{0}, {1}!\n", hello, world);
  return 0;
}