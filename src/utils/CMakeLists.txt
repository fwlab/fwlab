set(MODULE_NAME fwlab_utils)

add_library(${MODULE_NAME} STATIC
    "Clock.cpp"
    "TimeUtils.cpp"
    "Logger.cpp"
    "SDLUtils.cpp"
)
