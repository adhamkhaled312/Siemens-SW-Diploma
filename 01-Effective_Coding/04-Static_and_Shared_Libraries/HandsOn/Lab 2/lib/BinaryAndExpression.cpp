#include "BinaryAndExpression.h"
#include "ExpressionFactory.h"
#include "ExpressionVisitor.h"
#include <iostream>

BinaryAndExpression::BinaryAndExpression(
  ExpressionType type,
  Expression * left,
  Expression * right
): TwoOperandExpression(type, left, right)
{
  /* nothing */
}

void
BinaryAndExpression::accept(ExpressionVisitor & visitor)
{
  visitor.visit(*this);
}