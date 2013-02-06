/////////////////////////////////////////////////////////////////////////
//       _____   ______________  __________  ___  __________  ____     //
//      /  _/ | / / ____/  _/ / /_  __/ __ \/   |/_  __/ __ \/ __ \    //
//      / //  |/ / /_   / // /   / / / /_/ / /| | / / / / / / /_/ /    //
//    _/ // /|  / __/ _/ // /___/ / / _, _/ ___ |/ / / /_/ / _, _/     //
//   /___/_/ |_/_/   /___/_____/_/ /_/ |_/_/  |_/_/  \____/_/ |_|      //
//                                                                     //
//    Copyright (C)2013 Michael Brandon Miller                         //
//                                                                     //
//    This file is part of Infiltrator, distributed under the          //
//    GNU General Public License v3. See 'license.txt' for terms.      //
//                                                                     //
/////////////////////////////////////////////////////////////////////////

/**
 * @file  infiltrator.h
 * @brief Includes widely-used headers and defines globals.
 */

#ifndef INFILTRATOR_H_
#define INFILTRATOR_H_

#include <string>
#include <iostream>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>

namespace Infiltrator
{
    // Pseudo-random number Generator.
    extern boost::random::mt19937 NumGenerator;

    // Random number generation range type.
    typedef boost::random::uniform_int_distribution<> RandRange;
}

#endif // !INFILTRATOR_H_
