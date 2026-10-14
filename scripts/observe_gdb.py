#!/usr/bin/env python3
"""Observe a stopped melonDS CPU through its local GDB remote protocol.

Queries stop status and registers only, then detaches. No memory/register
writes, breakpoints or arbitrary remote commands are exposed.
"""
import argparse
import json
import socket
from pathlib import Path


def packet(sock, command):
    raw = command.encode('ascii')
    sock.sendall(b'$' + raw + b'#' + f'{sum(raw) & 255:02x}'.encode('ascii'))
    while True:
        byte = sock.recv(1)
        if not byte:
            raise ConnectionError('Stub closed the connection')
        if byte == b'$':
            break
    payload = bytearray()
    while len(payload) <= 8192:
        byte = sock.recv(1)
        if not byte:
            raise ConnectionError('Truncated GDB response')
        if byte == b'#':
            break
        payload.extend(byte)
    else:
        raise ValueError('Oversized GDB response')
    checksum = bytearray()
    while len(checksum) < 2:
        byte = sock.recv(2 - len(checksum))
        if not byte:
            raise ConnectionError('Truncated GDB checksum')
        checksum.extend(byte)
    if int(checksum, 16) != sum(payload) & 255:
        raise ValueError('GDB checksum mismatch')
    sock.sendall(b'+')
    return payload.decode('ascii')


def observe(cpu, port):
    with socket.create_connection(('127.0.0.1', port), timeout=5) as sock:
        # melonDS requires an initial ack before the first command packet.
        sock.sendall(b'+')
        if sock.recv(1) != b'+':
            raise ValueError('Unexpected melonDS handshake')
        status = packet(sock, '?')
        raw = packet(sock, 'g')
        data = bytes.fromhex(raw)
        if len(data) < 17 * 4 or len(data) % 4:
            raise ValueError('Invalid melonDS register response')
        registers = [int.from_bytes(data[i:i + 4], 'little') for i in range(0, len(data), 4)]
        result = {'cpu': cpu, 'port': port, 'stop_reply': status,
                  'registers': registers, 'pc': registers[15],
                  'sp': registers[13], 'lr': registers[14], 'cpsr': registers[16],
                  'scope': 'One stopped CPU observation, not a matching proof'}
        result['detach_reply'] = packet(sock, 'D')
        if result['detach_reply'] != 'OK':
            raise ValueError('GDB detach did not succeed')
        return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--cpu', choices=('arm9', 'arm7'), required=True)
    parser.add_argument('--port', type=int)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    port = args.port or (3333 if args.cpu == 'arm9' else 3334)
    if not 1 <= port <= 65535:
        parser.error('Invalid TCP port')
    result = observe(args.cpu, port)
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps({k: result[k] for k in ('cpu', 'stop_reply', 'pc', 'cpsr', 'detach_reply')}))


if __name__ == '__main__':
    main()
