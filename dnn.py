import pandas as pd
import tensorflow as tf

#data processing
df = pd.read_csv('C:/Users/maxba/OneDrive/桌面/imu data/v5 data(classified by num)/combined data v5.csv')
dataset = df.values
X = dataset[:,0:36]
Y = dataset[:,36]
from sklearn import preprocessing
min_max_scaler = preprocessing.MinMaxScaler() #normalize the data to 0-1
X_scale = min_max_scaler.fit_transform(X)
from sklearn.model_selection import train_test_split
X_train, X_test, Y_train, Y_test = train_test_split(X_scale, Y, test_size=0.3)

#validation set
#X_train, X_val_and_test, Y_train, Y_val_and_test = train_test_split(X_test, Y_test, test_size=0.3)
#X_val, X_test, Y_val, Y_test = train_test_split(X_val_and_test, Y_val_and_test, test_size=0.5)

#check data size
#print(X_train.shape, X_test.shape, Y_train.shape, Y_test.shape) 

#construct model
from keras.models import Sequential
from keras.layers import Dense
from keras.models import load_model
model = Sequential([    Dense(100, activation='relu', input_shape=(36,)),    Dense(100, activation='relu'),   Dense(100, activation='relu'),    Dense(5, activation='sigmoid'),])
model.compile(optimizer='adam',              loss='sparse_categorical_crossentropy',              metrics=['accuracy'])
model.fit(X_train, Y_train,          batch_size=32, epochs=100,          validation_data=None)

#test and save
accuracy = model.evaluate(X_test, Y_test)[1]
print("\nTest Accuracy: {0:f}\n".format(accuracy))
model.save('C:/Users/maxba/OneDrive/桌面/學士專題/DNN_model.h5')

#reference for the reloaded model
try_accuracy = model.evaluate(X_scale,Y)[1]
print("\nTry Accuracy: {0:f}\n".format(try_accuracy))

#predict data
#predictions = model.predict_classes(X_test)   
#print("predictions shape:", predictions)


#load model and predict new data
model1 = load_model('C:/Users/maxba/OneDrive/桌面/學士專題/DNN_model.h5')
model1.compile(optimizer='adam',              loss='sparse_categorical_crossentropy',              metrics=['accuracy'])
prediction_accuracy = model1.evaluate(X_scale,Y)[1]
print("\nPrediction Accuracy: {0:f}\n".format(prediction_accuracy))