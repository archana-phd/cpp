// 1. RAII - Resource Acquisition Is Initialization
struct File {
    File() { std::cout << "Opened\n"; }
    ~File() { std::cout << "Closed\n"; }
};
void useFile() { File f; }
//--
//--
//--
// 2. Range-based for loop
std::vector<int> nums = {1, 2, 3};
for (int n : nums) std::cout << n << '\n';
//--
//--
//--
// 3. auto type deduction
auto x = 42; // deduces int
//--
//--
//--
// 4. structured bindings (C++17)
std::pair<int, std::string> p = {1, "one"};
auto [id, name] = p;
//--
//--
//--
// 5. smart pointers (unique_ptr)
std::unique_ptr<int> p = std::make_unique<int>(10);
//--
//--
//--
// 6. lambda function
auto add = [](int a, int b) { return a + b; };
//--
//--
//--
// 7. constexpr function
constexpr int square(int x) { return x * x; }
//--
//--
//--
// 8. std::optional
std::optional<int> maybe(bool ok) {
    if (ok) return 10;
    return std::nullopt;
}
//--
//--
//--
// 9. std::variant + std::visit
std::variant<int, std::string> v = "hello";
std::visit([](auto&& val) { std::cout << val; }, v);
//--
//--
//--
// 10. enum class (scoped enum)
enum class Color { Red, Green, Blue };
//--
//--
//--
// 11. defaulted and deleted functions
struct A {
    A() = default;
    A(const A&) = delete;
};
//--
//--
//--
// 12. noexcept
int safe() noexcept { return 1; }
//--
//--
//--
// 13. move semantics
std::string a = "abc";
std::string b = std::move(a); // a is now empty
//--
//--
//--
// 14. initializer list constructor
std::vector<int> v = {1, 2, 3, 4};
//--
//--
//--
// 15. delegating constructors
struct S {
    int x;
    S() : S(0) {}
    S(int x) : x(x) {}
};
//--
//--
//--
// 16. uniform initialization
struct Point { int x, y; };
Point p{10, 20};
//--
//--
//--
// 17. type traits
template<typename T>
void printType() {
    if (std::is_integral_v<T>) std::cout << "int\n";
}
//--
//--
//--
// 18. std::any
std::any x = 42;
std::cout << std::any_cast<int>(x);
//--
//--
//--
// 19. std::tuple and tie
std::tuple<int, double, char> t = {1, 3.14, 'x'};
auto [a, b, c] = t;
//--
//--
//--
// 20. std::chrono for timing
auto start = std::chrono::steady_clock::now();
// do something
auto end = std::chrono::steady_clock::now();
//--
//--
//--
// 21. static_assert
static_assert(sizeof(int) == 4, "Expected 4-byte int");
//--
//--
//--
// 22. template specialization
template<typename T>
struct Foo {};
template<>
struct Foo<int> { static void bar() { std::cout << "int\n"; } };
//--
//--
//--
// 23. C++20 ranges
std::vector<int> v = {1, 2, 3, 4};
for (int x : v | std::views::filter([](int n){ return n % 2 == 0; }))
    std::cout << x;
//--
//--
//--
// 24. thread-local variable
thread_local int counter = 0;
//--
//--
//--
// 25. inline variables (C++17)
struct Config {
    inline static int version = 1;
};
//--
//--
//--
// 26. [[nodiscard]]
[[nodiscard]] int compute() { return 42; }
//--
//--
//--
// 27. if constexpr (C++17)
template<typename T>
void print(T t) {
    if constexpr (std::is_integral_v<T>) std::cout << "int\n";
    else std::cout << "not int\n";
}
//--
//--
//--
// 28. std::function
std::function<int(int, int)> op = [](int a, int b) { return a + b; };
//--
//--
//--
// 29. operator overloading
struct Vector2 {
    int x, y;
    Vector2 operator+(const Vector2& other) const {
        return {x + other.x, y + other.y};
    }
};
//--
//--
//--
// 30. custom deleter with unique_ptr
std::unique_ptr<FILE, decltype(&fclose)> f(fopen("file.txt", "r"), &fclose);
//--
//--
//--
// 31. tag dispatching
template<typename T>
void doStuffImpl(T, std::true_type) { std::cout << "integral\n"; }
template<typename T>
void doStuffImpl(T, std::false_type) { std::cout << "not integral\n"; }

template<typename T>
void doStuff(T x) {
    doStuffImpl(x, std::is_integral<T>{});
}
//--
//--
//--
// 32. CRTP (Curiously Recurring Template Pattern)
template<typename Derived>
struct Base {
    void interface() {
        static_cast<Derived*>(this)->implementation();
    }
};
struct Derived : Base<Derived> {
    void implementation() { std::cout << "Derived impl\n"; }
};
//--
//--
//--
// 33. named lambda (C++20)
auto square = [](int x) { return x * x; };
//--
//--
//--
// 34. std::bitset
std::bitset<8> bits("10101010");
//--
//--
//--
// 35. std::array over C-style arrays
std::array<int, 3> arr = {1, 2, 3};
//--
//--
//--
// 36. std::transform
std::vector<int> v = {1, 2, 3};
std::transform(v.begin(), v.end(), v.begin(), [](int x) { return x * 2; });
//--
//--
//--
// 37. std::accumulate
int sum = std::accumulate(v.begin(), v.end(), 0);
//--
//--
//--
// 38. std::reduce (C++17 parallel-friendly)
int result = std::reduce(v.begin(), v.end());
//--
//--
//--
// 39. std::span (C++20 view over array)
void print(std::span<int> s) {
    for (int x : s) std::cout << x << ' ';
}
//--
//--
//--
// 40. designated initializers (C++20)
struct Point { int x; int y; };
Point p = {.x = 5, .y = 10};
//--
//--
//--
// 41. co_await/coroutines (C++20)
#include <coroutine>
struct Task {
    struct promise_type {
        Task get_return_object() { return {}; }
        std::suspend_never initial_suspend() { return {}; }
        std::suspend_never final_suspend() noexcept { return {}; }
        void return_void() {}
        void unhandled_exception() {}
    };
};
Task example() { co_return; }
//--
//--
//--
// 42. dynamic_cast
struct Base { virtual ~Base() = default; };
struct Derived : Base {};
Base* b = new Derived;
Derived* d = dynamic_cast<Derived*>(b);
//--
//--
//--
// 43. consteval (C++20, evaluated at compile time)
consteval int magic() { return 42; }
constexpr int x = magic();
//--
//--
//--
// 44. [[likely]] and [[unlikely]] (C++20)
if (x > 0) [[likely]] {
    std::cout << "positive\n";
}
//--
//--
//--
// 45. concepts (C++20)
template<typename T>
concept Incrementable = requires(T t) { ++t; };

template<Incrementable T>
void inc(T& x) { ++x; }
//--
//--
//--
// 46. fold expressions (C++17)
template<typename... Args>
auto sum(Args... args) { return (... + args); }
//--
//--
//--
// 47. alias templates
template<typename T>
using Vec = std::vector<T>;
Vec<int> myInts;
//--
//--
//--
// 48. noexcept operator
template<typename T>
void f() {
    static_assert(noexcept(T()), "T must be noexcept default constructible");
}
//--
//--
//--
// 49. std::exchange
int a = 10;
int b = std::exchange(a, 0); // a = 0, b = 10
//--
//--
//--
// 50. override/final
struct Base { virtual void f() = 0; };
struct Derived : Base {
    void f() override final {}
};
