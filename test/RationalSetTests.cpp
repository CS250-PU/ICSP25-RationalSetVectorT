//****************************************************************************** 
// File name:		RationalSetTests.cpp
// Author:			CS, Pacific University
// Date:				
// Class:				CS 250
// Assignment:  
// Purpose:			This file is written to unit test all functions that are part
//              of the included interface.
// Hours:
//******************************************************************************

#include <gtest/gtest.h>
#include <fstream>

// interface to unit test
#include "../include/Rational.h"
#include "../include/RationalSet.h"   

// Each unit test for a given function is added below
TEST (RationalSetTests, constructorDefault) {
  RationalSet cRationalSet;

  EXPECT_EQ (0, cRationalSet.size ());
}

TEST (RationalSetTests, constructorCopy) {
  Rational cRational (3, 4);
  RationalSet cRationalSet;
  cRationalSet.add (cRational);
  RationalSet cRationalSet2 (cRationalSet);

  EXPECT_EQ (1, cRationalSet2.size ());
}

TEST (RationalSetTests, add) {
  Rational cRational (3, 4);
  RationalSet cRationalSet;

  cRationalSet.add (cRational);
  EXPECT_EQ (1, cRationalSet.size ());
  // add a duplicate
  cRationalSet.add (cRational);
  EXPECT_EQ (1, cRationalSet.size ());
  // add a different rational number
  cRationalSet.add (Rational (2, 3));
  EXPECT_EQ (2, cRationalSet.size ());
} 

TEST (RationalSetTests, isMember) {
  Rational cRational (3, 4);
  RationalSet cRationalSet;

  cRationalSet.add (cRational);
  EXPECT_TRUE (cRationalSet.isMember (cRational));
  EXPECT_FALSE (cRationalSet.isMember (Rational (2, 3)));
}

TEST (RationalSetTests, isEqual) {
  Rational cRational (3, 4);
  RationalSet cRationalSet;
  RationalSet cRationalSet2;

  cRationalSet.add (cRational);
  cRationalSet2.add (cRational);
  EXPECT_TRUE (cRationalSet.isEqual (cRationalSet2));
  cRationalSet2.add (Rational (2, 3));
  EXPECT_FALSE (cRationalSet.isEqual (cRationalSet2));
}
