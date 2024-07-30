#include "ExpressionPrinter.h"
#include "ExpressionFactory.h"
#include <iostream>

ExpressionPrinter::ExpressionPrinter(Expression * expr)
  : d_indentation(0)
{
  expr->accept(*this);
}

void
ExpressionPrinter::printIndentation()
{
  for(int i = 0; i < d_indentation ;i++)
    std::cout << " ";
}

void 
ExpressionPrinter::visit(AddSubExpression & expr)
{
  d_indentation++;
  std::cout<< "Expression AddSubExpreession:\n";

  printIndentation();
  std::cout<<"Left Expr: ";
  expr.leftExpr()->accept(*this);

  printIndentation();
  std::cout << "Right Expr: ";
  expr.rightExpr()->accept(*this);
  std::cout<< std::endl;
  d_indentation--;
}

void 
ExpressionPrinter::visit(BinaryAndExpression & expr)
{
  d_indentation++;
  std::cout<< "Expression BinaryAndExpression:\n";

  printIndentation();
  std::cout<<"Left Expr: ";
  expr.leftExpr()->accept(*this);

  printIndentation();
  std::cout << "Right Expr: ";
  expr.rightExpr()->accept(*this);
  std::cout<< std::endl;

  d_indentation--;
}

void 
ExpressionPrinter::visit(BinaryOrExpression & expr)
{
  d_indentation++;
  std::cout<< "Expression BinaryOrExpression:\n";

  printIndentation();
  std::cout<<"Left Expr: ";
  expr.leftExpr()->accept(*this);

  printIndentation();
  std::cout << "Right Expr: ";
  expr.rightExpr()->accept(*this);
  std::cout<< std::endl;

  d_indentation--;
}

void 
ExpressionPrinter::visit(BinaryXorExpression & expr)
{
  d_indentation++;
  std::cout<< "Expression BinaryXorExpression:\n";

  printIndentation();
  std::cout<<"Left Expr: ";
  expr.leftExpr()->accept(*this);

  printIndentation();
  std::cout << "Right Expr: ";
  expr.rightExpr()->accept(*this);
  std::cout<< std::endl;

  d_indentation--;
}

void 
ExpressionPrinter::visit(ComparisonExpression & expr)
{
  d_indentation++;
  std::cout<< "Expression ComparisonExpression:\n";

  printIndentation();
  std::cout<<"Left Expr: ";
  expr.leftExpr()->accept(*this);

  printIndentation();
  std::cout << "Right Expr: ";
  expr.rightExpr()->accept(*this);
  std::cout<< std::endl;

  d_indentation--;
}

void 
ExpressionPrinter::visit(IntegerExpression & expr)
{
  std::cout << "IntegerExpression value:" <<expr.value()->intValue() << std::endl;
}

void 
ExpressionPrinter::visit(LogicalAndExpression & expr)
{
  d_indentation++;
  std::cout<< "Expression LogicalAndExpression:\n";

  printIndentation();
  std::cout<<"Left Expr: ";
  expr.leftExpr()->accept(*this);

  printIndentation();
  std::cout << "Right Expr: ";
  expr.rightExpr()->accept(*this);
    std::cout<< std::endl;

  d_indentation--;

}
void 
ExpressionPrinter::visit(LogicalOrExpression & expr)
{
  d_indentation++;
  std::cout<< "Expression LogicalOrExpression:\n";

  printIndentation();
  std::cout<<"Left Expr: ";
  expr.leftExpr()->accept(*this);

  printIndentation();
  std::cout << "Right Expr: ";
  expr.rightExpr()->accept(*this);
  std::cout<< std::endl;

  d_indentation--;
}

void 
ExpressionPrinter::visit(MulDivModExpression & expr)
{
  d_indentation++;
  std::cout<< "Expression MulDivModExpression:\n";

  printIndentation();
  std::cout<<"Left Expr: ";
  expr.leftExpr()->accept(*this);

  printIndentation();
  std::cout << "Right Expr: ";
  expr.rightExpr()->accept(*this);
  std::cout<< std::endl;

  d_indentation--;
}

void 
ExpressionPrinter::visit(StringExpression & expr)
{
  std::cout << "StringExpression value:" <<expr.value()->strValue() << std::endl;
}

void 
ExpressionPrinter::visit(TwoOperandExpression & expr)
{
  /*nothing*/
}