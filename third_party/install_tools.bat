@echo off
mkdir tools
cp -f filament\out\build\x64-Debug\tools\cmgen\cmgen.exe tools\cmgen.exe
cp -f filament\out\build\x64-Debug\tools\cso-lut\cso-lut.exe tools\cso-lut.exe
cp -f filament\out\build\x64-Debug\tools\filamesh\filamesh.exe tools\filamesh.exe
cp -f filament\out\build\x64-Debug\tools\glslminifier\glslminifier.exe tools\glslminifier.exe
cp -f filament\out\build\x64-Debug\tools\matc\matc.exe tools\matc.exe
cp -f filament\out\build\x64-Debug\tools\matinfo\matinfo.exe tools\matinfo.exe
cp -f filament\out\build\x64-Debug\tools\mipgen\mipgen.exe tools\mipgen.exe
cp -f filament\out\build\x64-Debug\tools\normal-blending\normal-blending.exe tools\normal-blending.exe
cp -f filament\out\build\x64-Debug\tools\resgen\resgen.exe tools\resgen.exe
cp -f filament\out\build\x64-Debug\tools\rgb-to-lmsr\rgb-to-lmsr.exe tools\rgb-to-lmsr.exe
cp -f filament\out\build\x64-Debug\tools\roughness-prefilter\roughness-prefilter.exe tools\roughness-prefilter.exe
cp -f filament\out\build\x64-Debug\tools\specular-color\specular-color.exe tools\specular-color.exe
echo success
pause