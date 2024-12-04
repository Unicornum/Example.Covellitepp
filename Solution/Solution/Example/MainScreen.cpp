
#include "stdafx.h"
#include "MainScreen.hpp"
//#include <alicorn/std/string.hpp>

namespace layers
{

MainScreen::MainScreen(IWindowGui_t & _Window) :
  Layer(_Window, "Data/main.rml")
{
}

void MainScreen::Switch(void)
{
  using String_t = ::alicorn::extension::std::String;

  static const ::std::vector<String_t> BodyClases =
  {
    uT("BodyRed"),
    uT("BodyBlue"),
    uT("BodyGreen")
  };

  GetElement("id_body").SetClassStyle(BodyClases[m_Index % BodyClases.size()]);

  m_Index++;
}

} // namespace layers
