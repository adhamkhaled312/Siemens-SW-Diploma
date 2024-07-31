#ifndef INCLUDED_COMPARISONEXPRESSION_H
#define INCLUDED_COMPARISONEXPRESSION_H

#include "TwoOperandExpression.h"

class ExpressionVisitor;
/**
 * @brief Class to represent Comparison Expression
 * 10 == 0 for example
*/
class ComparisonExpression: public TwoOperandExpression
{
  public:
    enum OpType {
      EQUAL,
      NOT_EQUAL
    };
    ComparisonExpression(ExpressionType type,
                         Expression * left,
                         Expression * right,
                         OpType opType);

    OpType opType(void) { return d_opType; }

    bool isEqualExpression(void) { return OpType::EQUAL == d_opType; }
    bool isNotEqualExpression(void) { return OpType::NOT_EQUAL == d_opType; }

    void accept(ExpressionVisitor &);
    
  private:
    OpType d_opType;
};

#endif