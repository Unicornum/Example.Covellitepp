
#include "stdafx.h"
#include "ExampleWindow.hpp"
#include "MainScreen.hpp"

ExampleWindow::ExampleWindow(WindowGui_t & _WindowGui) :
  m_Events(_WindowGui)
{
  // Экран, который будет отображаться при старте программы.
  auto * pMainScreen = &_WindowGui.PushLayer<::layers::MainScreen>();

  m_Events[::covellite::events::Cursor.Touch]
    .Connect([=](void)
  {
    pMainScreen->Switch();
  });
}
