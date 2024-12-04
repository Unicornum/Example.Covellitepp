
#include "stdafx.h"
#include "ExampleApp.hpp"
#include <alicorn/application/current-module.hpp>
#include "ExampleWindow.hpp"
//#include "BasementWindow.hpp"

ExampleApp::ExampleApp(void) noexcept :
  Application(Continuous{})
{
  namespace events = ::covellite::events;
    
  m_Events[events::Application.Start]
    .Connect([&]() { DoInitWindow(); } );
  m_Events[events::Error.Exception]
    .Connect([](const events::Error_t::Description & /*_Description*/)
      { /* Обработчик ошибок во время работы программы */ });

  using ::alicorn::system::application::CurrentModule;

  // В Android будет ошибка, игнорируем ее.
  ::boost::system::error_code ErrorCode;
  ::boost::filesystem::current_path(CurrentModule::GetAppRootPath(), ErrorCode);
}

void ExampleApp::DoInitWindow(void)
{
  // Создание обязательного набора объектов окон приложения.
    
  const auto & wOs =                           // Класс фреймворка окна операционной системы.
    MakeWindow<::covellite::os::Window>(*this);     
  const auto & wApi =                          // Класс фреймворка окна графического Api
    MakeWindow<::covellite::api::Window>(wOs); // (реализация DirectX/OpenGL задается в настройках).
  //auto & wExpanse =                            // Класс фреймворка окна, обеспечивающего отрисовку 3D сцены.
    MakeWindow<::covellite::expanse::Window>(wApi);
  //auto & wBasement =
    //MakeWindow<BasementWindow>(wApi, wExpanse);  // Клиентский код, формирующий 3D сцену.
  auto & wGui =                                  // Класс фреймворка окна, обеспечивающего отрисовку GUI.
    MakeWindow<::covellite::gui::Window>(wApi);
  //auto & wExample =
    MakeWindow<ExampleWindow>(wGui);             // Клиентсткий код программы, управляющий
                                                 // переходами между разными слоями GUI.
}

// Точка входа в программу
APPLICATION_ENTRY_POINT(ExampleApp);
