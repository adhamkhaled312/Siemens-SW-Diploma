#ifndef INCLUDED_EXPRESSIONVISITOR_H
#define INCLUDED_EXPRESSIONVISITOR_H

class Expression;
class AddSubExpression;
class BinaryAndExpression;
class BinaryOrExpression;
class BinaryXorExpression;
class ComparisonExpression;
class IntegerExpression;
class LogicalAndExpression;
class LogicalOrExpression;
class MulDivModExpression;
class StringExpression;
class TwoOperandExpression;

class ExpressionVisitor
{
  public:
    virtual void visit(AddSubExpression &) { /*nothing*/}
    virtual void visit(BinaryAndExpression &) { /*nothing*/}
    virtual void visit(BinaryOrExpression &) { /*nothing*/}
    virtual void visit(BinaryXorExpression &) { /*nothing*/}
    virtual void visit(ComparisonExpression &) { /*nothing*/}
    virtual void visit(IntegerExpression &) { /*nothing*/}
    virtual void visit(LogicalAndExpression &) { /*nothing*/}
    virtual void visit(LogicalOrExpression &) { /*nothing*/}
    virtual void visit(MulDivModExpression &) { /*nothing*/}
    virtual void visit(StringExpression &) { /*nothing*/}
    virtual void visit(TwoOperandExpression &) { /*nothing*/}
};

#endif