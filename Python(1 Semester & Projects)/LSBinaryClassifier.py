import numpy as np
import matplotlib.pyplot as plt
plt.style.use('seaborn-whitegrid')
import pandas as pd
import random as rand


def k_fold_cross_validation(class_i,k_fold):
    #K-Fold Cross Validation and evaluation
    n = len(class_i)
    training_set = [[]for x in range(n)]
    testing_set = [[]for x in range(n)]
    #Every class has the same number of data, so you randomly pick class: 0
    initial_data = len(class_i[0])
    step = int(initial_data/k_fold)
    residual = initial_data - step*k_fold
    num_of_data = initial_data - residual

    for class_index in range(n):
        for start in range(0,num_of_data,step):
            testing_set[class_index].append(class_i[class_index][start:start+step])
            if(start == 0):
                training_set[class_index].append(class_i[class_index][start+step:num_of_data])
            else:
                training_set[class_index].append(class_i[class_index][0:start])
                training_set[class_index][-1]+=(class_i[class_index][start+step:num_of_data])
    return training_set,testing_set

# Correct and wrong answers for each fold
def calc_confusion_matrix(classes,testing_set,class_weights,fold):
    num_of_classes = len(testing_set)
    num_of_points_in_fold = len(testing_set[0][0])
    correct = 0
    wrong = 0
    for class_index in range(num_of_classes):
        for point in (testing_set[class_index][fold]):
            result = score_set(class_weights,fold,point)
            if(result == class_index):
                correct += 1
            else:
                wrong += 1
    return [correct,wrong]

#Predicts in which class a point is classified
def score_set(w,fold,point):
    scores = []
    num_of_classes = len(class_weights)
    num_of_x = len(point)
    #input(num_of_weights)
    for class_index in range(num_of_classes):
        b = w[class_index][fold][0]
        h = 0
        for i in range(num_of_x):
            h += w[class_index][fold][i+1]*point[i]
        h += b
        score = (1-h)**2 #y-y_predicted
        scores.append(score)
    class_classified_to = scores.index(max(scores))
    return class_classified_to


def observedValue(Y,class_index,sets):
    start = class_index*sets
    stop = class_index*sets + sets
    for i in range(len(Y)):
        Y[i] = 1
    for i in range(start,stop):
        Y[i] *= -1
    return Y


#Features get a discrete value of 1 or -1
features_y = []
#To store all the data, for each class and each class's color for plotting. We have n classes
n = 3
class_i = [[]for x in range(n)]
color = ["blue","orange","green"]
#Data points m for each class
m = 100
#Storing weights for each class, for each training set
class_weights = [[]for x in range(n)]
#For confusion matrix, evaluating each k - fold corss validation
evaluate_set = []



#Points for feature A
for i in range(m):
    x1 = rand.randint(20,60)
    x2 = rand.randint(20,60)
    class_i[0].append([x1,x2])
    features_y.append(1)

#Points for feature B
for i in range(m):
    x1 = rand.randint(60,100)
    x2 = rand.randint(80,120)
    class_i[1].append([x1,x2])
    features_y.append(-1)

#Points for feature C
for i in range(m):
    x1 = rand.randint(100,140)
    x2 = rand.randint(20,60)
    class_i[2].append([x1,x2])
    features_y.append(-1)

for i in range(int(m/4)):
    for j in range(3):
        x1 = rand.randint(20,140)
        x2 = rand.randint(20,120)
        pos = rand.randint(0,m-1)
        class_i[j][pos] = [x1,x2]


#Getting out training and testing set, divided by K for cross validation
k = 10
training_set,testing_set = k_fold_cross_validation(class_i,k)
#training_points is the number of training sets for each class. training_points = all_points - testing_points.
#Every class has same num of training points, so we pick randomly, say class 0 training set 0
m = m - m%k
training_points = len(training_set[0][0])
#input(training_points)
testing_points = len(testing_set[0][0])
#input(testing_points)
#Setting y vector
y = np.concatenate((features_y[0*m:0*m+m-testing_points],features_y[(0+1)*m:(0+1)*m+m-testing_points])).T
for i in range(1,n-1):
    y = np.concatenate((y,features_y[(i+1)*m:(i+1)*m+m-testing_points])).T

#y = np.concatenate((features_y[:90], features_y[100:190])).T
#y = np.concatenate((y, features_y[210:])).T


                                            #TRAINING PHASE

#k = num of folds, n = num of classes
for i in range(k):
    for class_index in range(n):
        for point in range(training_points):
            plt.scatter(training_set[class_index][i][point][0],training_set[class_index][i][point][1],color = color[class_index])
    X = np.vstack((training_set[0][i],training_set[1][i]))
    X = np.vstack((X,training_set[2][i]))
    m = len(X)
    X = np.array([np.ones(m), X[:, 0], X[:, 1]]).T
    #Calculate weights for each class ,for each training set(k)
    #Linear Equation for solving this problem is computed by W = ((XTX)^−1)XTy
    for class_index in range(n):
        y = observedValue(y,class_index,training_points)
        w_i = np.linalg.inv(X.T @ X) @ (X.T @ y)
        class_weights[class_index].append(w_i)


                                            #TESTING PHASE

#testing_points = number of points to test
#Every class has the same number of testing point, so we pick one randomly, say class 0 testing set 0

#Calculating confusion matrix for each training set
confusion_matrix = []

for fold in range(len(testing_set[0])):
    results = calc_confusion_matrix(class_i,testing_set,class_weights,fold)
    confusion_matrix.append(results)

print(confusion_matrix)

for i in range(len(confusion_matrix)):
    if(confusion_matrix[i][0] == 0):
        evaluate_set.append(0)
    else:
        evaluate_set.append(confusion_matrix[i][0]/testing_points) #confusion_matrix[i][0] number of correct guesses for class all classes in data set i

#To store the weights of the classes which had the best evaluated set( if many sets scored equally, we get the first one)
winning_weights = []

#Index of the highest scored set
best_set = evaluate_set.index(max(evaluate_set))
for i in range(n):
    winning_weights.append(class_weights[i][best_set])


print("The best weights came from the set: ",best_set)


#Plotting classes and decision boarders
line_x = np.linspace(0,140)
class_index = 0
for class_i in winning_weights:
    class_index += 1
    line_y = -class_i[0] / class_i[2] - (class_i[1] / class_i[2]) * line_x
    plt.plot(line_x,line_y,label = 'Class ' + str(class_index))

plt.title('Training set selected : '+str(best_set))
plt.legend()

plt.show()
