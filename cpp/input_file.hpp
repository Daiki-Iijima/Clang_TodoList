#ifndef INPUT_FILE_HPP_
#define INPUT_FILE_HPP_

#include "input.hpp"

class InputFile : public Input {
  public:
  protected:
    //  読みとリが終了したかチェックする
    virtual bool CheckEnd(const char &data) override;

  private:
};

#endif
