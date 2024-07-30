#ifndef INCLUDED_MULDIVMODEXPRESSION_H
#define INCLUDED_MULDIVMODEXPRESSION_H

#include "TwoOperandExpression.h"

class ExpressionVisitor;
/**
 * @brief Class to represent Mul, Div and Mod expressions
*/
class MulDivModExpression: public TwoOperandExpression
{
  public:
    enum OpType {
      MUL,
      DIV,
      MOD
    };
    MulDivModExpression(ExpressionType type,
                        Expression * left,
                        Expression * right,
                        OpType opType);

    OpType opType(void) { return d_opType; }

    bool isMultiplication(void) { return d_opType == OpType::MUL; }
    bool isDivision(void) { return d_opType == OpType::DIV; }
    bool isModulus(void) { return d_opType == OpType::MOD; }

    void accept(ExpressionVisitor &);
    
  private:
    OpType d_opType;
};

#endif