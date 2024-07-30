#include <iostream>
#include "lib/ExpressionFactory.h"
#include <vector>
#include "lib/ExpressionPrinter.h"
#include "lib/ExpressionExecuter.h"

int main()
{
  ExpressionFactory & factory = ExpressionFactory::factory();

  std::vector<Expression *> vec = factory.getArrayOfExpressions();

  for(unsigned int i =0 ; i< vec.size(); i++)
  {
    ExpressionPrinter {vec[i]};
    ExpressionExecuter executer {vec[i]};
    std::cout << "Value:";
    if(vec[i]->isInt())
    {
      std::cout << executer.value()->intValue();
    }
    else
    {
      std::cout << executer.value()->strValue();
    }
    std::cout<< std::endl << std::endl;
  }
  // IntegerExpression i(ExpressionType::INTEGER, 10);
  // std:: cout << "Integer: "<< i.value() << std::endl;
  return 0;
}