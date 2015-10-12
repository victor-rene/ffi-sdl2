"""
Extracts typedefs, enums and exported functions from a C preprocessor output.
"""

# Can be improved to work in a single pass by writing
# a stateful component working line by line
# Another improvement is to implement a switch to select
# what to extract and/or group results by category
def get_symbols(lines):
    buf = []
    inside = False
    count = 0
    export = "extern __attribute__((dllexport)) "
    for line in lines:
        if not inside:
            if line.startswith(export):
                inside = True
                line = line.replace(export, "")
            else:
                inside = "typedef" in line or "enum" in line
        if inside:
            count += line.count('{') - line.count('}');
            line = line.strip() + " "
            inside = (count > 0) or (not ';' in line)
            if not inside:
                line += '\n'
            buf.append(line)
    return buf

if __name__ == '__main__':
    # input
    import sys
    f = None
    if len(sys.argv) < 2:
        f = sys.stdin
    else:
        f = open(sys.argv[1], 'r')
    lines = f.readlines()
    f.close()
    # process and output
    symbols = get_symbols(lines)
    for line in symbols:
        sys.stdout.write(line)
