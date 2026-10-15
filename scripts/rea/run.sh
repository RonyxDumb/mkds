#!/bin/sh
# Local read-only REA/Ghidra session for the tested hosted environment.
set -eu
root=$(CDPATH= cd -- "$(dirname -- "$0")/../.." && pwd)
export GHIDRA_INSTALL_DIR="${GHIDRA_INSTALL_DIR:-$root/tools/ghidra_12.1.4_PUBLIC}"
export JAVA_HOME="${JAVA_HOME:-$root/tools/jdk21/jdk-21.0.12.1+1}"
export REA_GHIDRA_TRANSPORT=authenticated-loopback-tcp
if [ ! -f "$root/tools/rea-source/dist/cli.js" ] || [ ! -x "$JAVA_HOME/bin/java" ]; then
    echo "Restore and build the pinned REA clone and JDK21; see reports/REA-PID-FIX.md" >&2
    exit 1
fi
exec node "$root/tools/rea-source/scripts/rea.mjs" "$@"
