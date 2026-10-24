#!/usr/bin/env python3
"""Writes the header field at 0x6C for a ROM built without the ARM7 BIOS.

dsd leaves the 16-bit header field at 0x6C as 0 when no ARM7 BIOS is given. This writes the base ROM's value
(--secure-area-crc) there and recomputes the header checksum at 0x15E.

Builds that pass the BIOS to dsd don't need this step.
"""
import argparse
from pathlib import Path

parser = argparse.ArgumentParser()
parser.add_argument("rom_in", type=Path)
parser.add_argument("rom_out", type=Path)
parser.add_argument("--secure-area-crc", type=lambda s: int(s, 0), required=True)
args = parser.parse_args()


def crc16(data: bytes) -> int:
    crc = 0xFFFF
    for b in data:
        crc ^= b
        for _ in range(8):
            crc = (crc >> 1) ^ 0xA001 if crc & 1 else crc >> 1
    return crc


rom = bytearray(args.rom_in.read_bytes())
rom[0x6C:0x6E] = args.secure_area_crc.to_bytes(2, "little")
rom[0x15E:0x160] = crc16(rom[:0x15E]).to_bytes(2, "little")
args.rom_out.write_bytes(rom)
