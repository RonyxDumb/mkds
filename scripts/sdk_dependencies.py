"""Verify the SDK declarations used by source-level local matching proofs."""
from pathlib import Path
import hashlib
import json

def validate_sdk_headers(root):
    manifest = root / 'verification/sdk-header-manifest.json'
    if not (root / 'verification/sdk-source-proofs.json').exists():
        return
    expected = json.loads(manifest.read_text())
    actual = {str(p.relative_to(root)): hashlib.sha256(p.read_text().encode()).hexdigest()
              for p in sorted((root / 'vendor/pokediamond').rglob('*'))
              if p.is_file() and p.suffix in ['.h', '.inc', '.def']}
    assert actual == expected, 'SDK header dependencies differ from the verified checkpoint'
