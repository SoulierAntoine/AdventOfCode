# Read file and store it in a string
with open('./input.txt', 'r') as f:
    data = f.readline()

# Get rid of newline character and convert each value to an int
data = [int(c.rstrip('\n')) for c in data]

result = 0

for idx, val in enumerate(data):
    if idx < (len(data) - 1) and data[idx + 1] == val:
        result += (val * 2)

if data[-1] == data[0]:
    result += data[-1]

print result
