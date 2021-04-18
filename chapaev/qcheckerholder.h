#ifndef QCHECKERHOLDER_H
#define QCHECKERHOLDER_H
#include "qchecker.h"
#include <vector>

class qCheckerHolder
{
private:
    std::vector<qChecker> checkers;
public:
    qCheckerHolder();
};

#endif // QCHECKERHOLDER_H
