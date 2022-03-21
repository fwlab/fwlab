@echo off
copy filament\debug\CMakeSettings.json ..\third_party\filament\
copy bullet3\debug\CMakeSettings.json ..\third_party\bullet3\
copy OCCT\debug\CMakeSettings.json ..\third_party\OCCT\
copy fwlab\debug\CMakeSettings.json ..\
echo success
pause