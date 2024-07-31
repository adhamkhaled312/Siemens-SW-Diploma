#ifndef INCLUDED_LOGICALANDEXPRESSION_H
#define INCLUDED_LOGICALANDEXPRESSION_H

#include "TwoOperandExpression.h"

/**
 * @brief Class to represent Logical And Expression
 * 10 && 0 for example
*/
class LogicalAndExpression: public TwoOperandExpression
{
  public:
    LogicalAndExpression(ExpressionType type,
                        Expression * left,
                        Expression * right);
    void accept(ExpressionVisitor &);
    
};

#endif