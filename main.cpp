#include "Profile.h"
#include "Twitter.cpp"

#include <iostream>

int main() {
    Profile profile1 {"Abraham Lincoln", 45, "IL"};
    Profile profile2 {"Theodore Roosevelt", 66, "NY"};
    Profile profile3 {"Andrew Jackson", 59, "WI"};
    Profile profile4 {"Gerald Ford", 85, "MI"};
    Profile profile5 {"Barack Obama", 23, "HI"};

    std::string string1 = "Abraham Lincoln";
    std::string string2 = "Theodore Roosevelt";
    std::string string3 = "Andrew Jackson";
    std::string string4 = "Gerald Ford";
    std::string string5 = "Barack Obama";

    std::string user1 = "Thomas Jefferson";
    Profile user2 {"George Washington", 35, "WA"};

    Twitter<std::string> twitter1(user1);
    Twitter<Profile> twitter2(user2);

    std::cout << "---------- First with string ----------" << std::endl;
    twitter1.AddFollower(string1);
    twitter1.AddFollower(string2);
    twitter1.AddFollower(string3);
    twitter1.AddFollower(string4);
    twitter1.AddFollower(string5);
    twitter1.RemoveFollower(string3);
    std::cout << "----------------------" << std::endl;

    std::cout << "---------- Second with Profile ----------" << std::endl;
    twitter2.AddFollower(profile1);
    twitter2.AddFollower(profile2);
    twitter2.AddFollower(profile3);
    twitter2.AddFollower(profile4);
    twitter2.AddFollower(profile5);
    twitter2.RemoveFollower(profile3);
    std::cout << "----------------------" << std::endl;

    return 0;
}
