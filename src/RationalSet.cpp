//******************************************************************************
// File name:  RationalSet.cpp
// Author:     CS, Pacific University
// Date:       
// Class:      CS250
// Assignment: RationalSet
// Purpose:    Implements constructors & functions of class Rational. There is
//             no real error checking in this implementation.
//******************************************************************************

#include <iostream>
#include "../include/Rational.h"
#include "../include/RationalSet.h"

//******************************************************************************
// Constructor: RationalSet
//
// Description: Initializes data members to default values
//
// Parameters:  None
//
// Returned:    None
//******************************************************************************
RationalSet::RationalSet () {
}

//******************************************************************************
// Constructor: RationalSet Copy Constructor
//
// Description: Initializes data members to the values of the object passed
//              in.
//
// Parameters:  rcRationalSet - rational object having a numerator and 
//                              denominator
//
// Returned:    None
//******************************************************************************
RationalSet::RationalSet (const RationalSet& rcRationalSet) {
  mcRationals = rcRationalSet.mcRationals;
}

//******************************************************************************
// Method:	    size
//
// Description: Returns the number of rational numbers in the set.
//
// Parameters:  None
//
// Returned:    The number of rational numbers in the set
//******************************************************************************
size_t RationalSet::size () const {
  return mcRationals.size ();
}

//******************************************************************************
// Method:	    add
//
// Description: Adds a rational number to the set. Duplicates are allowed.
//
// Parameters:  rcRational - rational object having a numerator and denominator
//
// Returned:    None
//******************************************************************************
void RationalSet::add (const Rational& rcRational) {
  if (!isMember (rcRational)) {
    mcRationals.push_back (rcRational);
  }
}

//******************************************************************************
// Method:	    isMember
//
// Description: Determines if a rational number is in the set.
//
// Parameters:  rcRational - rational object having a numerator and denominator
//
// Returned:    true if the rational number is in the set; else, false
//******************************************************************************
bool RationalSet::isMember (const Rational& rcRational) const {
  bool bIsMember = false;
  for (size_t i = 0; !bIsMember && i < mcRationals.size (); i++) {
    if (mcRationals[i] == rcRational) {
      bIsMember = true;
    }
  }
  return bIsMember;
}

//******************************************************************************
// Method:	    isEqual
//
// Description: Compares two objects of RationalSet returning a value of true if
//              the numerators and denominators of both rational numbers are
//              the same.
//
// Parameters:  rcRationalSet - rational object having a numerator and
//                              denominator
//
// Returned:    true if objects are equal; else, false
//******************************************************************************
bool RationalSet::isEqual (const RationalSet& rcRationalSet) const {
  bool bIsEqual = true;
  if (mcRationals.size () != rcRationalSet.mcRationals.size ()) {
    bIsEqual = false;
  }

  for (size_t i = 0; bIsEqual && i < mcRationals.size (); i++) {
    if (!rcRationalSet.isMember (mcRationals[i])) {
      bIsEqual = false;
    }
  }
  return bIsEqual;
}

//******************************************************************************
// Method:	    operator<<
//
// Description: Outputs a set of rational numbers to the screen
//
// Parameters:  rcOutStream   - output stream
//              rcRationalSet - rational object having a numerator and 
//                              denominator
//
// Returned:    output stream
//******************************************************************************
std::ostream& operator<<(std::ostream& rcOutStream,
  const RationalSet& rcRationalSet) {
  rcOutStream << "{";
  for (size_t i = 0; i < rcRationalSet.mcRationals.size (); i++) {
    rcOutStream << rcRationalSet.mcRationals[i];
    if (i < rcRationalSet.mcRationals.size () - 1) {
      rcOutStream << ", ";
    }
  }
  rcOutStream << "}";

  return rcOutStream;
}

//******************************************************************************
// Method:	    operator>>
//
// Description: Reads a set of rational numbers from the input stream
//
// Parameters:  rcInStream    - input stream
//              rcRationalSet - rational object having a numerator and 
//                              denominator
//
// Returned:    input stream
//******************************************************************************
std::istream& operator>>(std::istream& rcInStream, RationalSet& rcRationalSet) {
  // the set must be enclosed in curly braces
  char ch;
  Rational cRational;

  rcInStream >> ch;
  if (!rcInStream.eof () && '{' != ch) {
    throw std::invalid_argument ("RationalSet must start with a curly brace");
  }

  while (rcInStream.peek () != '}' && rcInStream >> cRational) {
    rcRationalSet.add (cRational);
  }
  rcInStream >> ch;
  if (!rcInStream.eof () && '}' != ch) {
    throw std::invalid_argument ("RationalSet must end with a curly brace");
  }
  
  return rcInStream;
}