#include "LogicalOrExpression.h"
#include "ExpressionFactory.h"
#include "ExpressionVisitor.h"

LogicalOrExpression::LogicalOrExpression(
  ExpressionType type,
  Expression * left,
  Expression * right
): TwoOperandExpression(type, left, right)
{
  /* nothing */
}

void
LogicalOrExpression::accept(ExpressionVisitor & visitor)
{
  visitor.visit(*this);
}