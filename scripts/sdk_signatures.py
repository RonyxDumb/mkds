"""Generate caller candidates using signatures of freshly byte-verified SDK C.

The caller is still accepted only after complete byte equality. No arguments
are invented, and calls requiring wider or aggregate ABI reasoning are skipped.
"""
import json
import re

def split_arguments(text):
    if text.strip() in ['', 'void']: return []
    parts = []; start = 0; depth = 0
    for i, c in enumerate(text):
        depth += (c in '([{') - (c in ')]}')
        if c == ',' and depth == 0: parts.append(text[start:i].strip()); start = i + 1
    parts.append(text[start:].strip())
    return parts

def abi_type(declaration, result=False):
    if declaration.strip() == 'void': return 'void'
    if '*' in declaration or '[' in declaration: return 'void *'
    if re.search(r'\b(?:float|double|u64|s64|fx64|fx64c|longlong|long\s+long)\b', declaration): return None
    if re.search(r'\b(?:struct|union)\b', declaration): return None
    return 'int' if re.search(r'\b(?:int|s32|fx32|BOOL)\b', declaration) else 'unsigned int'

def recover_sdk_calls(root, module, declarations, body):
    ledger = root / 'verification/sdk-source-proofs.json'
    if not ledger.exists(): return declarations, body, 0
    changed = 0
    for tag, proof in json.loads(ledger.read_text()).items():
        if not tag.startswith(module + '_'): continue
        address = tag[len(module)+1:]
        original = proof['bindings'][proof['donor_function']]
        if not re.search(r'\b' + re.escape(original) + r'\s*\(', body): continue
        source = root / 'src' / module / (address + '_' + original + '.c')
        text = source.read_text()
        signature = re.search(r'(?m)^([^\n;{}#]+?)\b' + re.escape(proof['donor_function']) + r'\s*\(([^;{}]*)\)\s*\{', text)
        if not signature: continue
        result = abi_type(signature.group(1), True)
        params = [abi_type(p) for p in split_arguments(signature.group(2))]
        if result is None or any(p is None for p in params): continue
        changes = []
        for match in re.finditer(r'\b' + re.escape(original) + r'\s*\(', body):
            start = match.end(); depth = 1; end = start
            while end < len(body) and depth:
                depth += (body[end] == '(') - (body[end] == ')'); end += 1
            if depth: continue
            arguments = split_arguments(body[start:end-1])
            if len(arguments) < len(params): continue
            # Do not discard side-effect expressions from a decompiler draft.
            if any(re.search(r'\b[A-Za-z_]\w*\s*\(', x) for x in arguments[len(params):]): continue
            if result == 'void':
                previous = body[:match.start()].rstrip()
                if previous and previous[-1] not in ';{}': continue
            arguments = arguments[:len(params)]
            rendered = [f'({typ})({arg})' for typ,arg in zip(params, arguments)]
            changes.append((start,end-1,','.join(rendered)))
        if not changes: continue
        declaration = re.compile(r'^[^#\n;{}]*\b' + re.escape(original) + r'\s*\([^;]*\);', re.M)
        if not declaration.search(declarations): continue
        declarations = declaration.sub('extern ' + result + ' ' + original + '(' + (','.join(params) or 'void') + ');', declarations)
        for start,end,replacement in reversed(changes): body = body[:start] + replacement + body[end:]
        changed += len(changes)
    return declarations, body, changed
