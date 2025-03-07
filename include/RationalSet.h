//******************************************************************************
// File name:  RationalSet.h
// Author:     CS, Pacific University
// Date:       
// Class:      CS250
// Assignment: Rational 
// Purpose:    Interface for class Rational. A Rational number is of the form
//             numerator / denominator.
//******************************************************************************
#pragma once

#include <iostream>
#include "Rational.h"
#include <vector>

class RationalSet {
public:
  RationalSet ();
  RationalSet (const RationalSet&);
  size_t size () const;
  void add (const Rational&);
  bool isMember (const Rational&) const;
  bool isEqual (const RationalSet&) const;

  Rational operator[](int) const;
  RationalSet operator+(const RationalSet&) const;
  RationalSet operator-(const RationalSet&) const;
  RationalSet operator*(const RationalSet&) const;
  bool operator==(const RationalSet&) const;

  friend std::ostream& operator<<(std::ostream&, const RationalSet&);
  friend std::istream& operator>>(std::istream&, RationalSet&);

private:
  std::vector<Rational> mcRationals;
};