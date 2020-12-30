# Article-Analyser

## What is Article-Analyser ?
- It is a project that calculate and provide some analysis based on an article or a text provided by the user, like each word length/size, shortest and longest word, and most common word, it is a helpful tool to look for articles/text mistakes or to analyze articles/texts words.

## What does this project mainly depend on ?
- It mainly depend on threading, especially when the user has a big article/text file, threading will make the execution faster to evaluate the file and give different analysis.

## Why is C++ choosen for this project ?
- two reasons : 1)Performance: C++ is faster than most languages, and it fit this project, especially when the user want to provide a very big article to analyze.
2) Threading: I used python a lot in my projects, but python isnt that good for threading or multiprocessing, yet C++ is effective choice for threading.

## Is Python used in this project ?
- Yes it is used for drawing bar chart for word lengths, using matplotlib library, the reason for using matplotlib library, is because it is easier for the user to read a chart rather than an output of text, on a side note, matplotlib provide a "save" functionality for the user to save it in their own system.

## So, how can we use this project ?
- 1) copy the article/text you want into txt file, then run ``main.cpp`` it will ask for a full path for this txt file, if the txt file is empty the program will quit, otherwise it will continue and evaluate words lengths, shortest and longest words, and common words, each on a different thread.

- 2) this will also create a folder in Users folder called "data" which will have a csv file of each word and their lengths

- 3)run ``articleanalyser.py`` to evaluate this csv file into chart using matplotlib.

## Conclusion
- This project is easy to understand for developers, and easy to use for both users and developers, any suggestion or criticism is welcomed.

### Thank you.
