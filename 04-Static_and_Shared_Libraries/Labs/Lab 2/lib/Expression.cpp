#include "Expression.h"

ExactValue::ExactValue(int value): d_intValue(value),
                                   d_isInt(true)
{

}

ExactValue::ExactValue(std::string value): d_strValue(value),
                                           d_isInt(false)
{

}

Expression::Expression(ExpressionType type,
                       ExactValue * value
  ): d_type(type),
     p_value(value)
{
  /* nothing */
}