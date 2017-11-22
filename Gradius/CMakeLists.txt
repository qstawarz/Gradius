cmake_minimum_required(VERSION 3.8)
project(Gradius)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp src/Managers/Game.cpp includes/Managers/Game.h src/Managers/DisplayManager.cpp includes/Managers/DisplayManager.h src/Actors/Player.cpp includes/Actors/Player.h src/Actors/Enemy.cpp includes/Actors/Enemy.h src/Managers/EnemyManager.cpp includes/Managers/EnemyManager.h src/Managers/InputManager.cpp includes/Managers/InputManager.h src/Actors/Bullet.cpp includes/Actors/Bullet.h src/Managers/BulletManager.cpp includes/Managers/BulletManager.h src/Utils/Sprite.cpp includes/Utils/Sprite.h includes/Managers/IManager.h src/Managers/SpriteManager.cpp includes/Managers/SpriteManager.h src/Utils/UI.cpp includes/Utils/UI.h includes/Actors/IActor.h)
add_executable(Gradius ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Gradius ${SFML_LIBRARIES})
endif()