
#ifndef FIGURE_H
#define FIGURE_H
#include <string>
using std::string;

class IFigure {
    protected:
        string name;

    public:
        IFigure(string name) {
            this->name = name;
        };
        virtual ~IFigure() = default;
        virtual bool beats(IFigure &another) = 0;
        string getName();
};

class Rock : public IFigure {
    public:
        Rock() : IFigure("rock") {};
        bool beats(IFigure &another) override;
};

class Paper : public IFigure {
    public:
        Paper() : IFigure("paper") {};
        bool beats(IFigure &another) override;
};

class Scissors : public IFigure {
    public:
        Scissors() : IFigure("scissors") {};
        bool beats(IFigure &another) override;
};

#endif
