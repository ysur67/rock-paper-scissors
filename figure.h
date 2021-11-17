
#ifndef FIGURE_H
#define FIGURE_H
#include <string>
using std::string;

class IFigure {

    public:
        virtual ~IFigure() { };
        virtual bool beats(IFigure &another) = 0;
};

class Rock : public IFigure {
    public:
        bool beats(IFigure &another) override;
};

class Paper : public IFigure {
    public:
        bool beats(IFigure &another) override;
};

class Scissors : public IFigure {
    public:
        bool beats(IFigure &another) override;
};

#endif
