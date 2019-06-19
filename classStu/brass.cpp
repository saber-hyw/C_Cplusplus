#include "brass.h"

// brass class
Brass::Brass(const string &s, long an, double bal) {
}

Brass::~Brass() {
}

// brass plus
BrassPlus::BrassPlus(const string &s, long an, double bal, double ml, double r)
: Brass(s,an,bal) {
}

BrassPlus::BrassPlus(const Brass &ba, double ml, double r)
: Brass(ba) {
}

BrassPlus::~BrassPlus() {
}