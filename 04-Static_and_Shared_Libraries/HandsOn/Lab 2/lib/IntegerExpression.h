#ifndef INCLUDED_INTERGEREXPRESSION_H
#define INCLUDED_INTERGEREXPRESSION_H

#include "Expression.h"

class ExpressionVisitor;
/**
 * @brief Class to represent Integer
*/
class IntegerExpression: public Expression
{
  public:
    IntegerExpression(ExpressionType type, 
                      ExactValue * value);

    void accept(ExpressionVisitor &);
    
};


#endif