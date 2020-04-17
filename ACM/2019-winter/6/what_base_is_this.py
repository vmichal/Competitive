import sys



def find_min_base(number):
    radix = max(max(number), '1')
    return ord(radix)- ord('0')+1 if radix.isdigit() else ord(radix) - ord('A') +10+1;


def find_base(a, b):
    base_a = find_min_base(a)
    base_b = find_min_base(b)

    if a == b:
        return (base_a, base_b)

    while base_a <= 36 and base_b <= 36:
            val_a = int(a, base_a)
            val_b = int(b, base_b)

            if val_a == val_b:
                return (base_a, base_b)

            if val_a < val_b:
                base_a += 1
            else:
                base_b += 1
    return None

for line in sys.stdin:
    a, b = line.split()

    result = find_base(a, b)

    if result:
        print("%s (base %d) = %s (base %d)" % (a, result[0], b, result[1]))
    else:
        print("%s is not equal to %s in any base 2..36" % (a, b)) 
