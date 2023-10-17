import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        return

    # TODO: Read database file into a variable
    # Read database file into a list of dictionaries
    data =[]
    data_file = sys.argv[1]
    with open(data_file) as fp:
        data_reader = csv.DictReader(fp)
        data = [dict(row) for row in data_reader]
        list_info = [i for i in data[0]]
    #print(data)

    # TODO: Read DNA sequence file into a variable
    #sequence = ""
    sequence_file = sys.argv[2]
    with open(sequence_file) as fp:
        sequence = fp.read()
    # print(sequence)

    # TODO: Find longest match of each STR in DNA sequence

    #print(data[0].keys())
    check = [longest_match(sequence, subsequence) for subsequence in list_info][1:]

    # TODO: Check database for matching profiles

    is_dna = False
    for row in data:
        matches = [check[i - 1] == int(row[subsequence]) for i, subsequence in enumerate(row.keys()) if subsequence != "name"]
        if all(matches):
            print(row["name"])
            is_dna = True
            break
    if not is_dna:
        print("No match")

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
