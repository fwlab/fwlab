# fwlab

fwlab是一个人工智能实验室。

## 编译说明

1. 在`Windows`上安装`git`和`Visual Studio 2019`。

2. 使用git下载代码。

```sh
git clone https://gitee.com/fwlab/fwlab.git
cd fwlab
git submodule update --init
```

3. 使用`Visual Studio 2019`，分别打开文件夹`third_party/bullet3`和`third_party/filament`，
在`CMakeLists.txt`文件上右键，点击`生成`，生成依赖的第三方项目。

4. 使用`Visual Studio 2019`打开`fwlab`文件夹，在`CMakeLists.txt`文件上右键，点击`生成`，
生成的`fwlab.exe`在`out/build/x64-Debug/src`目录下。
