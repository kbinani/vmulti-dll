all: vmulti.dll

REPOSITORY_NAME = vmulti

vmulti.dll:
	if not exist .\$(REPOSITORY_NAME) hg clone https://code.google.com/p/vmulti/ & copy .\$(REPOSITORY_NAME)\dirs .\$(REPOSITORY_NAME)\dirs.original
	echo DIRS=hidmapper sys client dll> .\$(REPOSITORY_NAME)\dirs
	if exist .\$(REPOSITORY_NAME)\dll del /S /Q .\$(REPOSITORY_NAME)\dll & rmdir .\$(REPOSITORY_NAME)\dll
	mkdir .\$(REPOSITORY_NAME)\dll
	xcopy .\dll .\$(REPOSITORY_NAME)\dll
	cd .\$(REPOSITORY_NAME) & buildme.bat
