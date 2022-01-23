# fwlab

fwlab是一个人工智能实验室。

![image](image/screenshot.png)

## 编译说明

1. 安装以下软件：

```sh
sudo apt install clang libglu1-mesa-dev libc++-dev libc++abi-dev ninja-build libxi-dev cmake
```

* ninja下载地址：https://github.com/ninja-build/ninja/releases
* cmake下载地址：https://github.com/Kitware/CMake/releases

2. 使用`clang`作为默认编译器。

```sh
sudo update-alternatives --install /usr/bin/cc cc /usr/bin/clang 100
sudo update-alternatives --install /usr/bin/c++ c++ /usr/bin/clang++ 100
```

3. 在`third_party/filament`目录执行以下代码。

```sh
mkdir -p out/cmake-release
cd out/cmake-release
cmake -G Ninja -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=../../../release/filament ../..
ninja
ninja install
```

4. 将`third_party/release/filament/bin`目录添加到环境变量。

```sh
cd /etc/profile.d
sudo gedit filament.sh
```
将`third_party/release/filament/bin`的绝对路径添加到`filament.sh`文件中，例如：

```sh
export PATH=/home/user/fwlab/third_party/release/filament/bin:$PATH
```

给予执行权限：`sudo chmod +x filament.sh`

验证是否添加成功。

```sh
source filament.sh
echo $PATH
```

5. 在`fwlab`根目录执行以下代码。

```
mkdir build
cd build
cmake ..
make
```