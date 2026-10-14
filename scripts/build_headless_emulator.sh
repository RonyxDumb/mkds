#!/bin/sh
# Build the pinned upstream core into ignored tools/, without Qt/SDL or JIT.
set -eu
cd "$(dirname "$0")/.."
# pip's user scripts directory need not be on PATH in hosted workspaces.
# Use the module entry point when the CMake wheel is installed there.
if command -v cmake >/dev/null 2>&1; then
    run_cmake() { cmake "$@"; }
elif python3 -m cmake --version >/dev/null 2>&1; then
    run_cmake() { python3 -m cmake "$@"; }
else
    echo "CMake missing: install CMake or run python3 -m pip install cmake" >&2
    exit 1
fi
for prerequisite in git c++ make; do
    if ! command -v "$prerequisite" >/dev/null 2>&1; then
        echo "Missing emulator build prerequisite: $prerequisite" >&2
        exit 1
    fi
done
emulator_commit=906e9ebb27da8c6a715cd7abab4abfe8a8d29427
emulator_source="$PWD/tools/melonds-source"
if [ ! -d "$emulator_source/.git" ]; then
    git clone https://github.com/melonDS-emu/melonDS.git "$emulator_source"
fi
git -C "$emulator_source" checkout --detach "$emulator_commit"
if [ -n "$(git -C "$emulator_source" status --porcelain)" ]; then
    echo "Refusing to build modified emulator sources" >&2
    exit 1
fi
run_cmake -S "$emulator_source" -B tools/melonds-headless-build \
    -DBUILD_QT_SDL=OFF -DENABLE_JIT=OFF -DENABLE_OGLRENDERER=OFF \
    -DENABLE_LTO_RELEASE=OFF -DENABLE_GDBSTUB=ON
run_cmake --build tools/melonds-headless-build -j4
c++ -std=c++17 -O2 -fwrapv -DGDBSTUB_ENABLED -I"$emulator_source/src" \
    scripts/melonds_headless.cpp tools/melonds-headless-build/src/libcore.a \
    tools/melonds-headless-build/src/teakra/src/libteakra.a -pthread -ldl -lrt \
    -o tools/melonds-headless
