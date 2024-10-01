use msys2
pacman -S mingw-w64-x86_64-libxml2 mingw-w64-x86_64-curl mingw-w64-x86_64-SDL2 mingw-w64-x86_64-cmake mingw-w64-x86_64-ninja


mkdir build
cd build

cmake .. -G "Ninja"

ninja

copy the brand new RhoWebEngine.exe into the dist directory, containing all dlls required.

./RhoWebEngine.exe

