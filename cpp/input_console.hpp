#ifndef INPUT_CONSOLE_HPP_
#define INPUT_CONSOLE_HPP_

#include "input.hpp"

class InputConsole : public Input {
  public:
  protected:
    //  読みとリが終了したかチェックする
    virtual bool CheckEnd(const char &data) override;

  private:
};

#endif
