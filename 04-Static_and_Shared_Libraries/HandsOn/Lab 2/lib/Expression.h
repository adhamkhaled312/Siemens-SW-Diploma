#ifndef INCLUDED_EXPRESSION_H
#define INCLUDED_EXPRESSION_H

#include <iostream>

class ExpressionVisitor;
/**
 * @brief Class for Expression Value
*/
class ExactValue
{
  public:
    ExactValue(int value);
    ExactValue(std::string value);

    int intValue(void) { return d_intValue; }
    std::string strValue(void) { return d_strValue; }

    void print(void);
    
  private:
    int d_intValue;
    std::string d_strValue;
    bool d_isInt;
};

/**
 * @brief Expression Types Enum
*/
enum ExpressionType {
        INTEGER,
        STRING
};

/**
 * @brief Base class for all expressions
*/
class Expression
{
  public:
    Expression(ExpressionType type,
               ExactValue * value);

    const ExpressionType & type(void) 
      { return d_type; }

    bool isString(void) {return ExpressionType::STRING == d_type;}
    bool isInt(void) { return ExpressionType::INTEGER == d_type;}
    virtual void accept(ExpressionVisitor &) = 0;

    ExactValue * value(void) { return p_value; }
  protected:
    ExpressionType d_type;
    ExactValue * p_value;
};

#endif