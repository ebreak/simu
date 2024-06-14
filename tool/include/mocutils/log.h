#include <string>

namespace moc {
void log(std::string msg);
void warn(std::string msg);
void panic(std::string msg);


void logf(const char *fmt, ...);
void warnf(const char *fmt, ...);
void panicf(const char *fmt, ...);
}
