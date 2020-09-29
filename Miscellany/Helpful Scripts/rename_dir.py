import os

for filename in os.listdir():
	if "[" in filename: # One of the things you'd like to get rid of
		os.rename(filename, filename[filename.find("]")+2:]) # Cut it out