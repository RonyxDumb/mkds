#!/usr/bin/env bash
# Builds wibo from upstream source at a pinned commit.
#
# Why: mwcc lays out switch statements by comparing a case density (count / range) against 0.4 in x87 floating
# point. A Windows process starts with 53-bit x87 precision; wibo 1.2.0 and earlier leave the Linux default of
# 64 bits, and a density of exactly 0.4 (12/30, 2/5) then misses the comparison, so a switch with that density
# compiles differently from the original.
# Upstream set the Windows default in commit e8f4795 ("Initialize guest floating-point state explicitly"), after the
# 1.2.0 release; other code compiles identically with either build. Switch back to a release download once one
# contains it.
#
# Needs CMake, Ninja, clang, lld and libclang (llvm 17+), plus Python 3 (the `libclang` bindings are installed into
# a private venv under build/).
#
# Usage: tools/build_wibo.sh [output_path]   (default: tools/bin/wibo)
set -euo pipefail

WIBO_COMMIT=420a75b7f80435824c3a633571277f90ae056119

root="$(cd "$(dirname "$0")/.." && pwd)"
out="${1:-$root/tools/bin/wibo}"
work="$root/build/wibo-src"
venv="$root/build/wibo-venv"

mkdir -p "$(dirname "$out")"

if [ ! -d "$work/.git" ]; then
    rm -rf "$work"
    git clone -q https://github.com/decompals/wibo "$work"
fi
git -C "$work" fetch -q origin "$WIBO_COMMIT"
git -C "$work" checkout -q "$WIBO_COMMIT"

if [ ! -x "$venv/bin/python3" ]; then
    python3 -m venv "$venv"
    "$venv/bin/pip" install -q libclang
fi

libclang="$(ls /usr/lib/llvm-*/lib/libclang-*.so.1 2>/dev/null | sort -V | tail -n 1 || true)"
cmake_args=(-DPython3_EXECUTABLE="$venv/bin/python3")
[ -n "$libclang" ] && cmake_args+=(-DLIBCLANG_LIBRARY="$libclang")

(cd "$work" && cmake --preset release64-clang "${cmake_args[@]}" > /dev/null && cmake --build --preset release64-clang > /dev/null)
# Replace by rename, so a wibo that is running right now keeps its old file.
cp "$work/build/release64-clang/wibo" "$out.new"
mv -f "$out.new" "$out"
"$out" --version
