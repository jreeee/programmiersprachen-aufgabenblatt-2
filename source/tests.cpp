#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "vec2.hpp"

TEST_CASE("testing vec2", "[vec2]")
{
  Vec2 a = {};
  REQUIRE(a.x == Approx(0.0f));
  REQUIRE(a.y == Approx(0.0f));

  Vec2 b = {5.1f,-9.3f};
  REQUIRE(b.x == Approx(5.1f));
  REQUIRE(b.y == Approx(-9.3f));
}
TEST_CASE("testing +", "[vec2]")
{
  Vec2 a = {1.3f,-2.7f};
  Vec2 b = {3.5f,4.2f};
  Vec2 c = {};
  Vec2 d = {-5.7f,3.6f};
  Vec2 e = {-6.1f,-9.7f};
  Vec2 tmp = a += b;
  REQUIRE(tmp.x == Approx(4.8f));
  REQUIRE(tmp.y == Approx(1.5f));
}
int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
