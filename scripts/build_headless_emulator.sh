#!/bin/sh
# Build the pinned upstream core into ignored tools/, without Qt/SDL or JIT.
set -eu
cd "$(dirname "$0")/.."
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
cmake -S "$emulator_source" -B tools/melonds-headless-build \
    -DBUILD_QT_SDL=OFF -DENABLE_JIT=OFF -DENABLE_OGLRENDERER=OFF \
    -DENABLE_LTO_RELEASE=OFF -DENABLE_GDBSTUB=ON
cmake --build tools/melonds-headless-build -j4
c++ -std=c++17 -O2 -fwrapv -DGDBSTUB_ENABLED -I"$emulator_source/src" \
    scripts/melonds_headless.cpp tools/melonds-headless-build/src/libcore.a \
    tools/melonds-headless-build/src/teakra/src/libteakra.a -pthread -ldl -lrt \
    -o tools/melonds-headless
