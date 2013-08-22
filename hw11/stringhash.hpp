/**
 * \file stringhash.hpp
 * \author Kevin McSwiggen and Mars Park
 *
 * \brief Declaration for our myhash<string> hashing function
 *
 */

#ifndef STRINGHASH_HPP_INCLUDED
#define STRINGHASH_HPP_INCLUDED 1

#include <string>

/**
 * \brief The DJB2 string hash, described by Dan Bernstein on comp.lang.c
 */
size_t myhash(const std::string& s);

#endif // STRINGHASH_HPP_INCLUDED
