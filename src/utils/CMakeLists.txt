set(MODULE_NAME fwlab_utils)

add_library(${MODULE_NAME} STATIC
    "Clock.cpp"
    "DirectoryUtils.cpp"
    "EncodingUtils.cpp"
    "ImageUtils.cpp"
    "Logger.cpp"
    "SDLUtils.cpp"
    "TimeUtils.cpp"
    "Utils.cpp"
)
