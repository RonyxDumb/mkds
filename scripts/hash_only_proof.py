"""Validate explicit hash-only evidence without distributing reference code bytes."""
import json


def validate_hash_only(root, module, address, inventory_size, proof):
    path = root / 'verification/hash-only-proofs.json'
    entries = json.loads(path.read_text()) if path.exists() else {}
    key = f'{module}_{address:08x}'
    evidence = entries.get(key)
    if evidence is None:
        raise ValueError('Missing archived bytes or explicit hash-only evidence: ' + key)
    assert evidence['size'] == int(proof['size'])
    assert evidence['size'] >= inventory_size
    for field in ['sha256', 'source_sha256']:
        assert evidence[field] == proof[field]
    audit = json.loads((root / 'verification' / evidence['audit']).read_text())
    if evidence['size'] != inventory_size:
        span = audit.get('span_checks', {}).get(key)
        assert span is not None and span['validator'] == 'proof_span.validate_span'
        assert span['inventory_size'] == evidence.get('inventory_size') == inventory_size
        assert span['span_size'] == evidence['size']
        assert span['sha256'] == evidence['sha256'] and span['validated'] is True
    assert any(r['module'] == module and int(r['address'], 16) == address
               and all(r[field] == proof[field] for field in ['sha256', 'source_sha256', 'size'])
               for r in audit['new_matches'])
    groups = [audit['fresh_audits'][name] for name in ['resolved', 'unrelocated']]
    assert all(isinstance(group['tested'], int) and group['tested'] >= 0
               and group['tested'] == group['passed'] for group in groups)
    assert sum(group['passed'] for group in groups) == audit['total_functions'] > 0
    assert audit['full_rom_link_verified'] is False
