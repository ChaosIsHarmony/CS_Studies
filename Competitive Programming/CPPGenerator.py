# Used to rapidly generate CPP file for CodeForces puzzles
# Use: python3 CPPGenerator.py > CodeForces/900/Example.cpp

from sys import argv

script, filename = argv

content = open('CPPtemplate.txt')
new_file = open(filename, 'w')
new_file.write(content.read())

content.close()

