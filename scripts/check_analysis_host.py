#!/usr/bin/env python3
"""Check the Linux process identity prerequisite without weakening REA ownership."""
import argparse
import json
import os
from pathlib import Path
import subprocess


def inspect():
    pid = os.getpid()
    status = Path('/proc/self/status').read_text()
    proc_pid = int(next(line.split()[1] for line in status.splitlines() if line.startswith('Pid:')))
    result = {'runtime_pid': pid, 'proc_self_pid': proc_pid,
              'pid_namespace_consistent': pid == proc_pid,
              'ownership_checks_disabled': False}
    try:
        ps = subprocess.run(['ps', '-axo', 'pid=,ppid=,pgid=,uid=,stat=,command='],
                            capture_output=True, text=True, timeout=10)
        result['ps_exit_code'] = ps.returncode
        result['ps_stderr'] = ps.stderr.strip()
        result['ps_reports_current_process'] = any(
            line.split() and line.split()[0] == str(pid) for line in ps.stdout.splitlines())
    except (OSError, subprocess.TimeoutExpired) as error:
        result['ps_error'] = str(error)
        result['ps_reports_current_process'] = False
    result['rea_process_prerequisite_passed'] = (
        result['pid_namespace_consistent'] and result.get('ps_exit_code') == 0
        and result['ps_reports_current_process'])
    result['scope'] = 'Process prerequisite only; does not validate Ghidra installation or DS profile'
    if not result['rea_process_prerequisite_passed']:
        result['recovery'] = ('Run REA in a Linux host/container whose /proc belongs to the same '
                              'PID namespace as its processes, with procps installed. '
                              'Installing ps alone cannot repair a namespace mismatch.')
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--output', type=Path)
    args = parser.parse_args()
    result = inspect()
    text = json.dumps(result, indent=2) + '\n'
    if args.output:
        args.output.parent.mkdir(parents=True, exist_ok=True)
        args.output.write_text(text)
    print(text, end='')
    return 0 if result['rea_process_prerequisite_passed'] else 1


if __name__ == '__main__':
    raise SystemExit(main())
