import sys
import math

def main():
    with open(sys.argv[1], "r") as f:
        lns = f.readlines()
        lns = [s.replace("\n", "") for s in lns]

    T = int(lns[0])
    lns = lns[1:]

    Ts = []

    for i in range(T):
        lns = lns[1:]

        nums = tuple(map(int, lns[0].split(" ")))    
        gcd = math.gcd(*nums)
        divisors = [n for n in range(1, gcd +1) if gcd % n == 0]

        print(f"Case #{i+1}: {len(divisors)}")

        lns = lns[1:]



if __name__ == "__main__":
    main()