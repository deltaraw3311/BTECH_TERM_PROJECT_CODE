import pandas as pd
from sklearn.linear_model import LinearRegression
from sklearn.model_selection import train_test_split
from sklearn.metrics import r2_score

# Load the dataset
df = pd.read_csv('Downloads/Btpdata1.csv')

# Split the dataset into training and testing sets
X = df[['friction', 'bearing_capacity', 'angle_of_friction', 'slope_backfill', 'unit_weight', 'height', 'surcharge_pressure', 'soil_wall_interface_friction','concrete_density']]
y = df['Volume']
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=0)

# Fit the model to the training data
model = LinearRegression()
model.fit(X_train, y_train)

# Make predictions on the testing data
y_pred = model.predict(X_test)

# Evaluate the model's performance
r2 = r2_score(y_test, y_pred)
print('R2 value is : ')
print(f"R^2 score: {r2}")
x_train = pd.DataFrame([[0.3,144,35,25,19,5,25,27,24]], columns=X.columns)
y_pred = model.predict(x_train)
y_pred
