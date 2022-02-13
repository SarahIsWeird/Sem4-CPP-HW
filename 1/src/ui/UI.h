#ifndef APPLICATION_H
#define APPLICATION_H

#include "../complex/Complex.h"
#include "../util/Formattable.h"

class UI {
public:
    void Start();

private:
    static void PrintHelp();

    template <typename T> requires util::Formattable<T>
    T AskFor(const std::string& query, const std::string& error_query);

    double AskForComponent(const std::string& what); // Short-hand
};

#endif // APPLICATION_H