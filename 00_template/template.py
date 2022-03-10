import sys

def solve_case(n):

    # TODO : Solve Test Case Here

    print(f"Case #{n+1}: ")

# Execs the File
def main():

    # Get Input File Name or Complain
    try: 
        FILE_NAME = sys.argv[1]
    except IndexError:
        print("Please Provide a File.")
        exit(1)

    # Backup stdout
    rstdot = sys.stdout
    # Prepare Output File
    outf  = open(FILE_NAME.replace("input", "output"), "w")
    # Replace stdout with input file
    sys.stdout = outf

    # Open input File
    with open(FILE_NAME, "r") as f:

        # Get the number of test cases
        TN = int(f.readline())

        # Solving Test Cases
        for tn in range(TN):

            # TODO : Interpret Input File Here and pass to `solve_case`
            
            solve_case(tn)
    
    # Reset stdout
    sys.stdout = rstdot
    # Close Input File
    outf.close()


if __name__ == "__main__":
    main()