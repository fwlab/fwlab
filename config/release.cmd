@echo off
copy filament\release\CMakeSettings.json ..\third_party\filament\
copy bullet3\release\CMakeSettings.json ..\third_party\bullet3\
copy OCCT\release\CMakeSettings.json ..\third_party\OCCT\
copy fwlab\release\CMakeSettings.json ..\
echo success
pause