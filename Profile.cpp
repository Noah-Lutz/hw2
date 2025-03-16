#include "Profile.h"

#include <iostream>

std::ostream& operator<<(std::ostream& os, const Profile& p) {
    std::string output = "Username: " + p.username + "\n" +
                         "Age: " + std::to_string(p.age) + "\n" +
                         "State: " + p.state;
    os << output;
    return os;
}