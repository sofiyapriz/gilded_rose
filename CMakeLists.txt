cmake_minimum_required(VERSION 3.14)
project(GildedRose CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(UPDATER_SOURCES
    updaters/NormalItemUpdater.cpp
    updaters/AgedBrieUpdater.cpp
    updaters/SulfurasUpdater.cpp
    updaters/BackstagePassUpdater.cpp
    updaters/ConjuredItemUpdater.cpp
    updaters/ItemUpdaterFactory.cpp
)

add_executable(app
    GildedRose.cc
    main.cpp
    ${UPDATER_SOURCES}
)

add_executable(tests
    GildedRose.cc
    tests/test_gilded_rose.cpp
    ${UPDATER_SOURCES}
)

target_include_directories(app PRIVATE .)
target_include_directories(tests PRIVATE .)