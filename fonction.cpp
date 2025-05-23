#include "fonction.h"
#include <string>
#include <vector>
using namespace std;
using namespace std;

vector<string> split(const string& str, char delimiter) {
    vector<string> result;
    string current;
    for (char c : str) {
        if (c == delimiter) {
            result.push_back(current);
            current.clear();
        } else {
            current += c;
        }
    }
    result.push_back(current);
    return result;
}
