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

I have included a bash script to make compilation very easy.

1. Make sure the build script has execution permissions (you only need to do this once):
   ```bash
   chmod +x build.sh
   ```
2. Run the build script:
   ```bash
   ./build.sh
   ```

## How to Run

After a successful compilation, you can start the key generator like this:
```bash
./keygen
```