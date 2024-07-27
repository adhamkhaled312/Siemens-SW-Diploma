#include "StringExpression.h"
#include "ExpressionFactory.h"
#include "ExpressionVisitor.h"

StringExpression::StringExpression(
  ExpressionType type,
  ExactValue * val
  ) : Expression(type, val)
{
  /* nothing*/
}

void
StringExpression::accept(ExpressionVisitor & visitor)
{
  visitor.visit(*this);
}