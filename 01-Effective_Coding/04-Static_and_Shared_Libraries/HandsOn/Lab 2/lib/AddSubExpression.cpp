#include "AddSubExpression.h"
#include "ExpressionFactory.h"
#include "ExpressionVisitor.h"
#include <iostream>

AddSubExpression::AddSubExpression(
  ExpressionType type,
  Expression * left,
  Expression * right,
  AddSubExpression::OpType opType
): TwoOperandExpression(type, left, right),
   d_opType(opType)
{
  /* nothing */
}

void
AddSubExpression::accept(ExpressionVisitor & visitor)
{
  visitor.visit(*this);
}