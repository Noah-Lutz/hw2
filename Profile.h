#ifndef PROFILE_H
#define PROFILE_H

#include <string>

struct Profile {
    std::string username;
    int age;
    std::string state;

    bool operator ==(const Profile& other) const {
        return username == other.username &&
            age == other.age &&
                state == other.state;
    }
};

inline std::ostream& operator<<(std::ostream& os, const Profile& p) {
    std::string output = "Username: " + p.username + "\n" +
                         "Age: " + std::to_string(p.age) + "\n" +
                         "State: " + p.state;
    os << output;
    return os;
}

#endif //PROFILE_H
