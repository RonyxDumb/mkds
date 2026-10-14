#!/usr/bin/env python3
"""Compare every physical byte of a candidate NDS image, without masks.

Binary equality is independent of build provenance. A reference copy or a
hybrid image is never reported as a complete source reconstruction.
"""
import argparse
import hashlib
import json
import struct
from pathlib import Path

EXPECTED_SHA1 = 'ce97d9b43f0d3ca0d48b781983e8a16f6393378f'


def regions(data):
    if len(data) < 0x200:
        raise ValueError('Reference header truncated')
    result = []

    def add(name, offset, size):
        if offset < 0 or size < 0 or offset + size > len(data):
            raise ValueError('Reference region outside ROM: ' + name)
        if size:
            result.append((offset, offset + size, name))

    header_size = struct.unpack_from('<I', data, 0x84)[0]
    add('header', 0, max(0x200, header_size))
    for name, at in [('arm9', 0x20), ('arm7', 0x30)]:
        offset, _, _, size = struct.unpack_from('<4I', data, at)
        add(name, offset, size)
    for name, at in [('filename_table', 0x40), ('file_allocation_table', 0x48),
                     ('arm9_overlay_table', 0x50), ('arm7_overlay_table', 0x58)]:
        offset, size = struct.unpack_from('<2I', data, at)
        add(name, offset, size)
    banner = struct.unpack_from('<I', data, 0x68)[0]
    if banner:
        version = struct.unpack_from('<H', data, banner)[0]
        sizes = {1: 0x840, 2: 0x940, 3: 0xA40, 0x103: 0x23C0}
        if version not in sizes:
            raise ValueError('Unknown reference banner version')
        add('banner', banner, sizes[version])
    fat, fat_size = struct.unpack_from('<2I', data, 0x48)
    if fat_size % 8 or fat + fat_size > len(data):
        raise ValueError('Invalid reference FAT')
    overlay_files = {}
    for cpu, at in [('arm9', 0x50), ('arm7', 0x58)]:
        offset, size = struct.unpack_from('<2I', data, at)
        if size % 32 or offset + size > len(data):
            raise ValueError('Invalid reference overlay table')
        for i in range(offset, offset + size, 32):
            overlay_id = struct.unpack_from('<I', data, i)[0]
            file_id = struct.unpack_from('<I', data, i + 24)[0]
            overlay_files[file_id] = f'{cpu}_overlay_{overlay_id}'
    for file_id, at in enumerate(range(fat, fat + fat_size, 8)):
        start, end = struct.unpack_from('<2I', data, at)
        add(overlay_files.get(file_id, f'filesystem_file_{file_id}'), start, end - start)
    # Physical partition, including all gaps and trailing padding. Overlapping
    # ranges are named together but never counted twice.
    boundaries = sorted({0, len(data), *(x for a, b, _ in result for x in (a, b))})
    return [(a, b, '+'.join(name for start, end, name in result
                           if start <= a and b <= end) or 'padding_or_unclassified')
            for a, b in zip(boundaries, boundaries[1:])]


def compare(reference, candidate, provenance='unknown'):
    digest = hashlib.sha1(reference).hexdigest()
    if digest != EXPECTED_SHA1:
        raise ValueError('Wrong reference ROM SHA-1: ' + digest)
    partitions = regions(reference)
    details = []
    same = 0
    differences = []
    for start, end, name in partitions:
        original, rebuilt = reference[start:end], candidate[start:end]
        if original == rebuilt:
            equal = len(original)
        else:
            equal = 0
            for offset, expected in enumerate(original, start):
                actual = candidate[offset] if offset < len(candidate) else None
                if actual == expected:
                    equal += 1
                elif len(differences) < 64:
                    differences.append({'offset': f'0x{offset:08x}',
                                        'reference': expected, 'candidate': actual})
        same += equal
        details.append({'name': name, 'offset': start, 'size': end - start,
                        'equal_bytes': equal, 'different_or_missing_bytes': end - start - equal,
                        'reference_sha256': hashlib.sha256(original).hexdigest(),
                        'candidate_sha256': hashlib.sha256(rebuilt).hexdigest()})
    extra = max(0, len(candidate) - len(reference))
    exact = reference == candidate
    return {'scope': 'Every physical ROM byte; no header, relocation, asset or padding mask',
            'reference_sha1': digest, 'reference_sha256': hashlib.sha256(reference).hexdigest(),
            'candidate_sha1': hashlib.sha1(candidate).hexdigest(),
            'candidate_sha256': hashlib.sha256(candidate).hexdigest(),
            'reference_size': len(reference), 'candidate_size': len(candidate),
            'compared_extent': max(len(reference), len(candidate)),
            'equal_bytes': same, 'different_or_missing_bytes': len(reference) - same,
            'extra_candidate_bytes': extra, 'full_file_equal': exact,
            'candidate_provenance': provenance,
            'full_source_reconstruction_verified': False,
            'provenance_limitation': 'This comparator verifies file equality only, not how candidate bytes were built.',
            'first_differences': differences, 'regions': details}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('reference', type=Path)
    parser.add_argument('candidate', type=Path)
    parser.add_argument('--provenance', choices=('unknown', 'reference-roundtrip', 'hybrid', 'source-build'), default='unknown')
    parser.add_argument('--output', type=Path, default=Path('build/full-rom-comparison.json'))
    args = parser.parse_args()
    try:
        report = compare(args.reference.read_bytes(), args.candidate.read_bytes(), args.provenance)
    except (OSError, ValueError, struct.error) as error:
        parser.exit(2, str(error) + '\n')
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(report, indent=2) + '\n')
    print(json.dumps({key: report[key] for key in ('reference_size', 'candidate_size', 'equal_bytes',
                                                  'different_or_missing_bytes', 'extra_candidate_bytes',
                                                  'full_file_equal', 'candidate_provenance')}))
    return 0 if report['full_file_equal'] else 1


if __name__ == '__main__':
    raise SystemExit(main())
