#-------------------------------------------------------#
# 指定cmake版本
cmake_minimum_required(VERSION 2.8.12)
# 设置工程--opencv-develop
project(opencv-develop)
# 添加c++11标准
add_definitions(-std=c++11)

#-------------------------------------------------------#
# 针对Qt--自动使用moc、uic、rcc程序预处理.h文件、ui文件等
# set(CMAKE_AUTOUIC ON)
# set(CMAKE_AUTOMOC ON)
# set(CMAKE_AUTORCC ON)

#---------Libraries-OpenCV、Qt5、MVS、Threads-----------#
# Opencv
# IF (CMAKE_SYSTEM_NAME MATCHES "Windows")
# 	set(OpenCV_DIR E:/Opencv4.5.5/opencv/build/x64/vc15/lib)  
# ENDIF()
# find_package(OpenCV 4.5.5  REQUIRED)
# include_directories(${OpenCV_INCLUDE_DIRS})
# Threads for window
# set(THREADS_PREFER_PTHREAD_FLAG ON)
# find_package(Threads REQUIRED)

# QT5
#find_package(Qt5SerialPort REQUIRED)
#find_package(Qt5Core REQUIRED)
#find_package(Qt5Widgets REQUIRED)
#find_package(Qt5 COMPONENTS Widgets Core Gui Network REQUIRED)

# MVS for linux
# find_library(CAMERA_LIB libMvCameraControl.so libMvCameraControl.so.3.2.1.0 /opt/MVS/lib/64/)
# find_path(MVS_PATH CameraParams.h MvCameraControl.h MvErrorDefine.h PixelType.h /opt/MVS/include/)
# include_directories(${MVS_PATH})

# MVS for windows
# IF (CMAKE_SYSTEM_NAME MATCHES "Windows")
# 	find_library(CAMERA_LIB MvCameraControl.lib E:\MVS\MVS\Development\Libraries\win64\)
# 	find_path(MVS_PATH MvCameraControl.h  E:\MVS\MVS\Development\include\)
# 	include_directories(${MVS_PATH})
# ENDIF()

#--------------------Include----------------------------#
include_directories(include)

#--------------------Source-----------------------------#
aux_source_directory(src DIR_SRCS)
# 指定最终生成的可执行文件的路径

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
add_executable(21RM ${DIR_SRCS})

# IF (CMAKE_SYSTEM_NAME MATCHES "Windows")
# 	SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
# 	add_executable(21RM.exe ${DIR_SRCS})
# ENDIF()


#------将库文件链接到可执行程序上(写在add_executable后)------#
# target_link_libraries(21RM Threads::Threads)
# target_link_libraries(21RM ${OpenCV_LIBS})
#target_link_libraries(21RM Qt5::Core)
#target_link_libraries(21RM Qt5::Widgets)
#target_link_libraries(21RM Qt5::SerialPort)
# target_link_libraries(21RM ${CAMERA_LIB})
#-------------------------------------------------------#

