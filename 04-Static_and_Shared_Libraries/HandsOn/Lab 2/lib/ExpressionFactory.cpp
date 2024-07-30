#include "ExpressionFactory.h"

ExpressionFactory * ExpressionFactory::s_factory = nullptr;

ExpressionFactory &
ExpressionFactory::factory()
{
  if(s_factory == nullptr)
  {
    s_factory = new ExpressionFactory();
  }
  return *s_factory;
}

std::vector<Expression *> 
ExpressionFactory::getArrayOfExpressions()
{
  std::vector<Expression *> arr;

  // 1 + 2
  Expression * lval = createIntegerExpression(1);
  Expression * rval = createIntegerExpression(2);
  arr.push_back(createAddSubExpression(lval,rval, AddSubExpression::OpType::ADD));

  // 1 - 2
  lval = createIntegerExpression(1);
  rval = createIntegerExpression(2);
  arr.push_back(createAddSubExpression(lval,rval, AddSubExpression::OpType::SUB));

  // 2 && 6
  lval = createIntegerExpression(2);
  rval = createIntegerExpression(6);
  arr.push_back(createBinaryAndExpression(lval,rval));
  
  // 2 || 6
  lval = createIntegerExpression(2);
  rval = createIntegerExpression(6);
  arr.push_back(createBinaryOrExpression(lval,rval));
  
  // 2 ^ 6
  lval = createIntegerExpression(2);
  rval = createIntegerExpression(6);
  arr.push_back(createBinaryXorExpression(lval,rval));
  
  // 10 == -10
  lval = createIntegerExpression(10);
  rval = createIntegerExpression(-10);
  Expression * left = createComparisonExpression(lval,rval, ComparisonExpression::OpType::EQUAL);
  arr.push_back(left);
  
  // 10 != -10
  lval = createIntegerExpression(10);
  rval = createIntegerExpression(-10);
  Expression * right = createComparisonExpression(lval,rval, ComparisonExpression::OpType::NOT_EQUAL);
  arr.push_back(right);

  // 10 == -10 && 10 != -10
  arr.push_back(createLogicalAndExpression(left, right));
  
  // 10 == -10 || 10 != -10
  arr.push_back(createLogicalOrExpression(left, right));

  return arr;

}

ExactValue *
ExpressionFactory::createExactValue(int val)
{
  return new ExactValue(val);
}

ExactValue *
ExpressionFactory::createExactValue(std::string val)
{
  return new ExactValue(val);
}

AddSubExpression * 
ExpressionFactory::createAddSubExpression(
  Expression * left,
  Expression * right,
  AddSubExpression::OpType opType)
{
  return new AddSubExpression(left->type(), left, right,opType);
}

BinaryAndExpression * 
ExpressionFactory::createBinaryAndExpression(
  Expression * left,
  Expression * right)
{
  return new BinaryAndExpression(left->type(), left, right);
}

BinaryOrExpression * 
ExpressionFactory::createBinaryOrExpression(
  Expression * left,
  Expression * right)
{
  return new BinaryOrExpression(left->type(), left, right);
}

BinaryXorExpression * 
ExpressionFactory::createBinaryXorExpression(
  Expression * left,
  Expression * right)
{
  return new BinaryXorExpression(left->type(), left, right);
}

ComparisonExpression * 
ExpressionFactory::createComparisonExpression(
  Expression * left,
  Expression * right,
  ComparisonExpression::OpType opType)
{
  return new ComparisonExpression(left->type(), left, right,opType);
}

IntegerExpression * 
ExpressionFactory::createIntegerExpression(int value)
{
  ExactValue * exValue = createExactValue(value);
  return new IntegerExpression(ExpressionType::INTEGER, exValue);
}

LogicalAndExpression * 
ExpressionFactory::createLogicalAndExpression(
  Expression * left,
  Expression * right)
{
  return new LogicalAndExpression(left->type(), left, right);
}

LogicalOrExpression * 
ExpressionFactory::createLogicalOrExpression(
  Expression * left,
  Expression * right)
{
  return new LogicalOrExpression(left->type(), left, right);
}

MulDivModExpression * 
ExpressionFactory::createMulDivModExpression(
  Expression * left,
  Expression * right,
  MulDivModExpression::OpType opType)
{
  return new MulDivModExpression(left->type(), left, right,opType);
}

StringExpression *
ExpressionFactory::createStringExpression(
  std::string name)
{
  ExactValue * exValue = createExactValue(name);
  return new StringExpression(ExpressionType::STRING, exValue);
}