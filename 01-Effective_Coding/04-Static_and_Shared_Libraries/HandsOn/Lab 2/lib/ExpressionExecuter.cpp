#include "ExpressionExecuter.h"
#include "ExpressionFactory.h"
#include <iostream>

ExpressionExecuter::ExpressionExecuter(Expression * expr)
 : p_value(nullptr)
{
  expr->accept(*this);
}

void 
ExpressionExecuter::visit(AddSubExpression & expr)
{
  expr.leftExpr()->accept(*this);
  ExactValue * left = p_value;
  expr.rightExpr()->accept(*this);
  ExactValue * right = p_value;

  if(expr.type() == ExpressionType::INTEGER)
  {
    int leftInt = left->intValue();
    int rightInt = right->intValue();
    if(expr.isAddition())
      p_value = ExpressionFactory::factory().createExactValue(leftInt + rightInt);
    else if(expr.isSubtraction())
      p_value = ExpressionFactory::factory().createExactValue(leftInt - rightInt);
  }
  else
  {
    std::string leftStr = left->strValue();
    std::string rightStr = right->strValue();
    if(expr.isAddition())
      p_value = ExpressionFactory::factory().createExactValue(leftStr + rightStr);
  }
}

void 
ExpressionExecuter::visit(BinaryAndExpression & expr)
{
  expr.leftExpr()->accept(*this);
  ExactValue * left = p_value;
  expr.rightExpr()->accept(*this);
  ExactValue * right = p_value;

  if(expr.type() == ExpressionType::INTEGER)
  {
    int leftInt = left->intValue();
    int rightInt = right->intValue();
    p_value = ExpressionFactory::factory().createExactValue(leftInt & rightInt);
  }
  else
  {
    p_value = nullptr;
  }
}

void 
ExpressionExecuter::visit(BinaryOrExpression & expr)
{
  expr.leftExpr()->accept(*this);
  ExactValue * left = p_value;
  expr.rightExpr()->accept(*this);
  ExactValue * right = p_value;

  if(expr.type() == ExpressionType::INTEGER)
  {
    int leftInt = left->intValue();
    int rightInt = right->intValue();
    p_value =   ExpressionFactory::factory().createExactValue(leftInt | rightInt);
  }
  else
  {
    p_value = nullptr;
  }
}

void 
ExpressionExecuter::visit(BinaryXorExpression & expr)
{
  expr.leftExpr()->accept(*this);
  ExactValue * left = p_value;
  expr.rightExpr()->accept(*this);
  ExactValue * right = p_value;

  if(expr.type() == ExpressionType::INTEGER)
  {
    int leftInt = left->intValue();
    int rightInt = right->intValue();
    p_value =   ExpressionFactory::factory().createExactValue(leftInt ^ rightInt);
  }
  else
  {
    p_value = nullptr;
  }
}

void 
ExpressionExecuter::visit(ComparisonExpression & expr)
{
  
  expr.leftExpr()->accept(*this);
  ExactValue * left = p_value;
  expr.rightExpr()->accept(*this);
  ExactValue * right = p_value;

  if(expr.type() == ExpressionType::INTEGER)
  {
    int leftInt = left->intValue();
    int rightInt = right->intValue();
    if(expr.isEqualExpression())
      p_value = ExpressionFactory::factory().createExactValue(leftInt == rightInt);
    else
      p_value = ExpressionFactory::factory().createExactValue(leftInt != rightInt);
  }
  else
  {
    std::string leftStr = left->strValue();
    std::string rightStr = right->strValue();
    if(expr.isEqualExpression())
      p_value = ExpressionFactory::factory().createExactValue(leftStr == rightStr);
    else
      p_value = ExpressionFactory::factory().createExactValue(leftStr != rightStr);
  }
}

void 
ExpressionExecuter::visit(IntegerExpression & expr)
{
  p_value = expr.value();
}

void 
ExpressionExecuter::visit(LogicalAndExpression & expr)
{
  expr.leftExpr()->accept(*this);
  ExactValue * left = p_value;
  expr.rightExpr()->accept(*this);
  ExactValue * right = p_value;
  int leftInt = left->intValue();
  int rightInt = right->intValue();

  p_value = ExpressionFactory::factory().createExactValue(leftInt && rightInt);

}
void 
ExpressionExecuter::visit(LogicalOrExpression & expr)
{
  expr.leftExpr()->accept(*this);
  ExactValue * left = p_value;
  expr.rightExpr()->accept(*this);
  ExactValue * right = p_value;
  int leftInt = left->intValue();
  int rightInt = right->intValue();

  p_value = ExpressionFactory::factory().createExactValue(leftInt || rightInt);
}

void 
ExpressionExecuter::visit(MulDivModExpression & expr)
{
  expr.leftExpr()->accept(*this);
  ExactValue * left = p_value;
  expr.rightExpr()->accept(*this);
  ExactValue * right = p_value;

  if(expr.type() == ExpressionType::INTEGER)
  {
    int leftInt = left->intValue();
    int rightInt = right->intValue();
    if(expr.isMultiplication())
      p_value = ExpressionFactory::factory().createExactValue(leftInt * rightInt);
    else if(expr.isDivision())
      p_value = ExpressionFactory::factory().createExactValue(leftInt / rightInt);
    else if(expr.isModulus())
      p_value = ExpressionFactory::factory().createExactValue(leftInt % rightInt);
  }
  else
  {
    p_value = nullptr;
  }
}

void 
ExpressionExecuter::visit(StringExpression & expr)
{
  p_value = expr.value();
}

void 
ExpressionExecuter::visit(TwoOperandExpression & expr)
{
  /*nothing*/
}