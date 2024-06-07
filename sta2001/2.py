"""
Problem:
There are three bowls and the random experiment is to select a bowl first, and then draw a chip from the selected
    bowl. Assume that the probabilities to select each bowl are
    P(B1) = 1/3, P(B2) = 1/6, P(B3) = 1/2.
For each selected bowl, all chips in the bowl are “equally likely”.
    Red: 2  White: 4       Red: 1  White: 2         Red: 5  White: 4
        B1                     B2                        B3
* Let R={draw a red chip}. We know from the lecture that P (R) = 4/9 .
* Suppose now that the outcome of the experiment is a red chip, but we don't know from which bowl the chip was drawn.
 We know from the lecture that   P(B1|R) = 1/4, P(B2|R) = 1/8, P(B3|R) = 5/8.
The task is to simulate this random experiment 100000 times by computer and check the relative frequencies of the
    event R and the event Bi|R, i = 1, 2, 3.
You should draw a figure to show the profiles of the relative frequency of R and Bi|R, i = 1, 2, 3 as the random
    experiment is repeated from 1 to 100000 times.
"""
import random
import matplotlib.pyplot as plt


class Bowl:
    def __init__(self, red, white):
        self.red = red
        self.white = white
        self.balls = []

    def arg(self):
        for _ in range(self.red):
            self.balls.append(0)
        for _ in range(self.white):
            self.balls.append(1)
        return self.balls


B1, B2, B3 = Bowl(2, 4).arg(), Bowl(1, 2).arg(), Bowl(5, 4).arg()
bowls = [B1, B2, B3]
weights = [1/3, 1/6, 1/2]

class PickBallExperiment:
    def __init__(self, bowls, weights):
        self.bowls = bowls
        self.weights = weights

    def pick_bowl(self):
        picked_bowl_ = random.choices(self.bowls, self.weights)
        picked_bowl = picked_bowl_[0]
        return picked_bowl

    def pick_ball(self, picked_bowl):
        index = random.randint(0, len(picked_bowl)-1)
        picked_ball = picked_bowl[index]
        return picked_ball

    def simulate(self, num_experiment):
        event_count = 0
        B1_count = 0
        frequencies = []
        for _ in range(1, num_experiment + 1):
            picked_bowl = self.pick_bowl()
            picked_ball = self.pick_ball(picked_bowl)
            if picked_ball == 0:
                event_count += 1
                if picked_bowl == self.bowls[0]:
                    B1_count += 1
            if event_count > 0:
                frequency = B1_count / event_count
                # print(frequency)
                frequencies.append(frequency)
        return frequencies
    
    def plot(self):
        y = self.simulate(100000)

        num_experiment = len(y)
        x = range(1, num_experiment + 1)
        
        plt.xlabel('Number of experiments')
        plt.ylabel('Conditonal frequency')

        plt.plot(x, y)
        plt.show()


experiment = PickBallExperiment(bowls, weights)
experiment.plot()