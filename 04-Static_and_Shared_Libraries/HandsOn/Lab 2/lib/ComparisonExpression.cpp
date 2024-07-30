#include "ComparisonExpression.h"
#include "ExpressionFactory.h"
#include "ExpressionVisitor.h"
#include <iostream>

ComparisonExpression::ComparisonExpression(
  ExpressionType type,
  Expression * left,
  Expression * right,
  OpType opType
): TwoOperandExpression(type, left, right),
   d_opType(opType)
{
  /* nothing */
}

void
ComparisonExpression::accept(ExpressionVisitor & visitor)
{
  visitor.visit(*this);
}