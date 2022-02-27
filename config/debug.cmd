@echo off
copy filament\debug\CMakeSettings.json ..\third_party\filament\
copy OCCT\debug\CMakeSettings.json ..\third_party\OCCT\
copy fwlab\debug\CMakeSettings.json ..\
echo success
pause