# Building RhoWebEngine

This guide explains how to build the `RhoWebEngine` project on both Linux and Windows using a Raspberry Pi as the development environment. It assumes you have all necessary dependencies installed and that you are familiar with basic command-line tools.

---

## Prerequisites

Before building the project, ensure you have the following tools installed on your system:

### General Prerequisites
- **CMake** (Version 3.10 or higher)
- **Ninja** (for fast building)
- **GCC/G++** (for compiling on Linux)
- **x86_64-w64-mingw32** (for cross-compiling on Windows)
- **pkg-config** (for finding packages on Linux)
- **SDL2** (for rendering)
- **libcurl** (for fetching)
- **libxml2** (for parsing HTML)

### Installing Dependencies on Raspberry Pi (Linux)
```bash
sudo apt-get update
sudo apt-get install cmake ninja-build pkg-config libsdl2-dev libcurl4-openssl-dev libxml2-dev
```

### Installing Cross-Compiling Tools for Windows
```bash
sudo apt-get install mingw-w64
```

---

## Building on Linux

### 1. Clone the Repository

First, clone the project repository:

```bash
git clone https://github.com/Komas19-new/Rho.git
cd Rho
```

### 2. Create a Build Directory

Create a new directory for building the project:

```bash
mkdir build
cd build
```

### 3. Configure with CMake

Run the following command to configure the project using CMake and Ninja:

```bash
cmake .. -G "Ninja"
```

This command will generate the necessary build files.

### 4. Build the Project

To build the project, use the `ninja` command:

```bash
ninja
```

Once the build process completes, you will have the `RhoWebEngine` executable in the build directory.

### 5. Running the Application

To run the application, execute:

```bash
./RhoWebEngine
```

---

## Cross-Compiling for Windows

Follow these steps to cross-compile `RhoWebEngine` for Windows on a Raspberry Pi.

### 1. Install Cross-Compiling Tools

Ensure that you have the `mingw-w64` toolchain installed (as mentioned in the prerequisites).

### 2. Configure with CMake

We will use a custom toolchain file for cross-compiling. The toolchain file is provided in the repository as `windows-toolchain.cmake`.

First, create a new build directory for the Windows build:

```bash
mkdir build-windows
cd build-windows
```

Next, configure the project using CMake with the toolchain file:

```bash
cmake .. -G "Ninja" -DCMAKE_TOOLCHAIN_FILE=../windows-toolchain.cmake
```

This will set up the cross-compiling environment.

### 3. Build for Windows

To build the project for Windows, run:

```bash
ninja
```

After the build completes, you will have a Windows `.exe` file in the `build-windows` directory.

### 4. Required DLLs for Windows

Make sure to include the following DLLs in the same directory as the `RhoWebEngine.exe` file before running the application on Windows:
- `SDL2.dll`
- `libcurl.dll`
- `libxml2.dll`

You can download precompiled versions of these libraries for Windows if they are not already available.

---

## Cleaning the Build Directory

If you need to clean up your build directory, simply delete the `build` or `build-windows` folder and recreate it following the steps above.

---

## Troubleshooting

### 1. Missing Libraries
Ensure all dependencies (SDL2, libcurl, libxml2) are installed and properly linked. If pkg-config fails to find the libraries, you might need to specify their paths manually in `CMakeLists.txt`.

### 2. CMake Fails to Configure
If CMake fails to configure the project, ensure that all necessary dependencies are installed and available for pkg-config.

### 3. Windows Executable Doesn't Run
Ensure that all required DLLs are in the same directory as the `.exe` file when running the application on Windows.

---

## License

This project is licensed under the GNU GPLv3 License.

---

## Contributing

We welcome contributions! Please submit pull requests or report issues on our GitHub repository.