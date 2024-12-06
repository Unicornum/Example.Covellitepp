
#pragma once
#include <Covellite/Covellite.hpp>

namespace layers
{

/**
* \ingroup ExampleGroup
* \brief
*  ����� ������ � ������ \ref ExamplePage \n
*  ����� �������� ������ ���������.
*  
* \version
*  1.0.0.0        \n
* \date
*  04 ������� 2024    \n
* \author
*  CTAPOBEP (unicornum.verum@gmail.com)
* \copyright
*  � CTAPOBEP 2024
*/
class MainScreen final :
  public ::covellite::gui::Layer
{
public:
  void Switch(void);

private:
  int m_Index = 0;

public:
  explicit MainScreen(IWindowGui_t &);
};

} // namespace layers
