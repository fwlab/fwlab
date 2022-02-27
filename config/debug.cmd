@echo off
copy filament\debug\CMakeSettings.json ..\third_party\filament\
copy rapidjson\debug\CMakeSettings.json ..\third_party\rapidjson\
copy fwlab\debug\CMakeSettings.json ..\
echo success
pause