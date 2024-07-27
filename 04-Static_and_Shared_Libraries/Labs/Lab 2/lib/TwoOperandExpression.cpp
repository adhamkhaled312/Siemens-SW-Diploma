
#include "TwoOperandExpression.h"
#include "ExpressionFactory.h"
#include "ExpressionVisitor.h"

TwoOperandExpression::TwoOperandExpression( 
  ExpressionType type,
  Expression * left,
  Expression * right 
  ): Expression(type, nullptr),
     p_leftExpr(left),
     p_rightExpr(right)
{
  /* nothing */
}

void
TwoOperandExpression::accept(ExpressionVisitor & visitor)
{
  visitor.visit(*this);
}