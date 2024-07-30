#ifndef INCLUDED_EXPRESSIONPRINTER_H
#define INCLUDED_EXPRESSIONPRINTER_H

#include "ExpressionVisitor.h"

class ExpressionPrinter: public ExpressionVisitor
{
  public:
    ExpressionPrinter(Expression *);
  
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

    void printIndentation();
  private:
    int d_indentation;
};

#endif