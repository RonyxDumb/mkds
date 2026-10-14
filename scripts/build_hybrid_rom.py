#!/usr/bin/env python3
"""Insert audited compiled function objects into reference-derived modules.

This is a hybrid integration check, never a complete C source build.
Reference-derived unverified code, data and assets are explicitly retained.
Run both fresh compilation audits first. ROM output stays in ignored build/.
"""
import argparse
import csv
import hashlib
import io
import json
from pathlib import Path
import ndspy.rom
import ndspy.code
import ndspy.codeCompression
from elftools.elf.elffile import ELFFile
from compare_rom import compare, EXPECTED_SHA1

ROOT = Path(__file__).resolve().parents[1]


def build(rompath, output):
    reference = rompath.read_bytes()
    if hashlib.sha1(reference).hexdigest() != EXPECTED_SHA1:
        raise ValueError('Wrong reference ROM')
    groups = {}
    for key, filename, audit in [
        ('unrelocated', 'local-byte-exact.tsv', 'matching-audit.json'),
        ('resolved', 'local-linked-byte-exact.tsv', 'linked-matching-audit.json'),
    ]:
        groups[key] = list(csv.DictReader((ROOT / 'verification' / filename).open(), delimiter='\t'))
        result = json.loads((ROOT / 'verification' / audit).read_text())
        if result['tested'] != result['passed'] or result['passed'] != len(groups[key]):
            raise ValueError('Compilation audit incomplete: ' + key)
    # The same relocation resolver as the independent audit, now importable
    # without executing its compilation loop. All bytes are checked again.
    import audit_resolved_calls as resolver
    rom = ndspy.rom.NintendoDSRom(reference)
    cpu_modules = {'arm9': rom.loadArm9(), 'arm7': rom.loadArm7()}
    overlays = {'arm9': rom.loadArm9Overlays(), 'arm7': rom.loadArm7Overlays()}
    modules = {name: [(section.ramAddress, section.data) for section in module.sections]
               for name, module in cpu_modules.items()}
    for cpu, entries in overlays.items():
        for oid, overlay in entries.items():
            modules[f'{cpu}_ov{oid:03}'] = [(overlay.ramAddress, overlay.data)]
    buffers = {name: [(base, bytearray(data), bytearray(len(data))) for base, data in sections]
               for name, sections in modules.items()}
    records = []
    for group, rows in groups.items():
        for row in rows:
            addr, size, module = int(row['address'], 16), int(row['size']), row['module']
            tag = f'{module}_{addr:08x}'
            source = ROOT / 'src' / module / f"{addr:08x}_{row['name']}.c"
            if hashlib.sha256(source.read_bytes()).hexdigest() != row['source_sha256']:
                raise ValueError('Source changed since audit: ' + tag)
            obj = ROOT / ('verification/mw-objects' if group == 'unrelocated' else 'build/linked-audit-objects') / (tag + '.o')
            data = obj.read_bytes()
            if group == 'resolved':
                code, relocations = resolver.linked(data, module, row['name'], addr)
                if len(relocations) != int(row['relocations']):
                    raise ValueError('Relocation count mismatch: ' + tag)
            else:
                elf = ELFFile(io.BytesIO(data))
                symbol = next(s for s in elf.get_section_by_name('.symtab').iter_symbols() if s.name == row['name'])
                index, start = symbol['st_shndx'], symbol['st_value'] & ~1
                code = elf.get_section(index).data()[start:start + symbol['st_size']]
                if any(start <= r['r_offset'] < start + size
                       for sec in elf.iter_sections() if sec['sh_type'] in ('SHT_REL', 'SHT_RELA') and sec['sh_info'] == index
                       for r in sec.iter_relocations()):
                    raise ValueError('Unexpected unresolved relocation: ' + tag)
            if len(code) != size or hashlib.sha256(code).hexdigest() != row['sha256']:
                raise ValueError('Compiled body mismatch: ' + tag)
            for base, buffer, coverage in buffers[module]:
                if base <= addr and addr + size <= base + len(buffer):
                    offset = addr - base
                    if buffer[offset:offset + size] != code:
                        raise ValueError('Compiled bytes differ from reference module: ' + tag)
                    buffer[offset:offset + size] = code
                    coverage[offset:offset + size] = b'\x01' * size
                    break
            else:
                raise ValueError('Compiled body outside module: ' + tag)
            records.append({'module': module, 'address': row['address'], 'size': size,
                            'source_sha256': row['source_sha256'], 'code_sha256': row['sha256'],
                            'object_sha256': hashlib.sha256(data).hexdigest()})
    output.mkdir(parents=True, exist_ok=True)
    for name, module in cpu_modules.items():
        for section, (_, buffer, _) in zip(module.sections, buffers[name]):
            section.data = buffer
        # Preserve reference compression state where identifiable. This does
        # not guarantee the original compressor's byte stream or file layout.
        compressed = False
        if module.codeSettingsOffs is not None:
            raw = ndspy.codeCompression.decompress(getattr(rom, name))
            compressed = len(raw) != len(getattr(rom, name))
        setattr(rom, name, module.save(compress=compressed))
    for cpu, entries in overlays.items():
        for oid, overlay in entries.items():
            overlay.data = buffers[f'{cpu}_ov{oid:03}'][0][1]
            rom.files[overlay.fileID] = overlay.save(compress=overlay.compressed)
        setattr(rom, cpu + 'OverlayTable', ndspy.code.saveOverlayTable(entries))
    candidate = rom.save()
    reloaded = ndspy.rom.NintendoDSRom(candidate)
    reloaded_modules = {}
    for cpu in ('arm9', 'arm7'):
        maincode = reloaded.loadArm9() if cpu == 'arm9' else reloaded.loadArm7()
        reloaded_modules[cpu] = [(section.ramAddress, section.data) for section in maincode.sections]
        overlay_entries = reloaded.loadArm9Overlays() if cpu == 'arm9' else reloaded.loadArm7Overlays()
        for oid, overlay in overlay_entries.items():
            reloaded_modules[f'{cpu}_ov{oid:03}'] = [(overlay.ramAddress, overlay.data)]
    if reloaded_modules != modules:
        raise ValueError('Serialized hybrid changes decompressed module bytes or addresses')
    (output / 'hybrid.nds').write_bytes(candidate)
    comparison = compare(reference, candidate, 'hybrid')
    (output / 'comparison.json').write_text(json.dumps(comparison, indent=2) + '\n')
    provenance = {
        'scope': 'Compiled local functions integrated into reference-derived modules',
        'compiled_functions': len(records),
        'compiled_span_bytes_sum': sum(r['size'] for r in records),
        'unique_compiled_span_bytes': sum(sum(coverage) for sections in buffers.values() for _, _, coverage in sections),
        'reference_derived_unverified_code_data_and_assets_retained': True,
        'full_source_reconstruction_verified': False,
        'full_rom_link_verified': False,
        'all_decompressed_modules_equal_to_reference': True,
        'modules': [{'module': name, 'initialized_bytes': sum(len(b) for _, b, _ in sections),
                     'unique_compiled_span_bytes': sum(sum(c) for _, _, c in sections)}
                    for name, sections in buffers.items()],
        'objects': records,
    }
    (output / 'provenance.json').write_text(json.dumps(provenance, indent=2) + '\n')
    print(json.dumps({k: provenance[k] for k in ('compiled_functions', 'unique_compiled_span_bytes', 'full_source_reconstruction_verified')}))
    print(json.dumps({k: comparison[k] for k in ('candidate_size', 'equal_bytes', 'different_or_missing_bytes', 'full_file_equal')}))


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('rom', type=Path)
    parser.add_argument('--output', type=Path, default=ROOT / 'build/hybrid')
    args = parser.parse_args()
    build(args.rom, args.output)


if __name__ == '__main__':
    main()
