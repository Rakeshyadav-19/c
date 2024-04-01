# How to clean data using pandas

import pandas as pd
import numpy as np
import seaborn as sns #heatmap

r = pd.read_csv("/home/rax/Documents/GIT/Sems/All Sems/Data Analytics/CSV/Exp5.csv")
print(r)

# To check if null value is present , return bool
print(r.isnull())
# gives statistics of nul value in each coloumn
print(r.isnull().sum())
print("\n")


# Check this vlaues if present or not
missing_value = ["N/a", "na", np.nan]
# In this 
a = pd.read_csv("/home/rax/Documents/GIT/Sems/All Sems/Data Analytics/CSV/Exp5.csv", na_values = missing_value)
# 
print(a.isnull().sum())
print("\n")
print(a.isnull().any())
print("\n")

# Cretaes a heatmap
m = sns.heatmap(a.isnull(),yticklabels = False, annot = True)
print(m) #Not visible since I execute in terminal

