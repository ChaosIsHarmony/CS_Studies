import pandas as pd
from sklearn.tree import DecisionTreeRegressor

data_file_path = 'melb_data.csv'
housing_data = pd.read_csv(data_file_path)

#drops data points with missing fields
housing_data.dropna(axis=0)

#y is the standard variable for prediction target
y = housing_data.Price
#X is the standard variable for the feature set
#housing_data.columns will display all columns in the data set
housing_features = ['Rooms', 'Bathroom', 'Landsize', 'Lattitude', 'Longtitude']
X = housing_data[housing_features]


#Steps to building a model [ref. https://www.kaggle.com/dansbecker/your-first-machine-learning-model]
#Define: What type of model will it be? A decision tree? Some other type of model? Some other parameters of the model type are specified too.
#Fit: Capture patterns from provided data. This is the heart of modeling.
#Predict: Just what it sounds like
#Evaluate: Determine how accurate the model's predictions are.

#Define model as decision tree
housing_model = DecisionTreeRegressor(random_state=1)

#Fit model
housing_model.fit(X, y)

#Predict (taken from first 5 items in data set, but would normal take from test set, not training set)
print((X.head))
print(housing_model.predict(X.head()))