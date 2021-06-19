#include <iostream>
#include <optional>
#include "matchit.h"

template <typename T>
constexpr auto square(std::optional<T> const &t)
{
    using namespace matchit;
    Id<T> id;
    return match(t)(
        // clang-format off
        pattern(some(id)) = id * id,
        pattern(none)     = expr(0)
        // clang-format on
    );
}
constexpr auto x = std::make_optional(5);
static_assert(square(x) == 25);

int main()
{
    auto t = std::make_optional(3);
    std::cout << square(t) << std::endl;
    return 0;
}
