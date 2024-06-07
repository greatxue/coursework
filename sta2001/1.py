"""
Problem: Throwing a fair 6-sided die
By definition, this is a random experiment and the sample space S = {1, 2, 3, 4, 5, 6}.
The task is to simulate this random experiment 5000 times by computer and check the relative frequency of the event
    A = {1, 2}. You should draw a figure to show the profile of the relative frequency of A as the random experiment is
    repeated from 1 to 5000 times.
"""
import random
import matplotlib.pyplot as plt


class Die:
    def __init__(self, sides=6):
        self.sides = sides
    
    def roll(self):
        return random.randint(1, self.sides)


class RollExperiment:
    def __init__(self, die):
        self.die = die
        self.relative_frequencies = []

    def simulate(self, num_experiment):
        event_count = 0
        for i in range(1, num_experiment + 1):
            outcome = self.die.roll()
            if outcome == 1 or outcome == 2:
                event_count += 1
            relative_frequency = event_count / i
            self.relative_frequencies.append(relative_frequency)

    def plot_relative_frequencies(self):
        num_experiment = len(self.relative_frequencies)

        x = range(1, num_experiment + 1)
        y = self.relative_frequencies
        plt.xlabel('Number of experiments')
        plt.ylabel('Relative frequency')

        plt.plot(x, y)
        plt.show()


# Create a six-sided die.
die = Die(6)

# Create an experiment and pass the "die" in.
experiment = RollExperiment(die)

# Simulate the rolling process.
experiment.simulate(5000)
experiment.plot_relative_frequencies()
