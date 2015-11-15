#include "TrimTest.h"

std::string TrimTest::s[TrimTest::NTESTS] = {
	" \t abcdefghijklmnopqrstuvwxyz \t ",
	"abcdefghijklmnopqrstuvwxyz \t ",
	" \t abcdefghijklmnopqrstuvwxyz",
	"a", "ab", "abc", "a b c",
	" \t a b c \t ", "\t a \t b \t c \t",
	"\t \n \r \v \f",
	""
};
