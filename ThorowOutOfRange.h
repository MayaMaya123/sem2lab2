//
// Created by Майя Флейшер on 07.06.2021.
//
#include <ostream>

#ifndef SEM2LAB2_THOROWOUTOFRANGE_H
#define SEM2LAB2_THOROWOUTOFRANGE_H

class IndexOutOfRange : public std::exception {
public:
    const char *what() const noexcept override {
        return "Invalid index!";
    }
};

#endif //SEM2LAB2_THOROWOUTOFRANGE_H
