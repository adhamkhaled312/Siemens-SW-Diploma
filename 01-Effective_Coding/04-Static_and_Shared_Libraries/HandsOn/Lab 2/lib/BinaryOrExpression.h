#ifndef INCLUDED_BINARYOREXPRESSION_H
#define INCLUDED_BINARYOREXPRESSION_H

#include "TwoOperandExpression.h"

class ExpressionVisitor;
/**
 * @brief Class to represent Binary Or Expression
 * 10 | 0 for example
*/
class BinaryOrExpression: public TwoOperandExpression
{
  public:
    BinaryOrExpression(ExpressionType type,
                        Expression * left,
                        Expression * right);
    void accept(ExpressionVisitor &);

    
};

#endif