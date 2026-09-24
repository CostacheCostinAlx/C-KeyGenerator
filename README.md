# C Key Generator

A simple graphical application written in C using the **Raylib** and **Raygui** libraries to generate random keys and passwords.

## Project Structure

As seen in the workspace, the project contains:
- `main.c` - The main source code of the application.
- `raygui.h` - The header file for the graphical user interface.
- `raylib/` - The Raylib library folder included directly in the project.
- `build.sh` - A bash script for automated compilation.

## Prerequisites (Linux)

Since Raylib is included in the project folder, you only need the standard C build tools and the specific font used in the app.

You can install these by running:
```bash
sudo apt update
sudo apt install build-essential fonts-dejavu
```


## How to Compile

### 1. Download Raylib directly into the project folder
```bash
git clone [https://github.com/raysan5/raylib.git](https://github.com/raysan5/raylib.git)
```

### 2. Compile the Raylib static library
```bash
cd raylib/src
make PLATFORM=PLATFORM_DESKTOP
cd ../..
```
### 3. Make the build script executable and compile the app
```bash
chmod +x build.sh
./build.sh
```
## How to Run

After a successful compilation, you can start the key generator like this:
```bash
./keygen
```
