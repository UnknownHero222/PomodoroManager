cmake_minimum_required(VERSION 3.5)

project(PomodoroManager LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.
find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(PomodoroManager
    main.cpp
    pomodoro_manager_wdg.cpp
    pomodoro_manager_wdg.h
    pomodoro_manager_wdg.ui
    notification_window.ui
    notification_window.h
    notification_window.cpp
    resources.qrc
)

target_link_libraries(PomodoroManager PRIVATE Qt5::Widgets)
