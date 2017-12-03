# Read file and store it in a string
with open('./input.txt', 'r') as f:
    data = f.readline()

# Get rid of newline character and convert each value to an int
data = [int(c.rstrip('\n')) for c in data]

result = 0
prev = 0

for val in data:
    if val == prev:
        result += val
    prev = val

if data[0] == data[-1]:
    result += data[0]

print result
