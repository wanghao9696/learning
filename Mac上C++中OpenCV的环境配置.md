# Mac上C++中opencv的环境配置
## 安装opencv
> brew install opencv

或  
> git clone (opencv的github链接，-b指定版本分支)  
cd opencv  
mkdir build  
cd build  
#注意下一步最后有两个点，markdown编辑出来可能显示有问题  
cmake -D CMAKE_BUILD_TYPE=Release -D CMAKE_INSTALL_PREFIX=/usr/local ..  
make -j8  
make install  

完成!

使用该指令可查看是否成功安装opencv  
> pkg-config --cflags --libs opencv

若没有pkg-config可直接brew install pkg-config  
关于pkg-config的介绍可参考：[这篇博客](https://blog.csdn.net/newchenxf/article/details/51750239)  
以上即完成opencv的安装!


## opencv在c++中的使用
### 使用g++ 编译c++ ：
> g++ main.cpp -o main -L 库文件所在路径 -l 库文件名字  

比如：用到<opencv2/higngui.hpp>，就可以
> g++ main.cpp -o main -L /usr/local/include/opencv -l opencv_highgui

或直接
> g++ $(pkg-config --cflags --libs opencv) main.cpp -o main

### 使用cmake编译c++：
新建CMakeLists.txt，输入以下内容：

    cmake_minimum_required(VERSION 3.12)
    project(main)

    set(CMAKE_CXX_STANDARD 11)

    find_package(OpenCV REQUIRED)

    include_directories(${OpenCV_INCLUDE_DIRS})
    set(CMAKE_CXX_STANDARD 11)

    add_executable(main main.cpp)

    target_link_libraries(main ${OpenCV_LIBS})



添加环境变量（应该不添加环境变量也可以）  
vim ~/.bash_profile

    export LIBRARY_PATH=/usr/local/lib/:$LIBRARY_PATH
    export LD_LIBRARY_PATH=/usr/local/lib$LD_LIBRARY_PATH
    export PKG_CONFIG_PATH=/usr/local/lib/pkgconfig:$PKG_CONFIG_PATH
    export C_INCLUDE_PATH=/usr/local/include:$C_INCLUDE_PATH
    export CPLUS_INCLUDE_PATH=/usr/local/include:$CPLUS_INCLUDE_PATH