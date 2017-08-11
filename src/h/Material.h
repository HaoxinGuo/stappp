/***************************************************************/
/*  FEM++ : A C++ finite element method code for teaching      */
/*     Computational Dynamics Laboratory                       */
/*     School of Aerospace Engineering, Tsinghua University    */
/*                                                             */
/*     http://www.comdyn.cn/                                   */
/***************************************************************/

#pragma once

using namespace std;

#include <stddef.h>
#include <iostream>
#include <fstream>

//	Material base class which only define one data member
//	All type of material classes should be derived from this base class
class Material
{
public:

	unsigned int num;	// Set number
	
	double E;  // Young's modulus

public:

//	Read material data from stream Input
	virtual bool Read(ifstream& Input, int mset) = 0;

//	Write material data to Stream OutputFile
//	virtual void Output(ofstream* OutputFile);
};

//	Material class for bar element
class BarMaterial : public Material
{
public:

	double Area;	// Sectional area of a bar element

public:
	
//	Read material data from stream Input
	virtual bool Read(ifstream& Input, int mset);

//	Write material data to Stream OutputFile
	virtual void Write(ofstream& OutputFile, int mset);
};
