# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Espressif/frameworks/esp-idf-v5.2.2/components/bootloader/subproject"
  "C:/chatgpt/esp-box/examples/chatgpt_demo/factory_nvs/build/bootloader"
  "C:/chatgpt/esp-box/examples/chatgpt_demo/factory_nvs/build/bootloader-prefix"
  "C:/chatgpt/esp-box/examples/chatgpt_demo/factory_nvs/build/bootloader-prefix/tmp"
  "C:/chatgpt/esp-box/examples/chatgpt_demo/factory_nvs/build/bootloader-prefix/src/bootloader-stamp"
  "C:/chatgpt/esp-box/examples/chatgpt_demo/factory_nvs/build/bootloader-prefix/src"
  "C:/chatgpt/esp-box/examples/chatgpt_demo/factory_nvs/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/chatgpt/esp-box/examples/chatgpt_demo/factory_nvs/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/chatgpt/esp-box/examples/chatgpt_demo/factory_nvs/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
