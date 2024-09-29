# Life
Let life play out as you walk away from your screens

# Install dependencies

You will have most of these already installed.
```
sudo pacman -Syu base-devel glibc libc++ libc++abi linux-api-headers freeglut mesa mesa-utils glu
```

Optional:
```
sudo pacman -Syu glibc-debug
```
# Build
```
mkdir build
cd build
cmake ..
cmake --build .
```
