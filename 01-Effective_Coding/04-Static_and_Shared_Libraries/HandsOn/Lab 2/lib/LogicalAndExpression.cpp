#include "LogicalAndExpression.h"
#include "ExpressionFactory.h"
#include "ExpressionVisitor.h"

LogicalAndExpression::LogicalAndExpression(
  ExpressionType type,
  Expression * left,
  Expression * right
): TwoOperandExpression(type, left, right)
{
  /* nothing */
}

void
LogicalAndExpression::accept(ExpressionVisitor & visitor)
{
  visitor.visit(*this);
}