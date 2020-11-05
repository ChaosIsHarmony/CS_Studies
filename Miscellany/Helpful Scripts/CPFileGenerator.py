# Used to rapidly generate CPP/Java files for programming puzzles
# Use: python3 CPFileGenerator.py > CodeForces/900/Example.cpp

from sys import argv

script, filename = argv

# Open template file
content = ""
if '.cpp' in filename:
	content = open('CPPtemplate.txt').read()
else:
	content = open('JavaTemplate.txt').read()

# Create new file w/ name passed as command line arg
new_file = open(filename, 'w')
new_file.write(content)
