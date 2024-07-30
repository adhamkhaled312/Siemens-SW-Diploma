#ifndef INCLUDED_BINARYXOREXPRESSION_H
#define INCLUDED_BINARYXOREXPRESSION_H

#include "TwoOperandExpression.h"

class ExpressionVisitor;
/**
 * @brief Class to represent Binary Or Expression
 * 10 | 0 for example
*/
class BinaryXorExpression: public TwoOperandExpression
{
  public:
    BinaryXorExpression(ExpressionType type,
                        Expression * left,
                        Expression * right);
    void accept(ExpressionVisitor &);
    
};

#endif