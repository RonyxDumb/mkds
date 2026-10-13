"""Lift Ghidra's ARM word-read expansion back to a native 32-bit C load.

These are candidate transformations, never matching evidence by themselves.
The original compiler and complete function-byte comparison must validate them.
"""
import re

def parenthesized(text, position):
    while position < len(text) and text[position].isspace(): position += 1
    if position >= len(text) or text[position] != '(': return None
    opening = position; depth = 1; position += 1
    while position < len(text) and depth:
        depth += (text[position] == '(') - (text[position] == ')'); position += 1
    if depth: return None
    return text[opening+1:position-1], position

def normalized(expression):
    return re.sub(r'\s+', '', expression)

def word_read(text, position):
    match = re.match(r'\*\s*\(\s*uint\s*\*\s*\)', text[position:])
    if not match: return None
    address = parenthesized(text, position + match.end())
    if not address: return None
    expression, end = address
    masked = re.fullmatch(r'(.*?)\s*&\s*0xfffffffc[Uu]?\s*', expression, flags=re.S)
    if not masked: return None
    return masked.group(1).strip(), end

def simplify_word_reads(text):
    replacements = []; occupied = 0
    for match in re.finditer(r'\*\s*\(\s*uint\s*\*\s*\)', text):
        start = match.start()
        if start < occupied: continue
        first = word_read(text, start)
        if first is None: continue
        address, end = first
        whole_end = None
        right = re.match(r'\s*>>\s*', text[end:])
        if right:
            rotation = parenthesized(text, end + right.end())
            if rotation and normalized(rotation[0]) == normalized(address) + '&3':
                separator = re.match(r'\s*\*\s*8\s*\|\s*', text[rotation[1]:])
                if separator:
                    second = word_read(text, rotation[1] + separator.end())
                    if second and normalized(second[0]) == normalized(address):
                        left = re.match(r'\s*<<\s*', text[second[1]:])
                        shift = parenthesized(text, second[1] + left.end()) if left else None
                        if shift and normalized(shift[0]) == normalized(address) + '&3':
                            suffix = re.match(r'\s*\*\s*-8\s*\+\s*(?:0x20|32)[Uu]?', text[shift[1]:])
                            if suffix: whole_end = shift[1] + suffix.end()
        # A plain masked read is also only a candidate; equality is checked later.
        finish = whole_end if whole_end is not None else end
        replacements.append((start, finish, '*(uint *)(' + address + ')'))
        occupied = finish
    for start, end, replacement in reversed(replacements):
        text = text[:start] + replacement + text[end:]
    return text, len(replacements)
