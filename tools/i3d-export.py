#Blender 2.65

import bpy
import os
import struct 

def wrtf(a, b):
    file.write(struct.pack(a, b))

main_path = "c:/tmp/"
outputfile = os.path.join(main_path, 'model.i3d')
file = open(outputfile, 'wb')
    
obj = bpy.context.active_object
mesh = obj.data

file.write(struct.pack("<i", len(mesh.polygons) * 3))

print("\nindices")

for face in mesh.polygons:
    i0 = face.vertices[0]
    i1 = face.vertices[1]
    i2 = face.vertices[2]
    wrtf("<i", i0)
    wrtf("<i", i1)
    wrtf("<i", i2)
    print(str(i0) + "," + str(i1) + "," + str(i2))
    
print("\nnormals")
    
for face in mesh.polygons:
    for i in range(len(face.vertices)):
        v = mesh.vertices[face.vertices[i]]
        vn0 = v.normal[0]
        vn1 = v.normal[1]
        vn2 = v.normal[2]
        wrtf("<f", vn0)
        wrtf("<f", vn1)
        wrtf("<f", vn2)
        print(str(vn0) + "," + str(vn1) + "," + str(vn2))

print("\nuvcoords")

for uv_layer in mesh.uv_layers:
    for x in range(len(uv_layer.data)):
        uvx = uv_layer.data[x].uv.x
        uvy = uv_layer.data[x].uv.y
        wrtf("<f", uvx)
        wrtf("<f", uvy)
        print(str(uvx) + "," + str(uvy))
   
print("\nvertices")
        
for vert in mesh.vertices:
    vx = vert.co.xyz.x
    vy = vert.co.xyz.y
    vz = vert.co.xyz.z
    wrtf("<f", vx)
    wrtf("<f", vy)
    wrtf("<f", vz)
    print(str(vx) + "," + str(vy) + "," + str(vz))
    
print("\n")
    
file.close()
