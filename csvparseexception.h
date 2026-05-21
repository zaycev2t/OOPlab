#ifndef CSVPARSEEXCEPTION_H
#define CSVPARSEEXCEPTION_H

#include <exception>
#include <string>

class CsvParseException : public std::exception {
private:
    std::string message_;
    unsigned line_number_;

public:
    CsvParseException(const std::string& msg, unsigned line)
        : message_(msg), line_number_(line) {}

    const char* what() const noexcept override {
        return message_.c_str();
    }

    unsigned lineNumber() const {
        return line_number_;
    }
};

#endif
