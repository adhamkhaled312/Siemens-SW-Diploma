#ifndef INCLUDED_EXPRESSIONEXECUTER_H
#define INCLUDED_EXPRESSIONEXECUTER_H

#include "ExpressionVisitor.h"

class ExactValue;

class ExpressionExecuter: public ExpressionVisitor
{
  public:
    ExpressionExecuter(Expression *);
    ExactValue * value(void)
     { return p_value; }
  private:
    void visit(AddSubExpression &);
    void visit(BinaryAndExpression &);
    void visit(BinaryOrExpression &);
    void visit(BinaryXorExpression &);
    void visit(ComparisonExpression &);
    void visit(IntegerExpression &);
    void visit(LogicalAndExpression &);
    void visit(LogicalOrExpression &);
    void visit(MulDivModExpression &);
    void visit(StringExpression &);
    void visit(TwoOperandExpression &);

    
  private:
    ExactValue * p_value;
};

#endif