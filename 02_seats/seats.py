import sys
import math

def main():
    with open(sys.argv[1], "r") as f:
        lns = f.readlines()
        lns = [s.replace("\n", "") for s in lns]

    T = int(lns[0])
    lns = lns[1:]

    Ts = []

    for tc in range(T):
        seatsN, days = map(int, lns[0].split(" "))
        lns = lns[1:]
        initial = [n for n in range(seatsN)]
        buffer = initial.copy()

        newSeats = list(map(int, lns[0].split(" ")))

        for _ in range(days):
            for j, newSeat in enumerate(newSeats):
                buffer[newSeat] = initial[j]
            initial = buffer
            buffer = initial.copy()
        lns = lns[1:]

        print(f"Case #{tc+1}:", " ".join(list(map(str, buffer))))


if __name__ == "__main__":
    main()