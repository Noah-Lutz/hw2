#include "Twitter.h"

#include <iostream>
#include <ostream>

template<typename T>
Twitter<T>::Twitter(T user) : user(user), followers(2), followerCount(0) {
}

template<typename T>
void Twitter<T>::AddFollower(T& t) {
    if (followerCount == followers.length()) {
        followers.changeSize(followers.length() * 2);
    }

    followers[followerCount] = t;
    followerCount++;
}

template<typename T>
void Twitter<T>::RemoveFollower(T &t) {
    bool shiftDown = false;

    for (int i = 0; i < followerCount; i++) {
        if (t == followers[i]) {
            shiftDown = true;
            continue;
        }

        if (shiftDown) {
            followers[i - 1] = followers[i];
        }
    }

    if (shiftDown) {
        followerCount--;
    }

    if (followers.length() > 2 && (followerCount < (followers.length() / 4))) {
        followers.changeSize(followerCount/2);
    }

    PrintFollowers();
}

template<typename T>
void Twitter<T>::PrintFollowers() {
    for (int i = 0; i < followerCount; i++) {
        std::cout << followers[i] << std::endl;
    }
}