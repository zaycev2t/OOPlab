#ifndef BOOKS_H
#define BOOKS_H

#include <string>
class Book {
private:
    std::string author;
    std::string title;
    int year;
    int pages;

public:
    // Конструкторы
    Book() : author(""), title(""), year(0), pages(0) {}

    Book(const std::string& auth, const std::string& titl, int y, int p)
        : author(auth), title(titl), year(y), pages(p) {}

    // Геттеры
    std::string getAuthor() const { return author; }
    std::string getTitle() const { return title; }
    int getYear() const { return year; }
    int getPages() const { return pages; }

    // Сеттеры
    void setAuthor(const std::string& auth) {
        if (!auth.empty()) author = auth;
        else author = "Unknown";
    }

    void setTitle(const std::string& titl) {
        if (!titl.empty()) title = titl;
        else title = "Untitled";
    }

    void setYear(int y) {
        if (y >= 1 && y <= 2100) year = y;
        else year = 0;
    }

    void setPages(int p) {
        if (p >= 1 && p <= 10000) pages = p;
        else pages = 0;
    }
};
#endif // BOOKS_H
