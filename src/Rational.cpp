//***************************************************************************
// File name:  rational.cpp
// Author:     CS, Pacific University
// Date:       
// Class:      CS250
// Assignment: Rational 
// Purpose:    Implements constructors & functions of class Rational. There is
//             no real error checking in this implementation.
//***************************************************************************

#include <iostream>
#include "../include/Rational.h"

//***************************************************************************
// Constructor: Rational
//
// Description: Initializes data members to default values
//
// Parameters:  numerator   - the numerator of the rational number
//              denominator - the denominator of the rational number
//
// Returned:    None
//***************************************************************************
Rational::Rational (int numerator, int denominator) {
	setNumerator (numerator);
	setDenominator (denominator);
}

//***************************************************************************
// Constructor: Rational Copy Constructor
//
// Description: Initializes data members to the values of the object passed
//              in.
//
// Parameters:  rcRational - rational object having a numerator and denominator
//
// Returned:    None
//***************************************************************************
Rational::Rational (const Rational& rcRational) {
	setNumerator (rcRational.mNumerator);
	setDenominator (rcRational.mDenominator);
}

//***************************************************************************
// Method:	    setNumerator
//
// Description: Changes the value of the numerator to the value input. Shows
//              the use of this although it is not necessary.
//
// Parameters:  numerator   - numerator of the rational number
//
// Returned:    None
//***************************************************************************
void Rational::setNumerator (int numerator) {
	mNumerator = numerator;
}

//***************************************************************************
// Method:	    setDenominator
//
// Description: Changes the value of the denominator to the value input.
//
// Parameters:  denominator   - denominator of the rational number
//
// Returned:    None
//***************************************************************************
void Rational::setDenominator (int denominator) {
	if (0 == denominator) {
		throw std::invalid_argument ("Denominator cannot be zero");
	}
	mDenominator = denominator;
}

//***************************************************************************
// Method:	    getNumerator
//
// Description: Returns the value of the numerator.
//
// Parameters:  None
//
// Returned:    The numerator value
//***************************************************************************
int Rational::getNumerator () const {
	return mNumerator;
}

//***************************************************************************
// Method:	    getDenominator
//
// Description: Returns the value of the denominator.
//
// Parameters:  None
//
// Returned:    The denominator value
//***************************************************************************
int Rational::getDenominator () const {
	return mDenominator;
}

//***************************************************************************
// Method:	    isqual
//
// Description: Compares two objects of Rational returning a value of true if 
//              the numerators and denominators of both rational numbers are 
//              the same.
//
// Parameters:  fraction - rational object having a numerator and denominator
//
// Returned:    true if objects are equal; else, false
//***************************************************************************
bool Rational::isEqual (const Rational& cRational)  const {
	return (mNumerator == cRational.mNumerator &&
		mDenominator == cRational.mDenominator);
}

//***************************************************************************
// Method:	    multiply
//
// Description: Multiples the numerators and denominators of two objects. 
//
// Parameters:  fraction - rational object having a numerator and denominator
//
// Returned:    An object of type Rational that contains the result of the             
//              multiplication.
//***************************************************************************
Rational Rational::multiply (const Rational& rcRational) const {
	return Rational (rcRational.mNumerator * mNumerator,
		rcRational.mDenominator * mDenominator);
}

//***************************************************************************
// Method:	    add
//
// Description: Adds the numerators and denominators of two objects.
//
// Parameters:  rcRational - rational object having a numerator and denominator
//
// Returned:    An object of type Rational that contains the result of the
//              addition.
//***************************************************************************
Rational Rational::add (const Rational& rcRational) const {
	return Rational (mNumerator * rcRational.mDenominator +
		mDenominator * rcRational.mNumerator,
		mDenominator * rcRational.mDenominator);
}

//*********************************************************************
// Operator function * - binary operation that multiplies two rational
//                       numbers
//*********************************************************************
Rational Rational::operator* (const Rational& rcRational) const {
	return Rational (mNumerator * rcRational.mNumerator,
		mDenominator * rcRational.mDenominator);
}

//*********************************************************************
// Operator function + - binary operation that adds two rational
//                       numbers
// Note: a/b + c/d = (ad + bc) / bd
//*********************************************************************

Rational Rational::operator+ (const Rational& rcRational) const {
	return Rational (mNumerator * rcRational.mDenominator +
		mDenominator * rcRational.mNumerator,
		mDenominator * rcRational.mDenominator);
}

//*********************************************************************
// Operator function - - unary operation that negates a rational number
//*********************************************************************

Rational Rational::operator- () const {
	return Rational (-mNumerator, mDenominator);
}

//*********************************************************************
// Operator function ==  compares two rational numbers for equivalency
//*********************************************************************

bool  Rational::operator== (const Rational& cRational) const {
	return (mNumerator == cRational.mNumerator) &&
		(mDenominator == cRational.mDenominator);
}

//*********************************************************************
// Operator function << outputs a rational number
//*********************************************************************

std::ostream& operator<< (std::ostream& rcOutStream,
	const Rational& rcRational) {
	rcOutStream << rcRational.mNumerator << '/' << rcRational.mDenominator;

	return rcOutStream;
}

//*********************************************************************
// Operator function >> inputs a rational number
//*********************************************************************

std::istream& operator>> (std::istream& cInStream, Rational& rcRational) {
	char ch;

	cInStream >> rcRational.mNumerator >> ch >> rcRational.mDenominator;

	return cInStream;
}