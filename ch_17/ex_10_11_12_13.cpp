// -----------------------------------------------------------------------------
// File:        ex_10_11_12_13.cpp
// Author:      Erkam Uzuncayir
// Date:        25/06/2025
// -----------------------------------------------------------------------------

#include <bitset>
#include <iostream>
#include <vector>

template <std::size_t N>
class Response
{
public:
    Response() = default;
    explicit Response(const std::string &s) : answer(s) {}
    std::bitset<N> get_answer() const { return answer; }
    void           update_answer(const std::size_t pos, bool is_on) { answer.set(pos, is_on); }
    std::size_t    grade(Response &solution, Response &user)
    {
        auto result = solution.get_answer() ^ user.get_answer();
        result.flip();
        return result.count();
    }

private:
    std::bitset<N> answer;
};


int main()
{
    // ex_10
    std::bitset<32>  bits_direct;
    std::bitset<32>  bits_default;
    std::vector<int> positions = {1, 2, 3, 5, 8, 13, 21};

    for (int pos : positions)
    {
        bits_direct.set(pos);
    }

    for (int pos : positions)
    {
        bits_default.set(pos);
    }
    std::cout << "Bitset after direct initialization: " << bits_direct << "\n";
    std::cout << "Bitset after default initialization: " << bits_default << "\n";

    // ex_11
    // You should instantiate with 100 binary-digit.
    Response<10> response("1010101010");
    Response<10> solutions("1000000000");
    std::cout << response.get_answer() << "\n";

    // ex_12
    response.update_answer(2, true);
    std::cout << response.get_answer() << "\n";

    // ex_13
    std::cout << response.grade(solutions, response) << "\n";
}
