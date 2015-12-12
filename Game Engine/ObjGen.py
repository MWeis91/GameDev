import random

cube_fp = "../Objects/Cube/"				#cube parent file path
cube_obj = "cube2.obj"					#cube .obj file
cube_tex = "CheckerPatternPaper.dds"	#cube .dds texture file
sphere_fp = "../Object/Sphere/"			#sphere parent file path
sphere_obj = "sphere2.obj"				#sphere .obj file
sphere_tex = "blue.dds"					#sphere .dds texture file path
filler = "0.0,0.0,0.0"

limit = int(50)

print "Enter the number of objects to be generated: "
numObjects = raw_input()
numObjects = int(numObjects)

f = open("objlist.txt","w")

while numObjects > 0:
	x = random.uniform(-limit, limit)
	y = random.uniform(-limit, limit)
	z = random.uniform(-limit, limit)
	xyz = ("%.2f" % x) + ',' + ("%.2f" % y) + ',' + ("%.2f" % z)
	object = random.sample([cube_fp, sphere_fp], 1)
	object_string = object[0] + " " + xyz + " " + filler + " " + filler
	f.write(object_string + "\n")
	numObjects = numObjects - 1
f.close()