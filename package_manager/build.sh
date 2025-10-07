#!/bin/bash
cd /home/sre/package_manager/vcpkg/build
rm -rf *
cmake -B /home/sre/package_manager/vcpkg/build -S /home/sre/package_manager/vcpkg -DCMAKE_TOOLCHAIN_FILE=/home/sre/package_manager/vcpkg/scripts/buildsystems/vcpkg.cmake -Wno-dev
cmake --build /home/sre/package_manager/vcpkg/build
