#ifndef TWITTER_H
#define TWITTER_H

#include "Array.h"

template<typename T> class Twitter {
public:
    Twitter(T user);
    void AddFollower(T& t);
    void RemoveFollower(T& t);
    void PrintFollowers();
private:
    T user;
    Array<T> followers;
    int followerCount;
};

#endif //TWITTER_H
