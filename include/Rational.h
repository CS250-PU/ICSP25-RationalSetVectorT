//******************************************************************************
// File name:  Rational.h
// Author:     CS, Pacific University
// Date:       
// Class:      CS250
// Assignment: Rational 
// Purpose:    Interface for class Rational. A Rational number is of the form
//             numerator / denominator.
//******************************************************************************
#pragma once

#include <iostream>

class Rational {
public:
	Rational (int = 0, int = 1);
	Rational (const Rational&);
	int getNumerator () const;
	int getDenominator () const;
	void setNumerator (int);
	void setDenominator (int);
	bool isEqual (const Rational& rcRational) const;
	Rational multiply (const Rational& rcRational) const;
	Rational add (const Rational& rcRational) const;
	Rational operator* (const Rational& rcRational) const;
	Rational operator+ (const Rational& rcRational) const;
	Rational operator- (void) const;
	bool operator== (const Rational& rcRational) const;

	friend std::ostream& operator<< (std::ostream& rcOutStream,
		const Rational& rcRational);
	friend std::istream& operator>> (std::istream& rcInStream,
		Rational& rcRational);

private:
	int mNumerator, mDenominator;
};