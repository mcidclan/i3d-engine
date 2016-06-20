#Blender 2.65


import bpy
import os
import struct


class IVec:
    id = 0
    x = 0.0
    y = 0.0 
    z = 0.0
    
class OpenglData:
    id = -1
    uv = IVec()
    v = IVec()
    
def wrtf(a, b):
    file.write(struct.pack(a, b))


vs = []
vis = []
uvs = []
uvs_unique_values = []


obj = bpy.context.active_object
mesh = obj.data

nv = len(mesh.polygons) * 3

print("\nvs")
for vert in mesh.vertices:
    v = IVec()
    v.x = vert.co.xyz.x
    v.y = vert.co.xyz.y
    v.z = vert.co.xyz.z
    vs.append(v)
    print(str(v.x) + " " + str(v.y) + " " + str(v.z))

print("\nuvs")    
for uv_layer in mesh.uv_layers:
    for x in range(len(uv_layer.data)):
        uv = IVec()
        uv.x = uv_layer.data[x].uv.x
        uv.y = uv_layer.data[x].uv.y
        uvs.append(uv)
        print(str(uv.x) + " " + str(uv.y))

next_id = 0

print("\nuv, uvunique")
for uv in uvs:
    
    id = -1
    current_uv_presence = False
    
    for uv_unique in uvs_unique_values:
        if (uv_unique.x == uv.x) and (uv_unique.y == uv.y):
            id = uv_unique.id
            current_uv_presence = True
            break
    
    if not current_uv_presence:
        uv.id = next_id
        uvs_unique_values.append(uv)
        next_id += 1
    else:
        uv.id = id

    
for face in mesh.polygons:
    vis.append(face.vertices[0])
    vis.append(face.vertices[1])
    vis.append(face.vertices[2])

print("\nid")
for vi in vis:
    print(vi)    

i = 0
next_id = 0

datas = {}
vs_final = []
ids_final = []
uvs_final = []

print("\nids_final")

while i < len(vis):    
    data = OpenglData()
    
    vid = vis[i]
    uvid = uvs[i].id
    
    data.v = vs[vid]
    data.uv = uvs_unique_values[uvid]
    
    print(":" + str(data.v.x) + "," + str(data.v.y) + "," + str(data.v.z) + " " + str(data.uv.x) + "," + str(data.uv.y))
    
    key = (uvid, vid)
    
    if key in datas:
        ids_final.append(datas[key].id)
    else:
        ids_final.append(next_id);
        data.id = next_id
        datas[key] = data
        vs_final.append(data.v)
        uvs_final.append(data.uv)        
        next_id += 1
        
    i += 1


main_path = "/media/data/tmp/"
outputfile = os.path.join(main_path, 'model.i3d')
file = open(outputfile, 'wb')

nv_unique = len(vs_final)

wrtf("<i", nv)
wrtf("<i", nv_unique)
print(str(nv) + " " + str(nv_unique))

print("nid = " + str(len(ids_final)))

for id in ids_final:
    wrtf("<i", id)
    print(id)

print("nvs = " + str(len(vs_final)))
    
for v in vs_final:
    wrtf("<f", v.x)
    wrtf("<f", v.y)
    wrtf("<f", v.z)
    print(str(v.x) + " " + str(v.y) + " " + str(v.z))

print("nuvs = " + str(len(uvs_final)))

for uv in uvs_final:
    wrtf("<f", uv.x)
    wrtf("<f", uv.y)
    print(str(uv.x) + " " + str(uv.y))

file.close()

