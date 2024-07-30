#include "BinaryOrExpression.h"
#include "ExpressionFactory.h"
#include "ExpressionVisitor.h"

#include <iostream>

BinaryOrExpression::BinaryOrExpression(
  ExpressionType type,
  Expression * left,
  Expression * right
): TwoOperandExpression(type, left, right)
{
  /* nothing */
}

void
BinaryOrExpression::accept(ExpressionVisitor & visitor)
{
  visitor.visit(*this);
}