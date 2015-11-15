#ifndef TRIM_H
#define TRIM_H
#include <string>
#include <cstddef>

inline std::string trim(const std::string& s){
	if(s.length()==0){
		return s;
	}
	std::size_t beg = s.find_first_not_of(" \a\b\f\n\r\t\v");
	std::size_t end = s.find_last_not_of(" \a\b\f\n\r\t\v");
	if(beg==std::string::npos){
		return "";
	}
	return std::string(s, beg, end-beg+1);
}

#endif //TRIM_H
