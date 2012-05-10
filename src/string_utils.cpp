#include "string_utils/string_utils.h"

// stolen from: http://oopweb.com/CPP/Documents/CPPHOWTO/Volume/C++Programming-HOWTO-7.html
void stringUtils::Tokenize(const std::string& str, std::vector<std::string>& tokens, const std::string& delimiters = " ") {
	// Skip delimiters at beginning.
	std::string::size_type lastPos = str.find_first_not_of(delimiters, 0);
	// Find first "non-delimiter".
	std::string::size_type pos     = str.find_first_of(delimiters, lastPos);

	while (std::string::npos != pos || std::string::npos != lastPos)
	{
		// Found a token, add it to the vector.
		tokens.push_back(str.substr(lastPos, pos - lastPos));
		// Skip delimiters.  Note the "not_of"
		lastPos = str.find_first_not_of(delimiters, pos);
		// Find next "non-delimiter"
		pos = str.find_first_of(delimiters, lastPos);
	}
}


void stringUtils::trim(string& str)
{
	// from: http://www.codeproject.com/KB/stl/stdstringtrim.aspx
	string::size_type pos = str.find_last_not_of(' ');

	if(pos != string::npos) {
		str.erase(pos + 1);
		pos = str.find_first_not_of(' ');
		if(pos != string::npos) 
			str.erase(0, pos);
	}
	else 
		str.erase(str.begin(), str.end());
}
