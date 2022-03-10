from sys import argv
import numpy as np

def flatten(lst):
    return [i for sublst in lst for i in sublst]
 
def faroShuffle(a, b):
    return flatten(zip(a, b))

def main():
    with open(argv[1], "r") as f:
        lns = f.readlines()
        lns = [s.replace("\n", "") for s in lns]

    Ts = []
    T = int(lns[0])

    for tc in range(T):
        N, K = tuple(map(int, lns[3 * tc + 1].split(" ")))
        antennas = list(list(map(int, lns[3 * tc + 2].split(" "))))
        buildings = list(list(map(int, lns[3 * tc + 3].split(" "))))

        antennas = sorted(antennas, key=abs)
        buildings = sorted(buildings, key=abs)

        maxA = antennas[-K:]
        maxB = buildings[-K:]
        
        minA = antennas[:K]
        minB = buildings[:K]

        maxA = sorted(maxA)
        maxB = sorted(maxB)
        minA = sorted(minA)
        minB = sorted(minB)

        maxA = faroShuffle(maxA[:int(K/2)], maxA[-int(K/2):])
        maxB = faroShuffle(maxB[:int(K/2)], maxB[-int(K/2):])
        
        minA = faroShuffle(minA[:int(K/2)], minA[-int(K/2):])
        minB = faroShuffle(minB[:int(K/2)], minB[-int(K/2):])
        minB = np.roll(minB, 1)

        # print("==="*5)
        # print(maxA)
        # print(maxB)
        # print("...")
        # print(minA)
        # print(minB)
        # print("==="*5)

        aMin = np.multiply(minA, minB)
        aMax = np.multiply(maxA, maxB)

        print(f"Case #{tc+1}: {sum(aMin)} {sum(aMax)}")


if __name__ == "__main__":
    main()
