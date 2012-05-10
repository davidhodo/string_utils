/*
 * stringUtils.h
 *
 *  Created on: Jan 28, 2010
 *      Author: hododav
 */

#ifndef STRINGUTILS_H_
#define STRINGUTILS_H_

#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

namespace stringUtils {

	//! converts the given value to a string
	template <class T>
	inline string to_string (const T& t) {
		stringstream ss;
		ss << t;
		return ss.str();
	}

	//! converts the given value to a string with a given percision
	template <class T>
	inline string precise_to_string (const T& t, unsigned int precision) {
		stringstream ss;
		ss << setprecision(precision) << t;
		return ss.str();
	}

	//! converts the given array of values to a string
	template <class T>
	inline string to_string (const T& t, unsigned int col, unsigned int row=1) {
		stringstream ss;
		string nrow, ncol, size_message; //[rxc]
		nrow = to_string(row);
		ncol = to_string(col);

		ss <<"[" << nrow << "x" << ncol << "]" << "{" << t[0];

		for (unsigned int ii=1; ii<row*col; ii++) {
			ss << "," << t[ii];
		}

		ss << "}";
		return ss.str();
	}

	template <class T>
	inline string precise_to_string (const T& t, unsigned int col, unsigned int precision, unsigned int row=1) {
		stringstream ss;
		ss <<"[" << row << "x" << col << "]" << "{" << setprecision(precision) << t[0];
		for (unsigned int ii=1; ii<row*col; ii++) {
			ss << "," << setprecision(precision) << t[ii] ;
		}
		ss << "}";
		return ss.str();
	}
	//! converts a BYTE[] to a string 
	template <class T>
	inline string to_string_byte (const T& t, unsigned int len) {
		stringstream ss;
		ss << "{" << (int)t[0];
		for (unsigned int ii=1; ii<len; ii++) {
			ss << "," << (int)t[ii] ;
		}
		ss << "}";
		return ss.str();
	}

	inline int convertToInteger(const string& s) {
		istringstream i(s);
		int x;
		if (!(i >> x))
			return 0;
		else
			return x;
	}

	inline double convertToDouble(const string& s) {
		istringstream i(s);
		double x;
		if (!(i >> x))
			return 0;
		else
			return x;
	}

	inline float convertToFloat(const string& s) {
		istringstream i(s);
		float x;
		if (!(i >> x))
			return 0;
		else
			return x;
	}

	inline bool convertToBool(const string& s) {
		istringstream i(s);
		bool xbool;
		if (!(i >> xbool))
			return 0;
		else
			return xbool;
	}

	/*
	If the above convertToBool method doesn't work then try below from
	http://stackoverflow.com/questions/3880927/num-get-facet-and-stringstream-conversion-to-boolean-fails-with-initialised-boo
	and refence here if  needed http://www.cplusplus.com/reference/iostream/manipulators/boolalpha/
	bool val = false;
  SStream >> val;
  if( SStream.fail() )
  {
    SStream.clear(); 
    SStream >> boolalpha >> val; 
  }    
  return val;  */


	//!< Converts a string of the form "0xA3F5" to an integer value
	inline long HexStringToInt(string hexValue) {
		stringstream ss;
		long lValue;
		ss << hex << hexValue;
		ss >> lValue;
		return lValue;
	}


	// converts and integer value to a hex string without the "0x"
	inline string IntToHexString(int value) {
		ostringstream os;

		// convert int value to hex
		os.flags(ios::hex);
		os<<value;
		string hexValue = os.str();

		// make any letters uppercase
		transform(hexValue.begin(), hexValue.end(), hexValue.begin(), \
					   (int(*)(int)) toupper);

		return hexValue;
	}

	inline string CharToHexString(char value) {
		string fullHexString=IntToHexString((int) value);
		if (fullHexString.length()>2)
			return fullHexString.substr(6,2);
		else
			return fullHexString;
	}


	//! method to split incoming messages into tokens
	// from: http://oopweb.com/CPP/Documents/CPPHOWTO/Volume/C++Programming-HOWTO-7.html
	void Tokenize(const string& str,vector<string>& tokens,const string& delimiters);

	void trim(string& str); //<! trims leading and trailing spaces from a string

}

#endif /* STRINGUTILS_H_ */
