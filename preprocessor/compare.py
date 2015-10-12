"""
Takes a list of symbols and a list of declarations.
Returns the list of missing symbols and declarations.
"""

if __name__ == '__main__':
    import sys
    if len(sys.argv) < 3:
        raise Exception("Expected 2 filenames as input.")
    fn_symb = sys.argv[1]
    fn_decl = sys.argv[2]
    symb_lines = open(fn_symb, 'r').readlines()
    decl_lines = open(fn_decl, 'r').readlines()
    # search symbols in declarations
    for symb in symb_lines:
        symb = symb.strip()
        found = False
        for decl in decl_lines:
            if symb in decl:
                found = True
                break
        if not found:
            print symb
    # search declarations in symbols
    for decl in decl_lines:
        decl = decl.strip()
        found = False
        for symb in symb_lines:
            symb = symb.strip()
            if symb in decl:
                found = True
                break
        if not found:
            print decl 
