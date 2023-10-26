"""
Problem:
An enterprising man proposes a game: let the player throw a fair six-sided die and then the player receives payment
    as follows:
    A = {1, 2, 3} -> 1 dollar
    B = {4, 5} -> 2 dollars
    C = {6} -> 3 dollars
The man charges the player 2 dollars for each play. What is the average payment the man needs to pay and can the man
    make profit if the game is repeated a large number of times?
The task is to simulate this random experiment 10000 times by computer and check the average payment.
You should draw a figure to show the profiles of the avg payment as the random experiment is repeated 10000 times.
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
        self.payments = []

    def sides_to_payment(self, side):
        sides_to_payment = {
            1: 1,
            2: 1,
            3: 1,
            4: 2,
            5: 2,
            6: 3
        }
        payment = sides_to_payment[side]
        return payment

    def simulate(self, num_experiment):
        payment_count = 0
        for crt_count in range(1, num_experiment + 1):
            side = self.die.roll()
            payment = self.sides_to_payment(side)
            payment_count += payment
            crt_count += 1
            payment_avg = payment_count / crt_count
            self.payments.append(payment_avg)

    def plot(self):
        num_experiment = len(self.payments)

        x = range(1, num_experiment + 1)
        y = self.payments
        plt.xlabel('Number of Experiments')
        plt.ylabel('Avg Payment')

        plt.plot(x, y)
        plt.show()


# Create a six-sided die.
die = Die(6)

# Create an experiment and pass the "die" in.
experiment = RollExperiment(die)

# Simulate the rolling process.
experiment.simulate(10000)
experiment.plot()