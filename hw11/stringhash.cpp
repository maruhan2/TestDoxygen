/**
 * \file stringhash.cpp
 * \author Kevin McSwiggen and Mars Park
 *
 * \brief The implementation of our myhash<string> function.
 *
 */

#include <string>

size_t myhash(const std::string& s)
{
    size_t hash = 5381;
    int c;
    size_t i = 0;

    while ((c = s.c_str()[i++]))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}
