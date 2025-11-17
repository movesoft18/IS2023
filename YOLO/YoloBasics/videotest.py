from ultralytics import YOLO
import cv2

detected_objects = []
model = YOLO("yolo11x.pt")

cap = cv2.VideoCapture("Video.mp4")

while True:
    ret, frame = cap.read()
    if not ret: break
    results = model(frame)
    detected_objects = []
    for result in results:
        xyxy = result.boxes.xyxy
        conf = result.boxes.conf
        names = [result.names[cls.item()] for cls in result.boxes.cls.int()]
        #print('Всего найдено', len(xyxy), 'объектов')
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
        image = result.plot()
        cv2.imshow('result', image)
    key = cv2.waitKey(1)
    if key == 27: 
        break
        #for e in detected_objects:
        #    print(f"name:{e['name']}, conf:{e['conf']},x1={e['x1']},y1={e['y1']},x1={e['x2']},y1={e['y2']}")
cv2.destroyAllWindows()
cap.release()