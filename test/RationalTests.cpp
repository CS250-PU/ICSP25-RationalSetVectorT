//****************************************************************************** 
// File name:		RationalTests.cpp
// Author:			CS, Pacific University
// Date:				
// Class:				CS 250
// Assignment:  
// Purpose:			This file is written to unit test all functions that are part
//              of the included interface.
// Hours:
//******************************************************************************

#include <gtest/gtest.h>

// interface to unit test
#include "../include/Rational.h"

// Each unit test for a given function is added below
TEST (RationalTest, constructorDefault) {
  Rational cRational;

  EXPECT_EQ (0, cRational.getNumerator ());
  EXPECT_EQ (1, cRational.getDenominator ());
}

TEST (RationalTest, constructorParametrized) {
  Rational cRational (3, 4);

  EXPECT_EQ (3, cRational.getNumerator ());
  EXPECT_EQ (4, cRational.getDenominator ());
}

TEST (RationalTest, constructorCopy) {
  Rational cRational (3, 4);
  Rational cRational2 (cRational);

  EXPECT_EQ (3, cRational2.getNumerator ());
  EXPECT_EQ (4, cRational2.getDenominator ());
}

TEST (RationalTest, setNumerator) {
  Rational cRational;

  cRational.setNumerator (3);
  EXPECT_EQ (3, cRational.getNumerator ());
}

TEST (RationalTest, setDenominator) {
  Rational cRational;

  cRational.setDenominator (4);
  EXPECT_EQ (4, cRational.getDenominator ());
}

TEST (RationalTest, isEqual) {
  Rational cRational (3, 4);
  Rational cRational2 (3, 4);

  EXPECT_TRUE (cRational.isEqual (cRational2));
}

TEST (RationalTest, multiply) {
  Rational cRational (3, 4);
  Rational cRational2 (2, 3);
  Rational cRational3 = cRational.multiply (cRational2);

  EXPECT_EQ (6, cRational3.getNumerator ());
  EXPECT_EQ (12, cRational3.getDenominator ());
}

TEST (RationalTest, add) {
  Rational cRational (3, 4);
  Rational cRational2 (2, 3);
  Rational cRational3 = cRational.add (cRational2);

  EXPECT_EQ (17, cRational3.getNumerator ());
  EXPECT_EQ (12, cRational3.getDenominator ());
}

TEST (RationalTest, operatorMultiply) {
  Rational cRational (3, 4);
  Rational cRational2 (2, 3);
  Rational cRational3 = cRational * cRational2;

  EXPECT_EQ (6, cRational3.getNumerator ());
  EXPECT_EQ (12, cRational3.getDenominator ());
}

TEST (RationalTest, operatorAdd) {
  Rational cRational (3, 4);
  Rational cRational2 (2, 3);
  Rational cRational3 = cRational + cRational2;

  EXPECT_EQ (17, cRational3.getNumerator ());
  EXPECT_EQ (12, cRational3.getDenominator ());
}

TEST (RationalTest, operatorNegate) {
  Rational cRational (3, 4);
  Rational cRational2 = -cRational;

  EXPECT_EQ (-3, cRational2.getNumerator ());
  EXPECT_EQ (4, cRational2.getDenominator ());
}

TEST (RationalTest, operatorEqual) {
  Rational cRational (3, 4);
  Rational cRational2 (3, 4);

  EXPECT_TRUE (cRational == cRational2);
}

TEST (RationalTest, operatorInsertion) {
  Rational cRational (3, 4);
  std::ostringstream cOutStream;

  cOutStream << cRational;
  EXPECT_EQ ("3/4", cOutStream.str ());
}

TEST (RationalTest, operatorExtraction) {
  Rational cRational;
  std::istringstream cInStream ("3/4");

  cInStream >> cRational;
  EXPECT_EQ (3, cRational.getNumerator ());
  EXPECT_EQ (4, cRational.getDenominator ());
}