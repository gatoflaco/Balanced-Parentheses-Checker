#include <iostream>

static inline bool is_valid(std::string s) {
    int len = s.length();
    int i = 0;
    char expected;
    while (true) {
        // first, move to the right looking for a closing paren
        while (i < len && (s[i] != ')' && s[i] != '}' && s[i] != ']' && s[i] != '>')) i++;
        
        // if you didn't find one, go back to check for lingering openers
        if (i == len) {
            while (--i >= 0) {
                if (s[i] == '(' || s[i] == '{' || s[i] == '[' || s[i] == '<') return false;    // lingering opener found
            }
            return true;    // it's balanced, can return true
        }
        
        // else, figure out which type of paren it was; set what opening paren to look for
        if (s[i] == ')') expected = '(';
        else expected = s[i] - 2;   // evil ascii assumption
        
        // replace the closing paren with a character representing that it is marked
        s[i--] = '\0';
        
        // now, move to the left looking for the matching opener
        while (i >= 0 && (s[i] != '(' && s[i] != '{' && s[i] != '[' && s[i] != '<')) i--;
        
        // check if you stopped for the right reason; if something is wrong, return false
        if (i == -1 || s[i] != expected) return false;
        
        // else, mark the matching opener; we can continue
        s[i++] = '\0';
    }
}

int main() {
    std::cout << "Input a string to test. Type \"done\" to quit." << std::endl;
    std::string test;
    while (true) {
        std::getline(std::cin, test);
        if (test == "done") break;
        std::cout << "\"" << test << "\" -> " << (is_valid(test) ? "accepted" : "rejected") << std::endl;
    }
}
