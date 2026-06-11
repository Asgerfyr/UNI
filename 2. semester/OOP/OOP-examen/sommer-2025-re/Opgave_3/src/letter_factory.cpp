#include "letter_factory.h"

std::vector<std::string> create_e() {
    std::vector<std::string> res;
    res.emplace_back("EEEEEEE ");
    res.emplace_back("E       ");
    res.emplace_back("E       ");
    res.emplace_back("EEEEE   ");
    res.emplace_back("E       ");
    res.emplace_back("E       ");
    res.emplace_back("EEEEEEE ");
    return res;
}

std::vector<std::string> create_x() {
    std::vector<std::string> res;
    res.emplace_back("X     X ");  // 8 characters
    res.emplace_back(" X   X  ");  // 8
    res.emplace_back("  X X   ");  // 8
    res.emplace_back("   X    ");  // 8
    res.emplace_back("  X X   ");  // 8
    res.emplace_back(" X   X  ");  // 8
    res.emplace_back("X     X ");  // 8
    return res;
}

std::vector<std::string> create_a() {
    std::vector<std::string> res;
    res.emplace_back("   AA   ");
    res.emplace_back("  A  A  ");
    res.emplace_back(" A    A ");
    res.emplace_back(" AAAAAA ");
    res.emplace_back(" A    A ");
    res.emplace_back(" A    A ");
    res.emplace_back(" A    A ");
    return res;
}

std::vector<std::string> create_m() {
    std::vector<std::string> res;
    res.emplace_back("M     M ");
    res.emplace_back("MM   MM ");
    res.emplace_back("M M M M ");
    res.emplace_back("M  M  M ");
    res.emplace_back("M     M ");
    res.emplace_back("M     M ");
    res.emplace_back("M     M ");
    return res;
}

std::vector<std::string> create_space() {
    std::vector<std::string> res;
    res.emplace_back("   ");
    res.emplace_back("   ");
    res.emplace_back("   ");
    res.emplace_back("   ");
    res.emplace_back("   ");
    res.emplace_back("   ");
    res.emplace_back("   ");
    return res;
}

std::vector<std::string> create_wrong_height() {
    std::vector<std::string> res;
    res.emplace_back("EEEEEEE ");
    res.emplace_back("E       ");
    res.emplace_back("E       ");
    res.emplace_back("EEEEE   ");
    res.emplace_back("E       ");
    res.emplace_back("E       ");
    return res;
}
