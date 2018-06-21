//
// Created by Ludovica Pagliarani on 20/06/2018.
//

#ifndef IGRPHGAME_HPP
#define IGRPHGAME_HPP

namespace graphic
{
  class IGrphGame
  {
  public:
      virtual ~IGrphGame() = default;
      virtual void display() = 0;
      virtual void eventManager() = 0;
  };
};
#endif //IGRPHGAME_HPP
