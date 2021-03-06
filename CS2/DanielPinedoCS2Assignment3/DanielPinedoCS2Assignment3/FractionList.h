/*
Name: Daniel Pinedo
Class: CS 2
Assignment #: 3
All Compilers Used: VS17
Operating Systems on Which Compiled: Win10
Date and Time of Last successful run: 10/4/2017 @0345
Email: d.p@ieee.org
*/

#pragma once
#ifndef FRACTIONLIST_H
#define FRACTIONLIST_H
#include "Fraction.h"
class FractionList
{
private:
	const static size_t MAX = 30;
	Fraction List[MAX];
	size_t num_elements;
	bool isSorted;
public:
	FractionList();
	void addFraction(const Fraction & F);
	const string toString() const;
	void sort();
	bool isEmpty() const;
	bool isFull() const;
	size_t getNumberOfElements() const;
	friend istream & operator >> (istream & in, FractionList & FL);
	friend ostream & operator << (ostream & out, FractionList & FL);
	static void FractionList::getInstance(FractionList & FL, istream & in);
	const Fraction getLargest();
	const Fraction getSumOfFractions();
	bool getSortState() const;
	Fraction operator [] (size_t index) const;
	~FractionList();
};
#endif

