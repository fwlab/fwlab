@echo off
mkdir tools
xcopy /Y filament\out\build\x64-Debug\tools\cmgen\cmgen.exe tools\
xcopy /Y filament\out\build\x64-Debug\tools\cso-lut\cso-lut.exe tools\
xcopy /Y filament\out\build\x64-Debug\tools\filamesh\filamesh.exe tools\
xcopy /Y filament\out\build\x64-Debug\tools\glslminifier\glslminifier.exe tools\
xcopy /Y filament\out\build\x64-Debug\tools\matc\matc.exe tools\
xcopy /Y filament\out\build\x64-Debug\tools\matinfo\matinfo.exe tools\
xcopy /Y filament\out\build\x64-Debug\tools\mipgen\mipgen.exe tools\
xcopy /Y filament\out\build\x64-Debug\tools\normal-blending\normal-blending.exe tools\
xcopy /Y filament\out\build\x64-Debug\tools\resgen\resgen.exe tools\
xcopy /Y filament\out\build\x64-Debug\tools\rgb-to-lmsr\rgb-to-lmsr.exe tools\
xcopy /Y filament\out\build\x64-Debug\tools\roughness-prefilter\roughness-prefilter.exe tools\
xcopy /Y filament\out\build\x64-Debug\tools\specular-color\specular-color.exe tools\
echo success
pause