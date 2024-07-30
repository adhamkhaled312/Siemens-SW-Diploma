#ifndef INCLUDED_STRINGEXPRESSION_H
#define INCLUDED_STRINGEXPRESSION_H

#include "Expression.h"

class StringExpression: public Expression
{
  public:
    StringExpression(ExpressionType type,
                     ExactValue * val);
    void accept(ExpressionVisitor &);
    
  
};


#endif