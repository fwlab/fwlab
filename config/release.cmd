@echo off
copy filament\release\CMakeSettings.json ..\third_party\filament\
copy rapidjson\release\CMakeSettings.json ..\third_party\rapidjson\
copy fwlab\release\CMakeSettings.json ..\
echo success
pause