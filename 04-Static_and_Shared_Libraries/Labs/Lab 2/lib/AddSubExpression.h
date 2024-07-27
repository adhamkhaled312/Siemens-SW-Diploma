#ifndef INCLUDED_ADDSUBEXPRESSION_H
#define INCLUDED_ADDSUBEXPRESSION_H

#include "TwoOperandExpression.h"

class ExpressionVisitor;
/**
 * @brief Class to represent addition and substraction expressions
*/
class AddSubExpression: public TwoOperandExpression
{
  public:
    enum OpType {
      ADD,
      SUB
    };
    AddSubExpression(ExpressionType type,
                     Expression * left,
                     Expression * right,
                     OpType opType);

    OpType opType(void) { return d_opType; }

    bool isAddition(void) { return d_opType == OpType::ADD; }
    bool isSubtraction(void) { return d_opType == OpType::SUB; }

    void accept(ExpressionVisitor &);

  private:
    OpType d_opType;
};

#endif