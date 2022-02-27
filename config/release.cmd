@echo off
copy filament\release\CMakeSettings.json ..\third_party\filament\
copy OCCT\release\CMakeSettings.json ..\third_party\OCCT\
copy fwlab\release\CMakeSettings.json ..\
echo success
pause