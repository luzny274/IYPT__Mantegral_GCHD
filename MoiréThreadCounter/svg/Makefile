name = compiled

pathCompiled = ${name}/
pathUbuntu = ${pathCompiled}Ubuntu/
pathWin32 = ${pathCompiled}Windows-32bit/
pathWin64 = ${pathCompiled}Windows-64bit/

main = Anim.cpp


all:
	g++ -o test ${main}

final:
	#Ubuntu
	$(info $(shell mkdir -p $(pathUbuntu)))
	g++ -O2 -o ${pathUbuntu}${name}.out ${main}
	#
	#
	#Windows-32bit
	$(info $(shell mkdir -p $(pathWin32)))
	i686-w64-mingw32-g++ -O2 -o ${pathWin32}${name}.exe ${main} 
	#
	#
	#Windows-64bit
	$(info $(shell mkdir -p $(pathWin64)))
	x86_64-w64-mingw32-g++ -O2 -o ${pathWin64}${name}.exe ${main}