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

#endif //PROFILE_H
