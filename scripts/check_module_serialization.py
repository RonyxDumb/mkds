#!/usr/bin/env python3
"""Isolate hybrid serialization changes without substituting any compiled code."""
import argparse
import hashlib
import json
from pathlib import Path
import ndspy.rom
import ndspy.code
import ndspy.codeCompression
from compare_rom import EXPECTED_SHA1


def check(reference, candidate):
    if hashlib.sha1(reference).hexdigest() != EXPECTED_SHA1:
        raise ValueError('Wrong reference ROM')
    rom = ndspy.rom.NintendoDSRom(reference)
    for cpu in ('arm9', 'arm7'):
        module = rom.loadArm9() if cpu == 'arm9' else rom.loadArm7()
        raw = getattr(rom, cpu)
        compressed = (module.codeSettingsOffs is not None
                      and len(ndspy.codeCompression.decompress(raw)) != len(raw))
        setattr(rom, cpu, module.save(compress=compressed))
        overlays = rom.loadArm9Overlays() if cpu == 'arm9' else rom.loadArm7Overlays()
        for overlay in overlays.values():
            rom.files[overlay.fileID] = overlay.save(compress=overlay.compressed)
        setattr(rom, cpu + 'OverlayTable', ndspy.code.saveOverlayTable(overlays))
    control = rom.save()
    return {'recompiled_functions_inserted': 0,
            'identical_complete_file_to_candidate': control == candidate,
            'control_sha256': hashlib.sha256(control).hexdigest(),
            'candidate_sha256': hashlib.sha256(candidate).hexdigest(),
            'control_size': len(control), 'candidate_size': len(candidate),
            'full_source_reconstruction_verified': False,
            'scope': 'No-code-substitution module serialization control; not a decompilation build'}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('reference', type=Path)
    parser.add_argument('candidate', type=Path)
    parser.add_argument('--output', type=Path)
    args = parser.parse_args()
    result = check(args.reference.read_bytes(), args.candidate.read_bytes())
    text = json.dumps(result, indent=2) + '\n'
    if args.output:
        args.output.parent.mkdir(parents=True, exist_ok=True)
        args.output.write_text(text)
    print(text, end='')
    return 0 if result['identical_complete_file_to_candidate'] else 1


if __name__ == '__main__':
    raise SystemExit(main())
