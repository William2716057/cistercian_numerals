#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <sstream>

static std::vector<std::string> cells(const std::string& s)

 {
	std::vector<std::string> out;
	for (size_t i = 0; i < s.size();) {
        	unsigned char c = s[i];
        	size_t len = (c < 0x80) ? 1 : (c >> 5) == 6 ? 2 : (c >> 4) == 14 ? 3 : 4;
        	out.push_back(s.substr(i, len));
        	i += len;
    }
	return out;
 }

static std::vector<std::string> splitLines(const std::string& s) {
    std::vector<std::string> lines;
    std::stringstream ss(s);
    std::string line;
    while (std::getline(ss, line)) lines.push_back(line);
    return lines;
}


static std::string merge(const std::string& a, const std::string& b) {
	auto la = splitLines(a), lb = splitLines(b);
    	std::string result;
    	for (size_t r = 0; r < la.size(); ++r) {
        	auto ca = cells(la[r]), cb = cells(lb[r]);
        	for (size_t c = 0; c < ca.size(); ++c)
            		result += (ca[c] != " ") ? ca[c] : cb[c];
        if (r + 1 < la.size()) result += "\n";
    }
    return result;
}

static std::string glyph(const char* r1, const char* r2, const char* r3, const char* r4, const char* r5) {
	return std::string(r1) + "\n" + r2 + "\n" + r3 + "\n" + r4 + "\n" + r5;
}

const std::unordered_map<std::string, int> cistercian = {
	//ones
    {glyph("   _ ", "  |  ", "  |  ", "  |  ", "     "), 1},
    {glyph("     ", "  |_ ", "  |  ", "  |  ", "     "), 2},
    {glyph("     ", "  |\\ ", "  |  ", "  |  ", "     "), 3},
    {glyph("     ", "  |/ ", "  |  ", "  |  ", "     "), 4},
    {glyph("   _ ", "  |/ ", "  |  ", "  |  ", "     "), 5},
    {glyph("     ", "  | |", "  |  ", "  |  ", "     "), 6},
    {glyph("   _ ", "  | |", "  |  ", "  |  ", "     "), 7},
    {glyph("     ", "  |_|", "  |  ", "  |  ", "     "), 8},
    {glyph("   _ ", "  |_|", "  |  ", "  |  ", "     "), 9},

    //tens
    {glyph(" _   ", "  |  ", "  |  ", "  |  ", "     "), 10},
    {glyph("     ", " _|  ", "  |  ", "  |  ", "     "), 20},
    {glyph("     ", " /|  ", "  |  ", "  |  ", "     "), 30},
    {glyph("     ", " \\|  ", "  |  ", "  |  ", "     "), 40},
    {glyph(" _   ", " \\|  ", "  |  ", "  |  ", "     "), 50},
    {glyph("     ", "| |  ", "  |  ", "  |  ", "     "), 60},
    {glyph(" _   ", "| |  ", "  |  ", "  |  ", "     "), 70},
    {glyph("     ", "|_|  ", "  |  ", "  |  ", "     "), 80},
    {glyph(" _   ", "|_|  ", "  |  ", "  |  ", "     "), 90},

    //100s
    {glyph("     ", "  |  ", "  |  ", "  |_ ", "     "), 100},
    {glyph("     ", "  |  ", "  |_ ", "  |  ", "     "), 200},
    {glyph("     ", "  |  ", "  |  ", "  |/ ", "     "), 300},
    {glyph("     ", "  |  ", "  |  ", "  |\\ ", "     "), 400},
    {glyph("     ", "  |  ", "  |  ", "  |\\ ", "   ‾ "), 500},
    {glyph("     ", "  |  ", "  |  ", "  | |", "     "), 600},
    {glyph("     ", "  |  ", "  |  ", "  |_|", "     "), 700},
    {glyph("     ", "  |  ", "  |_ ", "  | |", "     "), 800},
    {glyph("     ", "  |  ", "  |_ ", "  |_|", "     "), 900},

    //1000s
    {glyph("     ", "  |  ", "  |  ", " _|  ", "     "), 1000},
    {glyph("     ", "  |  ", " _|  ", "  |  ", "     "), 2000},
    {glyph("     ", "  |  ", "  |  ", " \\|  ", "     "), 3000},
    {glyph("     ", "  |  ", "  |  ", " /|  ", "     "), 4000},
    {glyph("     ", "  |  ", "  |  ", " /|  ", " ‾   "), 5000},
    {glyph("     ", "  |  ", "  |  ", "| |  ", "     "), 6000},
    {glyph("     ", "  |  ", "  |  ", "|_|  ", "     "), 7000},
    {glyph("     ", "  |  ", " _|  ", "| |  ", "     "), 8000},
    {glyph("     ", "  |  ", " _|  ", "|_|  ", "     "), 9000},

};

int main() {
    // Reverse map: number -> glyph
    std::unordered_map<int, std::string> byNumber;
    for (const auto& [g, n] : cistercian) byNumber[n] = g;

    int number;
    std::cout << "Enter number: ";
    std::cin >> number;
    if (number < 1 || number > 9999) {
        std::cout << "Out of range\n";
        return 1;
    }

    // Stem only, as the starting point
    std::string result = glyph("     ", "  |  ", "  |  ", "  |  ", "     ");

    for (int place : {1, 10, 100, 1000}) {
        int digit = number / place % 10;
        if (digit == 0) continue;
        result = merge(result, byNumber.at(digit * place));
    }

    std::cout << result << "\n";
}

/*int main() {

	int digit;

	auto it = cistercian.find(glyph("   _ ", "  |_|", "  |  ", "  |  ", "     "));
	if (it != cistercian.end()) std::cout << it->second << "\n";

	std::cout << "Enter digit: ";
	std::cin >> digit;

	bool found = false;
	for (const auto& [glyphStr, number] : cistercian) {
		if (number == digit) {
			std::cout << glyphStr << "\n";
			found = true;
			break;
		}
	}

	if (!found) std::cout << "Not in table" << digit << "\n";

}*/

