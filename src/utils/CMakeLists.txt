set(MODULE_NAME fwlab_utils)

add_library(${MODULE_NAME} STATIC
    "TimeUtils.cpp"
    "Logger.cpp"
    "SDLUtils.cpp"
)
