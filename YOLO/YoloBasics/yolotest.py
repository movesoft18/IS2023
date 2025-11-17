from ultralytics import YOLO

detected_objects = []
model = YOLO("yolo11n.pt")
results = model("1.jpg")
for result in results:
    xyxy = result.boxes.xyxy
    conf = result.boxes.conf
    names = [result.names[cls.item()] for cls in result.boxes.cls.int()]
    print('Всего найдено', len(xyxy), 'объектов')
    for i in range(0, len(xyxy)):
        item = {
            'x1': int(xyxy[i][0]),
            'y1': int(xyxy[i][0]),
            'x2': int(xyxy[i][0]),
            'y2': int(xyxy[i][0]),
            'conf': conf[i],
            'name': names[i],
        }
        detected_objects.append(item)
    result.show()
    for e in detected_objects:
        print(f"name:{e['name']}, conf:{e['conf']},x1={e['x1']},y1={e['y1']},x1={e['x2']},y1={e['y2']}")
