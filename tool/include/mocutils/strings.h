#include "string"
#include "vector"

namespace moc {
std::string strrev(std::string _src);
std::vector<std::string> operator/(const std::string&, char);

void strcpy(char* dst, const char* src, int ss, int l);
}