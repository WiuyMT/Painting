/**
 * @file Exceptions.cc
 *
 * @copyright 201 3081 Staff, All rights reserved.
 */
/* Exceptions.cpp

   Author: Eric Van Wyk
   Date: Oct 20, 2009.
*/

#include "HW03/Exceptions.h"
#include <string>

InvalidData::InvalidData(string _msg) {
    msg = _msg;
}

InvalidData::~InvalidData() {
}

string InvalidData::get_msg() {
    return msg;
}
