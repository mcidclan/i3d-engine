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

for face in mesh.polygons:
    wrtf("<i", face.vertices[0])
    wrtf("<i", face.vertices[1])
    wrtf("<i", face.vertices[2])
    
    for i in range(len(face.vertices)):
        v = mesh.vertices[face.vertices[i]]
        wrtf("<f", v.normal[0])
        wrtf("<f", v.normal[1])
        wrtf("<f", v.normal[2])
    
for uv_layer in mesh.uv_layers:
    for x in range(len(uv_layer.data)):
        wrtf("<f", uv_layer.data[x].uv.x)
        wrtf("<f", uv_layer.data[x].uv.y)
        
for vert in mesh.vertices:
    wrtf("<f", vert.co.xyz.x)
    wrtf("<f", vert.co.xyz.y)
    wrtf("<f", vert.co.xyz.z)
        
file.close()