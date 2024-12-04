
#pragma once
#include <Covellite/Covellite.hpp>

/**
* \ingroup ExampleGroup
* \brief
*  Класс входит в проект \ref ExamplePage \n
*  Класс главного объекта (точка входа) программы.
*  
* \version
*  1.0.0.0        \n
* \date
*  04 Декабрь 2024    \n
* \author
*  CTAPOBEP (unicornum.verum@gmail.com)
* \copyright
*  © CTAPOBEP 2024
*/
class ExampleApp final :
  public ::covellite::app::Application
{
private:
  void DoInitWindow(void);

public:
  ExampleApp(void) noexcept;
};
