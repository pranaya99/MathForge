// Copyright 2025 Pranaya Rao Ganta
#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include "./stack.h"

bool Operator(const std::string &token)
{
  return token == "+" || token == "-" || token == "*" || token == "/";
}

double evaluate_postfix(const std::string &expression)
{
  Stack<double> stack;
  std::istringstream iss(expression);
  std::string token;

  while (iss >> token)
  {
    if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-'))
    {
      // Push numbers onto the stack
      stack.Push(std::stod(token));
    }
    else if (Operator(token))
    {
      // Perform operations
      if (stack.Size() < 2)
      {
        throw std::invalid_argument(
            "Invalid expression: insufficient operands");
      }
      double operand2 = stack.Pop();
      double operand1 = stack.Pop();
      if (token == "+")
      {
        stack.Push(operand1 + operand2);
      }
      else if (token == "-")
      {
        stack.Push(operand1 - operand2);
      }
      else if (token == "*")
      {
        stack.Push(operand1 * operand2);
      }
      else if (token == "/")
      {
        if (operand2 == 0)
        {
          throw std::invalid_argument("Division by zero");
        }
        stack.Push(operand1 / operand2);
      }
    }
    else
    {
      throw std::invalid_argument("Unknown symbol: " + token);
    }
  }

  if (stack.Size() != 1)
  {
    throw std::invalid_argument("Invalid expression: too many operands");
  }

  return stack.Pop();
}

int main()
{
  std::string line;
  while (std::getline(std::cin, line))
  {
    try
    {
      double result = evaluate_postfix(line);
      std::cout << result << std::endl;
    }
    catch (const std::exception &e)
    {
      std::cerr << "Error: " << e.what() << std::endl;
    }
  }
  std::cout << "Bye!" << std::endl;
  return 0;
}
