#include <iostream>
#include <string>
#include <unordered_map>

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

}
