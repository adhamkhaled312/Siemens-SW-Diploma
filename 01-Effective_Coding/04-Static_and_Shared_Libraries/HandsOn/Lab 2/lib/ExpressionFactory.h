#ifndef INCLUDED_EXPRESSIONFACTORY_H
#define INCLUDED_EXPRESSIONFACTORY_H

#include "AddSubExpression.h"
#include "BinaryAndExpression.h"
#include "BinaryOrExpression.h"
#include "BinaryXorExpression.h"
#include "ComparisonExpression.h"
#include "IntegerExpression.h"
#include "LogicalAndExpression.h"
#include "LogicalOrExpression.h"
#include "MulDivModExpression.h"
#include "StringExpression.h"
#include <vector>

class ExpressionFactory
{
  private:
    ExpressionFactory(){}
  public:
    static ExpressionFactory * s_factory;
    static ExpressionFactory & factory();
    std::vector<Expression *> getArrayOfExpressions();
    ExactValue * createExactValue(int val);
    ExactValue * createExactValue(std::string val);
    AddSubExpression * createAddSubExpression(
      Expression * left,
      Expression * right,
      AddSubExpression::OpType opType);
    BinaryAndExpression * createBinaryAndExpression(
      Expression * left,
      Expression * right);
    BinaryOrExpression * createBinaryOrExpression(
      Expression * left,
      Expression * right);
    BinaryXorExpression * createBinaryXorExpression(
      Expression * left,
      Expression * right);
    ComparisonExpression * createComparisonExpression(
      Expression * left,
      Expression * right,
      ComparisonExpression::OpType opType);
    IntegerExpression * createIntegerExpression(int value);
    LogicalAndExpression * createLogicalAndExpression(
      Expression * left,
      Expression * right);
    LogicalOrExpression * createLogicalOrExpression(
      Expression * left,
      Expression * right);
    MulDivModExpression * createMulDivModExpression(
      Expression * left,
      Expression * right,
      MulDivModExpression::OpType opType);
    StringExpression * createStringExpression(
      std::string name);
};
#endif