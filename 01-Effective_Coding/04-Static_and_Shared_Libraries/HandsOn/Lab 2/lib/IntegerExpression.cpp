#include "IntegerExpression.h"
#include "ExpressionFactory.h"
#include "ExpressionVisitor.h"

IntegerExpression::IntegerExpression( 
  ExpressionType type, 
  ExactValue * value 
  ): Expression(type, value)
{
  /*nothing*/
}

void
IntegerExpression::accept(ExpressionVisitor & visitor)
{
  visitor.visit(*this);
}