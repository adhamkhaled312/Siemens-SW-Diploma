#include "MulDivModExpression.h"
#include "ExpressionFactory.h"
#include "ExpressionVisitor.h"

MulDivModExpression::MulDivModExpression(
  ExpressionType type,
  Expression * left,
  Expression * right,
  MulDivModExpression::OpType opType
): TwoOperandExpression(type, left, right),
   d_opType(opType)
{
  /* nothing */
}

void
MulDivModExpression::accept(ExpressionVisitor & visitor)
{
  visitor.visit(*this);
}