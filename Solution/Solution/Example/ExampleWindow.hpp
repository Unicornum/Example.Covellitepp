
#pragma once
#include <Covellite/Covellite.hpp>

/**
* \ingroup ExampleGroup
* \brief
*  Класс входит в проект \ref ExamplePage \n
*  Класс GUI окна программы.
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
class ExampleWindow final :
  public ::covellite::app::IWindow
{
  using Events_t = ::covellite::events::Events;
  using WindowGui_t = ::covellite::gui::Window;

private:
  Events_t m_Events;

public:
  explicit ExampleWindow(WindowGui_t &);
};
