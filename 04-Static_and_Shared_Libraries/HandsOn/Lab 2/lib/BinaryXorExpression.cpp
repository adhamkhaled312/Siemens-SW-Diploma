#include "BinaryXorExpression.h"
#include "ExpressionFactory.h"
#include "ExpressionVisitor.h"

#include <iostream>

BinaryXorExpression::BinaryXorExpression(
  ExpressionType type,
  Expression * left,
  Expression * right
): TwoOperandExpression(type, left, right)
{
  /* nothing */
}

void
BinaryXorExpression::accept(ExpressionVisitor & visitor)
{
  visitor.visit(*this);
}