# fwlab

fwlab是一个人工智能实验室。

![image](image/screenshot.png)

## 使用Ubuntu编译项目

1. 下载项目。

```sh
git clone https://gitee.com/fwlab/fwlab.git
cd fwlab
git submodule update --init
```

2. 安装以下软件：

```sh
sudo apt install build-essential clang libglu1-mesa-dev libc++-dev libc++abi-dev ninja-build libxi-dev cmake

sudo apt install libsdl2-2.0-0 libsdl2-dev
```

* ninja下载地址：https://github.com/ninja-build/ninja/releases
* cmake下载地址：https://github.com/Kitware/CMake/releases

3. 使用`clang`作为默认编译器。

```sh
sudo update-alternatives --install /usr/bin/cc cc /usr/bin/clang 100
sudo update-alternatives --install /usr/bin/c++ c++ /usr/bin/clang++ 100
```

4. 在`third_party/filament`目录执行以下代码。

```sh
mkdir -p out/build
cd out/build
cmake -G Ninja -DCMAKE_BUILD_TYPE=Debug -DFILAMENT_SUPPORTS_VULKAN=OFF -DCMAKE_INSTALL_PREFIX=../install ../..
ninja
ninja install
```

5. 将`third_party/filament/out/install/bin`目录添加到环境变量。

```sh
cd /etc/profile.d
sudo sh -c 'echo export PATH=/home/{username}/fwlab/third_party/filament/out/release/filament/bin:\$PATH > filament.sh'
sudo chmod +x filament.sh
source filament.sh
echo $PATH
```

6. 在`fwlab`根目录执行以下代码。

```
mkdir -p out/build
cd out/build
cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=../install ../..
make
```

## 使用Windows编译项目

1. 下载项目。

```sh
git clone https://gitee.com/fwlab/fwlab.git
cd fwlab
git submodule update --init
```

2. 安装以下软件：

Visual Studio 2019, 安装时选中使用C++的桌面开发。

3. 编译`third_party/filament`项目。

将`config/filament/debug/CMakeSettings.json`或`config/filament/release/CMakeSettings.json`拷贝到`third_party/filament`目录。

使用Visual Studio 2019打开目录`third_party/filament`。

右键`CMakeLists.txt`，选择生成。

右键`CMakeLists.txt`，选择安装。

将目录`third_party/filament/out/install/bin`添加到环境变量，保证`cmgen`、`matc`、`resgen`能在命令行运行。

4. 编译`fwlab`项目。

将`config/fwlab/debug/CMakeSettings.json`或`config/fwlab/release/CMakeSettings.json`拷贝到项目根目录。

使用Visual Studio 2019打开目录`fwlab`。

右键`CMakeLists.txt`，选择生成，生成的文件是`out/build/fwlab.exe`。

工具栏设置启动项为`out/build/fwlab.exe`，点击`fwlab.exe`启动程序。