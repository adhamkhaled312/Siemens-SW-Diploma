#ifndef INCLUDED_LOGICALOREXPRESSION_H
#define INCLUDED_LOGICALOREXPRESSION_H

#include "TwoOperandExpression.h"

/**
 * @brief Class to represent Logical Or Expression
 * 10 || 0 for example
*/
class LogicalOrExpression: public TwoOperandExpression
{
  public:
    LogicalOrExpression(ExpressionType type,
                        Expression * left,
                        Expression * right);
    void accept(ExpressionVisitor &);
    
};

#endif