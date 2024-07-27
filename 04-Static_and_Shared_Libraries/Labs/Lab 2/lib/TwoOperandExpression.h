#ifndef INCLUDED_IntegerExpression_H
#define INCLUDED_IntegerExpression_H

#include "Expression.h"

/**
 * @brief Base class for all two operand expressions
*/
class TwoOperandExpression: public Expression
{
  public:
    TwoOperandExpression(ExpressionType type,
                         Expression * left,
                         Expression * right);

    Expression * rightExpr(void) { return p_rightExpr; }
    Expression * leftExpr(void) { return p_leftExpr; }

    void accept(ExpressionVisitor &);

  protected:
    Expression * p_leftExpr;
    Expression * p_rightExpr;
};
#endif