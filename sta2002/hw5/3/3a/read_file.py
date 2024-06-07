# Read the .csv file
def read_csv(filename):
    with open(filename, 'r') as f:
        data = f.read().split('\n')[1:]  # Read from the 2nd line
        data = [line.split(',') for line in data if line]
        data = [[float(num) for num in line] for line in data]
    return list(zip(*data))  # Separate x, y to access each

