#ifndef INCLUDED_BINARYANDEXPRESSION_H
#define INCLUDED_BINARYANDEXPRESSION_H

#include "TwoOperandExpression.h"
// #include "ExpressionVisitor.h"

class ExpressionVisitor;
/**
 * @brief Class to represent Binary And Expression
 * 10 & 0 for example
*/
class BinaryAndExpression: public TwoOperandExpression
{
  public:
    BinaryAndExpression(ExpressionType type,
                        Expression * left,
                        Expression * right);
    void accept(ExpressionVisitor &);

};

#endif