"""
Extracts the list of functions from a C preprocessor output.
"""

def get_functions(lines):
    buf = []
    inside_function = False
    prefix = "extern __attribute__((dllexport)) "
    for line in lines:
        if not inside_function:
            inside_function = line.startswith(prefix)
            line = line.replace(prefix, "")
        if inside_function:
            line = line.strip()
            inside_function = not ';' in line
            if not inside_function:
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
    functions = get_functions(lines)
    for line in functions:
        sys.stdout.write(line)
