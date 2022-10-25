import csv
import matplotlib.pyplot as plt

x = []
y = []
with open('points.csv', newline='') as csvfile:
	spamreader = csv.reader(csvfile, delimiter=',', quotechar='|')
	for row in spamreader:
		x.append(float(row[0]))
		y.append(float(row[1]))


x1 = []
y1 = []
with open('pointsCon.csv', newline='') as csvfile:
	spamreader = csv.reader(csvfile, delimiter=',', quotechar='|')
	for row in spamreader:
		x1.append(float(row[0]))
		y1.append(float(row[1]))

x1.append(x1[0])
y1.append(y1[0])

x2 = []
y2 = []
with open('sortedPoints.csv', newline='') as csvfile:
	spamreader = csv.reader(csvfile, delimiter=',', quotechar='|')
	for row in spamreader:
		x2.append(float(row[0]))
		y2.append(float(row[1]))



plt.scatter(x, y, marker='o', color = 'r')
# plt.plot(x2,y2, label='Polar angle points line')
plt.plot(x1,y1, label='Convex hull')
plt.legend()
plt.savefig(f'plot_{len(x)}.png')
plt.show()