#include "react-native-another-test.h"
#include <iostream>

using namespace facebook;
using namespace std;

void installSequel(jsi::Runtime &rt)
{
  cout << "Installing JSI bindings" << endl;

  auto multiplyLambda = [](jsi::Runtime &rt, const jsi::Value &thisValue, const jsi::Value *args, size_t count) -> jsi::Value
  {
    if (count > 2) {
      jsi::JSError(rt, "Too many arguments");
    }
    
    if (!args[0].isNumber()) {
      jsi::JSError(rt, "Arg 0 is not a number");
    }
    
    double arg0 = args[0].asNumber();
    
    if (!args[1].isNumber()) {
      jsi::JSError(rt, "Arg 1 is not a number");
    }
    
    double arg1 = args[1].asNumber();
    
    return  jsi::Value(arg0 * arg1);
  };

  jsi::Function multiply = jsi::Function::createFromHostFunction(rt, jsi::PropNameID::forAscii(rt, "multiply"), 2, std::move(multiplyLambda));

  rt.global().setProperty(rt, "jsiMultiply", std::move(multiply));
}

void cleanUpSequel()
{
  cout << "Cleaning up JSI bindings" << endl;
}
