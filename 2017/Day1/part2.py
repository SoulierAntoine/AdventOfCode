import itertools

# Read file and store it in a string
with open('./input.txt', 'r') as f:
    data = f.readline()

# Get rid of newline character and convert each value to an int
data = [int(c.rstrip('\n')) for c in data]

result = 0

# Loop through half the list
for idx, val in enumerate(itertools.islice(data, 0, len(data) / 2)):
    if data[idx + (len(data) / 2)] == val:
        result += (val * 2)

print result
