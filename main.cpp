#include <string>
#include <iostream>
#include "figure.h"
using std::cout;
using std::string;

template <class DstType, class SrcType>
bool IsType(const SrcType* src)
{
  return dynamic_cast<const DstType*>(src) != nullptr;
}

bool Rock::beats(IFigure &another) {
    return IsType<Scissors>(&another);
}

bool Scissors::beats(IFigure &another) {
    return IsType<Paper>(&another);
}

bool Paper::beats(IFigure &another) {
    return IsType<Rock>(&another);
}

int main() {
    Rock rock = Rock();
    Scissors scissors = Scissors();
    cout << rock.beats(scissors) << std::endl;
    return 0;
}
