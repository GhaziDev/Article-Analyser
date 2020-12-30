import matplotlib.pyplot as plt 
import pandas as  pd 
data=pd.read_csv("C:/data/data.csv")
words=[i for i in data['Words']]
lengths=[i for i in data['Length']]
plt.barh(words,lengths)
plt.show()